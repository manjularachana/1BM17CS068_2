int calibrationTime=30;
long unsigned int lowin;
long unsigned int pause=5000;
boolean locklow=true;
boolean takelowtime;
int pirpin=3;
int ledpin=11;
void setup() {
  Serial.begin(9600);
  pinMode(pirpin,INPUT);
  pinMode(ledpin,OUTPUT);
  digitalWrite(pirpin,LOW);
  Serial.print("calibrating sensor");
  for(int i=0;i<calibrationTime;i++){
    Serial.print(".");
    delay(1000);}
    
  Serial.println("done");
  Serial.println("SENSOR ACTIVE");
  delay(50);

}

void loop() {
  if(digitalRead(pirpin)==HIGH){
     digitalWrite(ledpin,HIGH);
     if(locklow){
     locklow=false;
     Serial.println("---");
     Serial.println("motion detected at ");
     Serial.println(millis()/1000);
     Serial.println("sec");
     delay(50);
     }
     takelowtime=true;
  }
  
  if(digitalRead(pirpin)==LOW){
     digitalWrite(ledpin,LOW);
     if(takelowtime){
     lowin=millis();
     takelowtime=false;}
     if(!locklow&& millis()-lowin>pause){
      locklow=true;
      Serial.print("motion ended at ");
      Serial.print((millis()-pause)/1000);
      Serial.println("sec");
      delay(50);
     }
    
     }
}
    
  
