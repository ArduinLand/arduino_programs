/**
 * Ce fichier par contre contient l'ensemble des fonctions
 * Blynk utilisées pour la réalisation du projet 
 */

// Digital clock display of the time
void clockDisplay()
{
  // You can call hour(), minute(), ... at any time
  // Please see Time library examples for details

  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  String currentDate = String(day()) + "/" + month() + "/" + year();

  // Send time to the App
  Blynk.virtualWrite(V1, currentTime);
  // Send date to the App
  Blynk.virtualWrite(V2, currentDate);
}
 
//Choosen mode : Il s'agit de la sélection du mode
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  //Serial.println("Slider value = " + String(pinValue));
    // Ici on s'assure d'avoir reçu de l'information au travers de cette condition
    if(pinValue == 0){
      Blynk.notify("MODE PROGRAMMABLE ACTIVÉ");
      remote_control = false;
      paramReceived = false;
      parametre_remote = -1;
      digitalWrite(APPAREIL, LOW);
      Blynk.virtualWrite(V5, 0);
      prog_mode = true; // alors l'utilisateur a choisi
      //Le mode programmable
    }else{
    Blynk.notify("MODE CONTROLE À DISTANCE ACTIVÉ");

      remote_control = true; // Sinon le mode de contrôle à 
      //distance
      paramReceived_progMode = false;
      parametre_progMode = -1;
      digitalWrite(APPAREIL,LOW);
      prog_mode = false;
    }
  // process received value
}

//TImer for start and stop time
BLYNK_WRITE(V4)
{
 
  Serial.print("Got a value: ");
  paramReceived_progMode = true;
  parametre_progMode = param.asInt();
  Serial.println(param.asStr());

}
//Remote control pin 
BLYNK_WRITE(V5)
{
  paramReceived = true;
   parametre_remote = param.asInt(); // assigning incoming value from pin V1 to a variable
   if(remote_control){
     if(parametre_remote == 0)
       Blynk.notify("EXTINCTION DE VOTRE APPAREIL");
     else
       Blynk.notify("ALLUMAGE DE VOTRE APPAREIL");
   }
    //Serial.println("value ="+String(parametre));// Ici on s'assure d'avoir reçu de l'information au travers de cette condition
}


//Time input : traitement du temps entré par l'utilisateur
BLYNK_WRITE(V6) {
  
  TimeInputParam t(param);
  paramReceived_progMode = true;
  if(t.hasStartTime()){
    startTimeHour = t.getStartHour();
    startTimeMinute = t.getStartMinute();
//    Serial.println("---------------- START TIME OPTIONS----------------");
//    Serial.println("StartHour : "+startTimeHour +"\n"
//                          + "StartMinute : "+ startTimeMinute+"\n"
//                          + "StartSeconds : "+String(t.getStartSecond())
//     );
//    Serial.println("----------------------------------------------------");
  }

  if(t.hasStopTime()){
    stopTimeHour = t.getStopHour();
    stopTimeMinute = t.getStopMinute();
    
//    Serial.println("\n\n---------------- STOP TIME OPTIONS----------------");
//    Serial.println("StartHour : "+stopTimeHour +"\n"
//                          + "StartMinute : "+stopTimeMinute+"\n"
//                          + "StartSeconds : "+String(t.getStopSecond())
//     );
//    Serial.println("----------------------------------------------------");
  }
//  String daySelected[7] ={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
//
//  for (int i = 1; i <= 7; i++) {
//    if (t.isWeekdaySelected(i)) {
//      Serial.println(daySelected[i-1] + " is selected");
//    }
//  }
//    
  /* on aura 3600 * heure + 60 * minutes
  long startTimeInSecs = param[0].asLong();
  long heureActuelleInSecs = hour() * 3600 + 60*minute();
  if(startTimeInSecs == heureActuelleInSecs){
    Blynk.notify("IT'S TIME TO PUT IT ON");
    putItOn = true;
  }
  else
    putItOn = false;
  Serial.println(startTimeInSecs);
  Serial.println();*/
}

void connectToOneSsid(){                    
  while(wifiMulti.run() != WL_CONNECTED){
    delay(1000);
    Serial.print('.');  
  }
  Serial.println("Connected to "+ WiFi.SSID());
  String tmp_ssid = WiFi.SSID(), tmp_pass = WiFi.psk();
  char ssid [tmp_ssid.length()];
  tmp_ssid.toCharArray(ssid,tmp_ssid.length());
  char pass [tmp_pass.length()];
  tmp_pass.toCharArray(ssid,tmp_pass.length());
 
  Blynk.begin(auth,ssid,pass);
  
//  digitalWrite(APPAREIL, HIGH); //Extinction de led builtin
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,0,3),9443);
    rtc.begin();
  timer.setInterval(10000L,clockDisplay);
}
