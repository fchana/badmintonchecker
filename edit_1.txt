void setup() {
  Serial.begin(9600);
  pinMode(D0, INPUT);
  pinMode(D1, OUTPUT);
}

void loop() {
  delay(1000)
  Serial.println(digitalRead(D0));
  if(digitalRead(D0) == LOW){
    digitalWrite(D1, LOW);
  }
  else{
    digitalWrite(D1, HIGH);
  }

}
