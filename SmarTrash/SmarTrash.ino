#include <Servo.h> 
#include "variables_function.h"

void setup() {

Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(VERT, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
  monservo.attach(11);  // utilise la broche 11  pour le contrôle du servomoteur 
  monservo.write(0); // positionne le servomoteur à 0° 
  //Fermeture de la poubelle (vérification)
  fermerPoubelle();
  poubelleFermee = true;
  poubelleOuverte = false;
  ouverturePoubelle = false;
    
}

void loop() {
  if(poubellePleine)
  {
    //Allume la led rouge si la poubelle est pleine
    //TODO déterminer le niveau d'ordure dans la poubelle
    allumerLed("rouge");
    }
  else{
      //Si la poubelle n'est pas pleine on allume la VERTE
      // J'ai utilisé ici un module RGB
      allumerLed("vert");

      //Activation du mode mesure 
      digitalWrite(TRIGGER_PIN, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIGGER_PIN, LOW);
  
      /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
      long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
     
      /* 3. Calcul la distance à partir du temps mesuré */
      float distance_mm = (measure / 2.0) * SOUND_SPEED;
  
      afficherDistance(distance_mm);
      delay(TEMPS_SEUIL); // Vérification de la présence de l'utilisateur
                  //POur s'assurer vraiment que la personne est
               //devant la poubelle pour jeter quelque chose
  
      // Si après les 5secondes la personne est toujours à la 
      // distance seuil de notre poubelle alors elle veut effec-
      // tivement jeter quelque chose
    if(distancEnCm>0 && distancEnCm<=DISTANCE_SEUIL){
          //Modifier cette partie car pour ouvrir la poubelle
          // Je procédais par rotation donc modifie cette partie
           ouverturePoubelle=true;// Marque le fait que la poubelle est entrain de s'ouvrir
           ouvrirPoubelle();
           poubelleOuverte=true;//On marque que la poubelle est ouverte
           ouverturePoubelle=false;//Que l'ouverture est terminée
           poubelleFermee = false;
           fermeturePoubelle = false;
     }else{ // si la personne n'a pas atteint le TEMPS_SEUIL
     
            // L'on vérifie si la poubelle est ouverte
            if(poubelleOuverte)
            {
              delay(TEMPS_SEUIL); //On attend TEMPS_SEUIL pour s'assurer
                                  //que la personne n'est plus là
              fermeturePoubelle=true;
              fermerPoubelle();
              poubelleFermee=true;
              poubelleOuverte=false;
              ouverturePoubelle = false;
              fermeturePoubelle=false;
              }
            }
            delay(200);
      }
      
}//Fin loop
