#include "variables.h"
#include "blynk_function.h"
void setup()
{
  pinMode(APPAREIL, OUTPUT);  
  wifiMulti.addAP("Amaris2", "@Amaris2019");
  wifiMulti.addAP("AMARIS", "Pa$$2018");
  wifiMulti.addAP("iPhone de Paul-Marie", "t4r1geixca92j");
  wifiMulti.addAP("HUAWEI Mate 9 Pro", "MyDearPal!2018");
  wifiMulti.addAP("B315-MTNWIFI-7180", "01AL1EQT2BD");
  // Debug console
  Serial.begin(9600);
//  s.begin(9600);
   connectToOneSsid();  
  
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  
}

void loop()
{
  if(digitalRead(RESET_BUTTON) == HIGH)
    ESP.restart(); // Reset
  Blynk.run();
  timer.run();
  if(WiFi.status() != WL_CONNECTED)//Si au cours de lexécution du programme le nodeMCU se déconnecte
    connectToOneSsid();//Alors on lui suggèrede se reconnecter


    
  if( !(remote_control & prog_mode)  ){
    //Au démarrage de l'application on s'assure que l'utilisateur choisisse un mode
    if(paramReceived || paramReceived_progMode){
      Blynk.notify("VEUILLEZ D'ABORD ACTIVER L'UN DES MODES SVP");
      parametre_remote =-1;
      parametre_progMode = -1;
      paramReceived = false;
      paramReceived_progMode = false;
      Blynk.virtualWrite(V5,0);
      
    }
    
  }
 //si l'utilisateur a choisi le mode programmable alors
  if(prog_mode){
  //Ici nous sommes dans le cas où pendant le mode prog l'utilisateur essaie d'avoir accès au bouton réservé au remote control
    if(paramReceived && parametre_remote != - 1){
        Blynk.virtualWrite(V5, 0); // Réinitialisation 
        parametre_remote = -1;
        paramReceived = false;
  
        //Serial.println("Veuillez désactiver le mode programmable et activer le mode de contrôle à distance pour pouvoir l'allumer et l'éteindre manuellement, MERCI.");
        Blynk.notify("Veuillez désactiver le mode programmable et activer le mode de contrôle à distance pour pouvoir l'allumer et l'éteindre manuellement, MERCI.");

        paramReceived = false;
  }
  

  
  //normalement faire une requête à Blynk pour avoir le time start and time stop for the blynk
  //pour la démo on sera obligé de rentrer à nouveau 
  currentHour = String(hour());
  currentMinutes = String(minute());
  if(startTimeHour == currentHour && startTimeMinute == currentMinutes){
    digitalWrite(APPAREIL, HIGH); //car led builtin a besoin de low pour s'allumer
    }

  if(stopTimeHour == currentHour && stopTimeMinute == currentMinutes){
  digitalWrite(APPAREIL, LOW);
  }
  
 }//Fin du mode programmable
 
 if(remote_control){ 
 
  if(paramReceived_progMode){
     Blynk.notify("Veuillez désactiver le mode contrôle à distance et activer le mode programmable s'il vous plaît ");
    parametre_progMode = -1;
    paramReceived_progMode = false;
  }
  
  if(paramReceived && parametre_remote != -1){
      digitalWrite(APPAREIL, parametre_remote);
      paramReceived = false;
      parametre_remote = -1;
    }
  
 }

 
 /*
  if(paramReceived){
    s.write(parametre);
    paramReceived = false;
    parametre = -1;
  }
  */
 
}
