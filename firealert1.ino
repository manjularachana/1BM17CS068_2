#include<SoftwareSerial.h>
int sensorpin=0;
int sensorvalue=0;
int led=9;
int buzzer=12;

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("WElcome to techpnder flame sensor tutorial");
sensorvalue=analogRead(sensorpin);
Serial.println(sensorvalue);
if(sensorvalue<100){
  Serial.println("fire detected");
  Serial.println("led on");
  digitalWrite(led,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(1000);
  }
  digitalWrite(led,LOW);
  digitalWrite(buzzer,LOW);
  delay(sensorvalue);
}
