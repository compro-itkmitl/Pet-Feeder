#include <Servo.h> 

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2); //ถ้าจอไม่แสดงผล ให้ลองเปลี่ยน 0x3F เป็น 0x27

int botton = 10;
Servo myservo;   

void setup() 

{ 
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("---DOG FEEDER---");
  lcd.setCursor(0, 1);
  lcd.print("Status:");
  
  
  pinMode(botton, INPUT_PULLUP);
  
  myservo.attach(9); 

} 

void loop() 
{       
  int value = digitalRead(botton);

  if(value == 0){
    myservo.write(0);
    lcd.setCursor(7, 1); // ไปที่ตัวอักษรที่ 0 บรรทัดที่ 1
    lcd.print(" CLOSE");
                   
  }else{
    myservo.write(90);
    lcd.setCursor(7, 1); // ไปที่ตัวอักษรที่ 0 บรรทัดที่ 1
    lcd.print(" OPEN");
    delay(4000);
  }
}
