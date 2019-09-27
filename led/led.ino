void setup() 
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
if(Serial.available())
{
  int z = Serial.read();

  if(z == 1)
  {
    digitalWrite(13,HIGH);
  }
if(z == 2)
{
  digitalWrite(13,LOW);
  }
  
}
}
