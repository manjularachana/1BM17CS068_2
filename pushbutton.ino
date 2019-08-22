void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int buttonread=0;
buttonread=digitalRead(2);

digitalWrite(12,buttonread);

}
