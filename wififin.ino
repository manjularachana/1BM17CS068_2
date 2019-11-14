#include<SoftwareSerial.h> 
SoftwareSerial Serial1(2,3); 
void setup() { 
Serial.begin(9600); 
Serial1.begin(9600); // Setup Wifi as STA and connect to AP 
Serial1.println ("AT+CWMODE=1"); 
Serial1.println("AT+CWJAP=\"Wifiiiii\",\"12356789\"");
if(Serial1.available()){
  while(Serial1.available()){
    Serial.write(Serial1.read());
    }
  }
Serial1.println ("AT+CIPMUX=0"); 
}

// the loop function runs over and over again forever 
void loop() { 
int rawvoltage= 1000; 
float millivolts= (rawvoltage/1024.0) * 5000; 
float temp= millivolts/10; //celcius
 Serial1.println ("AT+CIPSTART=\"TCP\",\"thingspeak.com\"\",80"); 
 char cmd[200],cipsend[100]; 
 sprintf (cmd, " GET /update?api_key=G4PV6YYX37MBDUPO&field1=%d HTTP/1.0\r\n\r\n Host: thingspeak.com.com\r\n\r\n",(int)temp);
 sprintf (cipsend, "AT+CIPSEND=%d",strlen(cmd));
 Serial1.println(cipsend);
 Serial.println("done");
  if(Serial1.available()>0) {
    String message=Serial1.readString();
    while(message!=">") String message=Serial1.readString();
    Serial1.println(cmd); 
  } 
  delay(10000);
}
