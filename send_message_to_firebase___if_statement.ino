#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseObject.h>

#define FIREBASE_HOST "new-project-ec552-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "QtmUBviLdWs0vxYLcJSJ7ULoCJSVyY8ODeUZwoP5"
#define WIFI_SSID "FOYER 7"
#define WIFI_PASSWORD "Espoir2021"

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.print("Connected to");
  Serial.println(WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalVal = 0;
  if(digitalVal == 0){
    String MSG= "Bonjour";
    Firebase.setString("/msg", MSG);
    Serial.println(digitalVal);
    delay(4000);
    
  }
  else{
    String MSG= "No Bonjour";
    Firebase.setString("/msg", MSG);
    Serial.println(digitalVal);
    delay(4000);
  }

}
