int led0=7;
int led1=8;
int led2=9;
int led3=10;
int led4=11;
int led5=12;
int led6=13;

void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() {
//0
  digitalWrite(7,LOW);//a
  digitalWrite(8,LOW);//b
  digitalWrite(9,LOW);//c
  digitalWrite(10,LOW);//d
  digitalWrite(11,LOW);//e
  digitalWrite(12,LOW);//f
  digitalWrite(13,HIGH);//g
  delay(1000);
//1
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  delay(1000);
//2
  digitalWrite(7,LOW);  //a
  digitalWrite(8,LOW);  //b
  digitalWrite(9,HIGH); //c
  digitalWrite(10,LOW);  //d
  digitalWrite(11,LOW);  //e
  digitalWrite(12,HIGH);  //f
  digitalWrite(13,LOW); //g
  delay(1000);
// 3
  digitalWrite(7,LOW);  //a
  digitalWrite(8,LOW);  //b
  digitalWrite(9,LOW); //c
  digitalWrite(10,LOW);  //d
  digitalWrite(11,HIGH);  //e
  digitalWrite(12,HIGH);  //f
  digitalWrite(13,LOW); //g
  delay(1000);
//4
  digitalWrite(7,HIGH);  //a
  digitalWrite(8,LOW);  //b
  digitalWrite(9,LOW); //c
  digitalWrite(10,HIGH);  //d
  digitalWrite(11,HIGH);  //e
  digitalWrite(12,LOW);  //f
  digitalWrite(13,LOW); //g
  delay(1000);
//5
  digitalWrite(7,LOW);  //a
  digitalWrite(8,HIGH);  //b
  digitalWrite(9,LOW); //c
  digitalWrite(10,LOW);  //d
  digitalWrite(11,HIGH);  //e
  digitalWrite(12,LOW);  //f
  digitalWrite(13,LOW); //g
  delay(1000);
//6
  digitalWrite(7,LOW);  //a
  digitalWrite(8,LOW);  //b
  digitalWrite(9,LOW); //c
  digitalWrite(10,LOW);  //d
  digitalWrite(11,LOW);  //e
  digitalWrite(12,HIGH);  //f
  digitalWrite(13,LOW); //g
  delay(1000);
//7
  digitalWrite(7,LOW);  //a
  digitalWrite(8,LOW);  //b
  digitalWrite(9,LOW); //c
  digitalWrite(10,HIGH);  //d
  digitalWrite(11,HIGH);  //e
  digitalWrite(12,HIGH);  //f
  digitalWrite(13,HIGH); //g
  delay(1000);
//8
  digitalWrite(7,LOW);  //a
  digitalWrite(8,LOW);  //b
  digitalWrite(9,LOW); //c
  digitalWrite(10,LOW);  //d
  digitalWrite(11,LOW);  //e
  digitalWrite(12,LOW);  //f
  digitalWrite(13,LOW); //g
  delay(1000);
//9
  digitalWrite(7,LOW);  //a
  digitalWrite(8,LOW);  //b
  digitalWrite(9,LOW); //c
  digitalWrite(10,LOW);  //d
  digitalWrite(11,HIGH);  //e
  digitalWrite(12,LOW);  //f
  digitalWrite(13,LOW); //g
  delay(1000);
}
