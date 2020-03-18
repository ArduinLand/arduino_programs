int humidity;
const int TEMP_SENSOR = A5, RED = 9, GREEN = 10, BLUE = 11;
boolean needWater ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN , OUTPUT);
  pinMode(BLUE, OUTPUT);
  /*Vérification de l'extinction des leds
  digitalWrite(LED_ROUGE, LOW);
  digitalWrite(LED_VERTE, LOW);*/
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = analogRead(TEMP_SENSOR);
  Serial.println("humidity = "+ String(humidity));
  // SI notre plante manque d'eau alors led rouge allumée sinon led verte allumée
  needWater = (humidity >= 600) ? true : false  ;
    if(needWater){
      /*digitalWrite(LED_VERTE, LOW);
      digitalWrite(LED_ROUGE, HIGH);*/
      analogWrite(RED, 255);
       analogWrite(GREEN, 0);
       analogWrite(BLUE, 0);
    }else{
      /*digitalWrite(LED_ROUGE, LOW);
      digitalWrite(LED_VERTE, HIGH);*/
      analogWrite(RED, 0);
      analogWrite(BLUE, 255);
       analogWrite(GREEN, 0);
    }
delay(500);
}
