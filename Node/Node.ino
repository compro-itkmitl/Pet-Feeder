#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <BlynkSimpleEsp8266.h>

char auth[] = "2ae4032458ec496e87333ff98fb0a775";
SoftwareSerial NodeSerial(D2, D3); // RX | TX
void setup() {
  Blynk.begin(auth, "AndroidAP", "55667744");
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(115200);
  NodeSerial.begin(4800);
}
void loop() {
  Blynk.run();
  delay(100);
}
//เชื่อนnode กัน uno แล้วทำให้มอเต้อหมุนผ่านมือถือ
