#include <TridentTD_LineNotify.h>
#include <FirebaseArduino.h>
#define SSID        "oweninwza"
#define PASSWORD    "0967906611"
#define LINE_TOKEN  "IsZu1w8h8rcNKiFIWBX3EpFhwrL2sd7P5XKzjz0bc1G"

void setup() {
  Serial.begin(9600);
  pinMode(D0, INPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, INPUT);
  pinMode(D5, OUTPUT);
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  
  LINE.setToken(LINE_TOKEN);
}

void loop() {
  delay(1000)
  Serial.println(digitalRead(D0));
  if(digitalRead(D0) == LOW){
    digitalWrite(D1, LOW);
    Line.notify('court 1 is empty')
  }
  else{
    digitalWrite(D1, HIGH);
    Line.notify('court 1 is full')
  }
  Serial.println(digitalRead(D0));
  if(digitalRead(D2) == LOW){
    digitalWrite(D3, LOW);
    Line.notify('court 2 is empty')
  }
  else{
    digitalWrite(D3, HIGH);
    Line.notify('court 2 is full')
  }
  Serial.println(digitalRead(D0));
  if(digitalRead(D4) == LOW){
    digitalWrite(D5, LOW);
    Line.notify('court 2 is empty')
  }
  else{
    digitalWrite(D5, HIGH);
    Line.notify('court 2 is full')
  }

}
