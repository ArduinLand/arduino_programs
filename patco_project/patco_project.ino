#include "sim808_variables_function.h"
const int CONDITIONER = 7;
const int BUZZER = 8;
const int CURRENT = 9; // pin used to detect the "coupure"
const int INTERVAL = 1000;
unsigned long previous_millis = 0;
int led_state = LOW; 



void setup() {
  // put your setup code here, to run once:
  pinMode(CONDITIONER , OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode( CURRENT, INPUT);
  Serial.begin(9600);
  mySerial_gsm.begin(9600);
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
      if( smsAvailable() == 0){ // If we don't have any free sms
        
        long balance = checkMyBalance(); // First we verify our balance in order to know 
                                        //if we can send sms applying charges
        //TODO if my balance can allow me to send 2 sms first
        //I send a sms telling the admin sys to recharge because it's the last one we're going to send

        //After recharging, We are going to buy a pack of free sms
        buyFreeSmsPack();
        
      }else //Otherwise we send the alert message
        sim808.sendSMS(phone, MESSAGE_ALERT);
      

    } //Otherwise we verify if we received a message from the admin to shut down the alarm
    
    didWeReceiveAdminSms(); // ??
  }

}
