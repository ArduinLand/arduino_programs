#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>
#define MESSAGE_LENGTH 160
#define PIN_TX_GSM 10 //10 (arduino uno)
#define PIN_RX_GSM 11 //11 (arduino uno)


const int CONDITIONER = 7;
const int BUZZER = 8;
const int CURRENT = 9; // pin used to detect the "coupure"
const int INTERVAL = 1000;
unsigned long previous_millis = 0;
int led_state = LOW; 

char message[MESSAGE_LENGTH];
int messageIndex = 0;
char MESSAGE[300];
String message_etat;
char phone[16];
char datetime[24];
SoftwareSerial mySerial_gsm(PIN_TX_GSM,PIN_RX_GSM);
DFRobot_SIM808 sim808(&mySerial_gsm);//Connect RX,TX,PWR


void setup() {
  // put your setup code here, to run once:
  pinMode(CONDITIONER , OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode( CURRENT, INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  while(!sim808.init())
  {
      Serial.print("Sim808 init error\r\n");
      delay(1000);
  }
  Serial.println("SIM Init success");
  sendATcommand("AT+CMGF=1",1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  long current_time = millis(); // Store the current time
  
  if(current_time - previous_millis >= INTERVAL){
    
    previous_millis = current_time;
    //We're going to check each second if we have the current
    if( !digitalRead(CURRENT)  ) { // if not then we have to send an alert to the system administrator
      digitalWrite(BUZZER, HIGH) ;
      if( smsAvailable() == 0){
        // We are going to buy a pack of free sms
        long balance = checkMyBalance(); // First we verify our balance
        
      }else
        sim808.sendSMS(phone, MESSAGE_ALERT);
      
      //TODO later try to include the GSM module to send a SMS

    } //Otherwise we do nothing
    
    messageIndex = sim808.isSMSunread();

   //*********** At least, there is one UNREAD SMS ***********
   if (messageIndex > 0)
   { //TODO modify the modeDetection function in order to stop the buzzer alarm
      //By sending a well formatted syntax

      sim808.readSMS(messageIndex, message, MESSAGE_LENGTH, phone, datetime);
             
      //***********In order not to full SIM Memory, is better to delete it**********
      sim808.deleteSMS(messageIndex);

      if(phone == PHONE_ADMIN){
        // if we received a message from the admin
      }
      modeDetectionAndAction();
   }

  }

}

long checkMyBalance(){
         String resultat_at_commande =   sendATcommand("AT+CUSD=1,\"#122#\"",6000);// Donc ici je précise la commande AT et le timeout

   int debut_compte_principal = resultat_at_commande.indexOf("o") -1, fin_compte_principal = resultat_at_commande.indexOf("v") -1;
      String compte_principal = resultat_at_commande.substring(debut_compte_principal,fin_compte_principal);
      int debut_solde = compte_principal.indexOf("=") + 1;
      String solde = compte_principal.substring(debut_solde);
      solde.trim(); 
//      Serial.println("Solde : "+solde); 
      long solde_long = solde.substring(0,solde.length()).toInt();
      //Serial.println("solde_long = "+ String(solde_long));
  return solde_long;
}

long smsAvailable(){
      String resultat_at_commande =   sendATcommand("AT+CUSD=1,\"#122*3#\" ",500);// Donc ici je précise la commande AT et le timeout
      resultat_at_commande = resultat_at_commande.substring(36,37);

      return resultat_at_commande.toInt();
}

//TODO 
void buyFreeSmsPack(){
  
}

void modeDetectionAndAction(){
  //----------------------------------------------------- DÉTECTION DU MODE ET L'ACTION À EXÉCUTER --------------------------------------------------------------------------------------
      char* result[4];
      String mode; int index = 0;
      char *res;
      res = strtok(message,"/");
      mode = String(res); mode.toLowerCase();
      mode.trim();
      //result[0] = String(res);
      Serial.println("result[0] = "+ mode);
      //Serial.println("index = "+ String(index));
      index += 1;
      while(res != NULL){
        
        result[index] = res;
//        message = res;
        //index++;
         res = strtok(NULL,"/");
         //result[index] = String(res);

      }
      
}
