const int LED = 8;
const int INTERVAL = 1000;
unsigned long temps_fin = 0;
int etat_led = LOW; // De base la led est éteinte

void setup() {
  // put your setup code here, to run once:
  pinMode(LED , OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long temps_actuel = millis(); //Récupération du temps actuel
  Serial.println("temps_debut = " + String(temps_actuel));
  if(temps_actuel - temps_fin >= INTERVAL){
    //Actualise la valeur de temps_fin vu qu'elle va changer
    temps_fin = temps_actuel;
    Serial.println("temps_fin = " + String(temps_fin));

      (!etat_led) ? etat_led = HIGH : etat_led = LOW;

    digitalWrite( LED, etat_led);
  }

}
