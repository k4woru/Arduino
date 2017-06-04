int led0=0;
int led1=1;
int led2=2;
int led3=3;
int led4=4;
int led5=5;
int led6=6;

void setup() {
 pinMode(0,OUTPUT);
 pinMode(1,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 
}

void loop() {
  digitalWrite(0,HIGH);
  delay(40);
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  delay(40);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  delay(40);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  delay(40);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(40);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(40);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(40);
  digitalWrite(6,LOW);
}
