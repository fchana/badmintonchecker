#include <FirebaseArduino.h>
#define SSID        "oweninwza"
#define PASSWORD    "0967906611"
#define FIREBASE_HOST "fir-batminton.firebaseio.com"
#define FIREBASE_AUTH "PclJoL7BEop8SDgTAbxg01vFdiqsUocdfbrqyh58"
int court1 = 0;
int court2 = 0;
int court3 = 0;

void setup() {
  Serial.begin(115200); Serial.println();
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  Firebase.setInt("court1", court1);
  Firebase.setInt("court2", court2);
  Firebase.setInt("court3", court3);
  delay(3000);
  court1 = 1;
  court2 = 1;
  court3 = 1;
  delay(3000);
  court1 = 0;
  court2 = 0;
  court3 = 0;
}
