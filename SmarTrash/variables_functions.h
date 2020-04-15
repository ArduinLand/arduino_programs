const int RED =8, VERT = 9, BLUE = 10;
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s
const float SOUND_SPEED = 340.0 / 1000;
const int TEMPS_SEUIL = 250; // 250 msecondes 
const int DISTANCE_SEUIL = 5;
long tempsChronometre;
boolean chronometrage = false,ouverturePoubelle,poubelleOuverte;
boolean fermeturePoubelle,poubelleFermee,poubellePleine=false;
Servo monservo;  // crée l’objet pour contrôler le servomoteur


void afficherDistance(float distance_mm){
  //
  float distancEnCm=distance_mm / 10.0, 2;
  Serial.print("Distance: ");
  Serial.print(distancEnCm);
  Serial.print("cm, ");
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println("m");
}

void ouvrirPoubelle(){
}

void fermerPoubelle(){
  
}

void allumer(String couleur){
  if(couleur.toLowerCase() == "rouge"){
    analogWrite(RED, 0);
    analogWrite(VERT, 255);
    analogWrite(BLUE, 255);
  }else if(couleur.toLowerCase() == "verte" || couleur.toLowerCase() == "vert"){
    analogWrite(RED, 255);
    analogWrite(VERT, 0);
    analogWrite(BLUE, 255);
  }
}
