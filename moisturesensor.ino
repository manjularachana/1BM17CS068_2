#include<Servo.h>
Servo myservo;
int pos=0;
int sensorpin=0;
int sensorvalue=0;
void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorvalue=analogRead(sensorpin);
  Serial.println(sensorvalue);
  if(sensorvalue>500){
    for(pos=0;pos<=180;pos++){
      myservo.write(pos);
      delay(15);
    }
    for(pos=180;pos>=0;pos--){
      myservo.write(pos);
      delay(15);
    }
  }
    delay(1000);
}
