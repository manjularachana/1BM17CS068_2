#include<SoftwareSerial.h>
SoftwareSerial myserial(9,10);
#define led 12
char tag[]="53002913C4AD";
char input[12];
int count=0;
boolean flag=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myserial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(myserial.available()){
  count=0;
  while(myserial.available()&& count<12){
    input[count]=myserial.read();
    Serial.write(input[count]);
    count++;
    delay(5);
    }
    if(count==12){
      count=0;
      flag=1;
      while(count<12&&flag!=0){
        if(input[count]==tag[count]){
          flag=1;
          }
          else{
            flag=0;
            }
            count++;
        }
      }
      if(flag==1){
        Serial.println("accesss allowed");
        digitalWrite(led,HIGH);
        delay(2000);
        digitalWrite(led,LOW);
        }
        else{
          Serial.print("access denied");
          digitalWrite(led,LOW);
          delay(2000);
          }
          for(count=0;count<12;count++){
            input[count]='F';
            }
            count=0;
  }
}
