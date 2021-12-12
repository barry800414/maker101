void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7, HIGH);
  Serial.print("On\n");
  delay(2000);
  digitalWrite(7, LOW);
  Serial.print("Off\n");
  delay(2000);
  
}
