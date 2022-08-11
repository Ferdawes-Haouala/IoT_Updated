int greenPin = 4; //D2

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "new-project-ec552-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "QtmUBviLdWs0vxYLcJSJ7ULoCJSVyY8ODeUZwoP5"
#define WIFI_SSID "FOYER 7"
#define WIFI_PASSWORD "Espoir2021"

void setup() {
  pinMode(greenPin, OUTPUT);
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
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String msg= Firebase.getString("/msg/");
  Serial.print("Message:");
  Serial.println(msg);
  if (msg == "true"){
    digitalWrite ( greenPin, HIGH); // turn the green led on
    delay(2000);
    Serial.println("light On");
  }
  else{
    digitalWrite ( greenPin, LOW);
    delay(2000);
    Serial.println("Light off");
  }
}
