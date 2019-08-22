int byterecieved;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Type in the box above");
Serial.println();
pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  byterecieved=Serial.read();
  if(byterecieved=='1'){
  digitalWrite(12,HIGH);
  Serial.print("led high");
  }
  if(byterecieved=='0'){
    digitalWrite(12,LOW);
    Serial.print("led off");
    }
  
  }
}
