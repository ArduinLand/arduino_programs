#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>
#define MESSAGE_LENGTH 160
#define PIN_TX_GSM 10 //10 (arduino uno)
#define PIN_RX_GSM 11 //11 (arduino uno)

//------------- PROTOTYPES----------------
  void modeDetectionAndAction();
  long checkMyBalance();
  long smsAvailable();
  void buyFreeSmsPack();
  String sendATcommand(const char *toSend, unsigned long milliseconds);
//------------------------------------------

char message[MESSAGE_LENGTH];
int messageIndex = 0;
String message_etat;
char phone[16];
char datetime[24];
SoftwareSerial mySerial_gsm(PIN_TX_GSM,PIN_RX_GSM);
DFRobot_SIM808 sim808(&mySerial_gsm);//Connect RX,TX,PWR
const char MESSAGE_ALERT[MESSAGE_LENGTH];
const char PHONE_ADMIN[] = "";

void didWeReceiveAdminSms(){
	messageIndex = sim808.isSMSunread();

   //*********** At least, there is one UNREAD SMS ***********
   if (messageIndex > 0){ 
      //TODO modify the modeDetection function in order to stop the buzzer alarm
      //By sending a well formatted syntax

      sim808.readSMS(messageIndex, message, MESSAGE_LENGTH, phone, datetime);
             
      //***********In order not to full SIM Memory, is better to delete it**********
      sim808.deleteSMS(messageIndex);

      if(phone == PHONE_ADMIN){
        // if we received a message from the admin
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
   //Serial.println("Solde : "+solde); 
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

	//After we bought the pack we have to tell the admin that's everything's okay now
  
}

void modeDetectionAndAction(){
  //----------------------------------------------------- DETECTING THE INSTRUCTION TO EXECUTE--------------------------------------------------------------------------------------
  // Admin can stop the alarm and turn on or off the AC by sending a SMS
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
		//message = res;
	    //index++;
	    res = strtok(NULL,"/");
	    //result[index] = String(res);

    }
      
}

String sendATcommand(const char *toSend, unsigned long milliseconds) {
  String result;
 // Serial.print("Sending: ");
  //Serial.println(toSend);
  mySerial_gsm.println(toSend);
  unsigned long startTime = millis();
  //Serial.print("Received: ");
  while (millis() - startTime < milliseconds) {
    if (mySerial_gsm.available()) {
      char c = mySerial_gsm.read();
      //Serial.write(c);
      result += c;  // append to the result string
    }
  }
//Serial.println();  // new line after timeout.
return result;
}
