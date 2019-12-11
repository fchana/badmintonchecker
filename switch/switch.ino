#include <TridentTD_LineNotify.h>
#include <FirebaseArduino.h>
#define SSID        "oweninwza"
#define PASSWORD    "0967906611"
#define LINE_TOKEN  "IsZu1w8h8rcNKiFIWBX3EpFhwrL2sd7P5XKzjz0bc1G"
int court1 = 0;
int court2 = 0;
int court3 = 0;
int st = 0;
int sted = 3;

void setup() {
  Serial.begin(9600);
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
}

void loop() {
  if(digitalRead(D0) == 0){
    if(digitalRead(D5) == 0){
      court1 = 0;
      st += 1;
      digitalWrite(D5, HIGH);
      Serial.println(digitalRead(D0));
    }
  }
  else{
    if(digitalRead(D5) == 1){
      court1 = 1;
      st += 1;
      digitalWrite(D5, LOW);
      Serial.println(digitalRead(D0));
    }
  }
  if(digitalRead(D1) == 0){
    if(digitalRead(D6) == 0){
      court2 = 0;
      st += 1;
      digitalWrite(D6, HIGH);
      Serial.println(digitalRead(D1));
    }
  }
  else{
    if(digitalRead(D6) == 1){
      court2 = 1;
      st += 1;
      digitalWrite(D6, LOW);
      Serial.println(digitalRead(D1));
    }
  }
  if(digitalRead(D2) == 0){
    if(digitalRead(D7) == 0){
      court3 = 0;
      st += 1;
      digitalWrite(D7, HIGH);
      Serial.println(digitalRead(D2));
    }
  }
  else{
    if(digitalRead(D7) == 1){
      court3 = 1;
      st += 1;
      digitalWrite(D7, LOW);
      Serial.println(digitalRead(D2));
    }
  }

  if(st - sted == 1){
    if(court1 == 0){
      if(court2 == 0){
        if(court3 == 0){
          LINE.notify("All court are empty.");
        }
        else{
          LINE.notify("Court1 and court2 are empty, court3 is full.");
        } 
      }
      else{
        if(court3 == 0){
          LINE.notify("Court1 and court3 are empty, court2 is full.");
        }
        else{
          LINE.notify("Court1 is empty, court3 and court2 are full.");
        }
      }
    }
    else{
      if(court2 == 0){
        if(court3 == 0){
          LINE.notify("Court2 and court3 are empty, court1 is full.");
        }
        else{
          LINE.notify("Court2 is empty, court1 and court3 are full.");
        }
      }
      else{
        if(court3 == 0){
          LINE.notify("Court3 is empty, court1 and court2 are full.");
        }
        else{
          LINE.notify("All court are full.");
        }
      }
    }
    sted += 1;
  }
}
