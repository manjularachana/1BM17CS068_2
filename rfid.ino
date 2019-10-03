#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int count=0;
char input[12];
boolean flag=0;
void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  }


void loop() {
  // put your main code here, to run repeatedly:
if(mySerial.available()){
  count=0;
  while(mySerial.available() && count<12){
    input[count]=mySerial.read();
    count++;
    delay(5);
    }
    Serial.print(input);
  }
}
