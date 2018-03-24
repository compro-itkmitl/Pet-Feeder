#include <SoftwareSerial.h>


int botton = 8;
SoftwareSerial ArduinoSerial(3, 2); // RX, TX

void setup() {
  pinMode(8, INPUT);
  
  Serial.begin(115200);
  ArduinoSerial.begin(4800);
}
void loop() {
  while (ArduinoSerial.available() > 0) {
    int value = digitalRead(botton);
    Serial.println(value);
    float val = ArduinoSerial.parseFloat();
    if (ArduinoSerial.read() == '\n') {
      Serial.println(val);
      }
      }
      delay(100);
}

