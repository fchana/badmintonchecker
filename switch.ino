#include <TridentTD_LineNotify.h>
#define SSID        "SSID"
#define PASSWORD    "PASSWORD"
#define LINE_TOKEN  "LINE_TOKEN"
int court1 = 0;
int court2 = 0;
int court3 = 0;
int st = 0;
int sted = 3;
void setup() {
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  
  LINE.setToken(LINE_TOKEN);
  LINE.notify("Sever has online");
}

void loop() {
  if(digitalRead(D0) == 0){
    if(digitalRead(D5) == 0){
      court1 = 0;
      st += 1;
      digitalWrite(D5, HIGH);
      Serial.print(court1);
      Serial.print(court2);
      Serial.println(court3);
      Serial.print("Court1 = ");
      Serial.println(digitalRead(D0));
    }
  }
  else{
    if(digitalRead(D5) == 1){
      court1 = 1;
      st += 1;
      digitalWrite(D5, LOW);
      Serial.print(court1);
      Serial.print(court2);
      Serial.println(court3);
      Serial.print("Court1 = ");
      Serial.println(digitalRead(D0));
    }
  }
  if(digitalRead(D1) == 0){
    if(digitalRead(D6) == 0){
      court2 = 0;
      st += 1;
      digitalWrite(D6, HIGH);
      Serial.print(court1);
      Serial.print(court2);
      Serial.println(court3);
      Serial.print("Court2 = ");
      Serial.println(digitalRead(D1));
    }
  }
  else{
    if(digitalRead(D6) == 1){
      court2 = 1;
      st += 1;
      digitalWrite(D6, LOW);
      Serial.print(court1);
      Serial.print(court2);
      Serial.println(court3);
      Serial.print("Court2 = ");
      Serial.println(digitalRead(D1));
    }
  }
  if(digitalRead(D2) == 0){
    if(digitalRead(D7) == 0){
      court3 = 0;
      st += 1;
      digitalWrite(D7, HIGH);
      Serial.print(court1);
      Serial.print(court2);
      Serial.println(court3);
      Serial.print("Court3 = ");
      Serial.println(digitalRead(D2));
    }
  }
  else{
    if(digitalRead(D7) == 1){
      court3 = 1;
      st += 1;
      digitalWrite(D7, LOW);
      Serial.print(court1);
      Serial.print(court2);
      Serial.println(court3);
      Serial.print("Court3 = ");
      Serial.println(digitalRead(D2));
    }
  }
}
