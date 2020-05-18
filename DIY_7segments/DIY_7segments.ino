const int Seg_A = 6 ;
const int Seg_B = 3 ;
const int Seg_C = 8 ;
const int Seg_D = 9 ;
const int Seg_E = 10;
const int Seg_F = 2 ;
const int Seg_G = 11 ;
const int decimal2 = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  configuration_des_segments();
}
void configuration_des_segments() 
// Definir_les_broches
{
  pinMode(Seg_G,OUTPUT);
  pinMode(Seg_F,OUTPUT);
  pinMode(Seg_A,OUTPUT);
  pinMode(Seg_B,OUTPUT);
  pinMode(Seg_C,OUTPUT);
  pinMode(Seg_D,OUTPUT);
  pinMode(Seg_E,OUTPUT);
  pinMode(decimal2, OUTPUT);
}

void allumer_tout() 
// Allumer tous les segments
{
  digitalWrite(Seg_A,LOW);
  digitalWrite(Seg_B,LOW);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,LOW);
  digitalWrite(Seg_E,LOW);
  digitalWrite(Seg_F,LOW);
  digitalWrite(Seg_G,LOW);
}

void eteindre_tout() 
// Allumer tous lessegments
{
  digitalWrite(Seg_A,HIGH);
  digitalWrite(Seg_B,HIGH);
  digitalWrite(Seg_C,HIGH);
  digitalWrite(Seg_D,HIGH);
  digitalWrite(Seg_E,HIGH);
  digitalWrite(Seg_F,HIGH);
  digitalWrite(Seg_G, HIGH);
  digitalWrite(decimal2, HIGH);
}

void afficher_zero()
{ // affichage 0
  digitalWrite(Seg_A,LOW);
  digitalWrite(Seg_B,LOW);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,LOW);
  digitalWrite(Seg_E,LOW);
  digitalWrite(Seg_F,LOW);
  digitalWrite(Seg_G,HIGH);
}

void afficher_one()
{ // affichage 1
  digitalWrite(Seg_A,HIGH);
  digitalWrite(Seg_B,LOW);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,HIGH);
  digitalWrite(Seg_E,HIGH);
  digitalWrite(Seg_F,HIGH);
  digitalWrite(Seg_G,HIGH);
  digitalWrite(decimal2, LOW);

}

void afficher_two()
{ // affichage 2
  digitalWrite(Seg_A,LOW);
  digitalWrite(Seg_B,LOW);
  digitalWrite(Seg_C,HIGH);
  digitalWrite(Seg_D,LOW);
  digitalWrite(Seg_E,LOW);
  digitalWrite(Seg_F,HIGH);
  digitalWrite(Seg_G,LOW);
  digitalWrite(decimal2, HIGH);


}

void afficher_tree()
{ // affichage 3
  digitalWrite(Seg_A,LOW);
  digitalWrite(Seg_B,LOW);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,LOW);
  digitalWrite(Seg_E,HIGH);
  digitalWrite(Seg_F,HIGH);
  digitalWrite(Seg_G,LOW);
  digitalWrite(decimal2, HIGH);

}

void afficher_four()
{
//affichage 4
  digitalWrite(Seg_A,HIGH);
  digitalWrite(Seg_B,LOW);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,HIGH);
  digitalWrite(Seg_E,HIGH);
  digitalWrite(Seg_F,LOW);
  digitalWrite(Seg_G,LOW);
  digitalWrite(decimal2, HIGH);

}

 void afficher_five()
{
//affichage 5
  digitalWrite(Seg_A,LOW);
  digitalWrite(Seg_B,HIGH);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,LOW);
  digitalWrite(Seg_E,HIGH);
  digitalWrite(Seg_F,LOW);
  digitalWrite(Seg_G,LOW);
  digitalWrite(decimal2, HIGH);

}

void afficher_six(){
  //affichage 6
  digitalWrite(Seg_A,LOW);
  digitalWrite(Seg_B,HIGH);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,LOW);
  digitalWrite(Seg_E,LOW);
  digitalWrite(Seg_F,LOW);
  digitalWrite(Seg_G,LOW);
  digitalWrite(decimal2, HIGH);

}

void afficher_seven()
{
//affichage 7
  digitalWrite(Seg_A,LOW);
  digitalWrite(Seg_B,LOW);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,HIGH);
  digitalWrite(Seg_E,HIGH);
  digitalWrite(Seg_F,HIGH);
  digitalWrite(Seg_G,HIGH);
  digitalWrite(decimal2, HIGH);

}

void afficher_eight()
{
//affichage 8
  digitalWrite(Seg_A,LOW);
  digitalWrite(Seg_B,LOW);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,LOW);
  digitalWrite(Seg_E,LOW);
  digitalWrite(Seg_F,LOW);
  digitalWrite(Seg_G,LOW);
  digitalWrite(decimal2, HIGH);

}

void afficher_nine(){
    //affichage 9
  digitalWrite(Seg_A,LOW);
  digitalWrite(Seg_B,LOW);
  digitalWrite(Seg_C,LOW);
  digitalWrite(Seg_D,LOW);
  digitalWrite(Seg_E,HIGH);
  digitalWrite(Seg_F,LOW);
  digitalWrite(Seg_G,LOW);
  digitalWrite(decimal2, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  afficher_zero();
  delay(1000);
  afficher_one();
  delay(1000);
  afficher_two();
  delay(1000);
  afficher_tree();
  delay(1000);
  afficher_four();
  delay(1000);
  afficher_five();
  delay(1000);
  afficher_six();
  delay(1000);
  afficher_seven();
  delay(1000);
  afficher_eight();
  delay(1000);
  afficher_nine();
  delay(1000);
  allumer_tout();
  delay(1000);
  eteindre_tout();
  delay(1000);
  
}
