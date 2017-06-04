int rojo=2;
int amarillo=3;
int verde=4;
int azul=5;


void setup() {
  pinMode (2,OUTPUT);
  pinMode (3,OUTPUT);
  pinMode (4,OUTPUT);
  pinMode (5,OUTPUT);
  }

void loop() {
  digitalWrite(2,HIGH);
  delay(10000);
  digitalWrite(2,LOW);
  
  digitalWrite(3,HIGH);
  delay(1000);
  digitalWrite(3,LOW);

  digitalWrite(4,HIGH);
  delay(12000);
  digitalWrite(4,LOW);

  for (azul=0;azul<10;azul++)
  {
     digitalWrite(5,HIGH);
     delay(1000);
     digitalWrite(5,LOW);
     delay(1000);
     }
}
