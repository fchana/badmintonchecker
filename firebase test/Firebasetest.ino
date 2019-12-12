#include <TridentTD_LineNotify.h>
#include <FirebaseArduino.h>
#define SSID        "oweninwza"
#define PASSWORD    "0967906611"
#define FIREBASE_HOST "fir-batminton.firebaseio.com"
#define FIREBASE_AUTH "PclJoL7BEop8SDgTAbxg01vFdiqsUocdfbrqyh58"
#define LINE_TOKEN  "IsZu1w8h8rcNKiFIWBX3EpFhwrL2sd7P5XKzjz0bc1G"
int court1 = 0;
int court2 = 0;
int court3 = 0;

void setup() {
  Firebase.setInt("court1", court1);
  Firebase.setInt("court2", court2);
  Firebase.setInt("court3", court3);
  pinMode(D0, INPUT);
  pinMode(D1, OUTPUT);  
  Serial.begin(115200); Serial.println();
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  LINE.setToken(LINE_TOKEN);
  LINE.notify("Sever has online");
}

void loop() {
  if(digitalRead(D0) == 0){
    if(digitalRead(D5) == 0){
      court1 = 0;
      digitalWrite(D5, HIGH);
    }
  else{
    if(digitalRead(D5) == 1){
      court1 = 1;
      digitalWrite(D5, LOW);
    }
  }
  }
}
