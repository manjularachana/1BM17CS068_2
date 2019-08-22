int in = 0;
int led = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(in,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensedValue = analogRead(in);
  int convertedValue = map(sensedValue, 0, 1023, 0, 255);
  analogWrite(led, convertedValue);
  delay(1000);
  Serial.println(sensedValue);
  Serial.println(convertedValue);
}
