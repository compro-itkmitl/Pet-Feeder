#include <SoftwareSerial.h>
#include <Servo.h> 

Servo myservo;   

int botton = 8;
SoftwareSerial ArduinoSerial(3, 2); // RX, TX

void setup() {
  pinMode(8, INPUT);
  myservo.attach(9); 
  Serial.begin(115200);
  ArduinoSerial.begin(4800);
}
void loop() {
  while (ArduinoSerial.available() > 0) {
    int value = digitalRead(botton);
    Serial.println(value);
    float val = ArduinoSerial.parseFloat();
    if(value == 1){
    myservo.write(90); 
                        
    }else{
    myservo.write(0); 
    }
  }
}
//เชื่อม NODE กับ Arduino และ ทำให้ มอเตอร์หมุน

