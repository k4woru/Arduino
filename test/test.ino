int led=1;

void setup() {
pinMode (1,OUTPUT);
pinMode (2,OUTPUT);

}

void loop() {
  for(led=0;led<10;led++)
  {
  digitalWrite (1,HIGH);
  delay (900);
  digitalWrite (1,LOW);
  delay(900);

  digitalWrite (2,HIGH);
  delay (900);
  digitalWrite (2,LOW);
  delay(900);

 
  }

}
