#include <Servo.h> 

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2); //ถ้าจอไม่แสดงผล ให้ลองเปลี่ยน 0x3F เป็น 0x27

int start = 0;//uno start

int botton = 10;
int value = 0;
Servo myservo;

//tone
int tonePin = 12;

//on-off music
int on = 0, var = 1;

//เทfood
int tf = 5;
int tf_value = 1;

//button food size
int fs = 6;
int fs_value = 1;
int foodsize = 0;
int decryp[3] = {1, 2, 3}, i=0;
int time_delay = 4000;

void setup() 

{ 
  pinMode(12, OUTPUT);//buzzer

  pinMode(3, INPUT_PULLUP);//on-off music

  pinMode(11, INPUT_PULLUP);//node finsh setup
  
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("---DOG FEEDER---");
  lcd.setCursor(0, 1);
  lcd.print("Status:");
  Serial.begin(9600);
  
  pinMode(botton, INPUT_PULLUP);//รับค่ามาจากสายที่เชื่อมกับnode

  //LED music
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

  //เทfood
  pinMode(tf, INPUT_PULLUP);

  //botton food size
  pinMode(fs, INPUT_PULLUP);//  รับค่าจากปุ่ม
  
  myservo.attach(9);

}

void loop() 
{
  if(start == 0){
    lcd.setCursor(7, 1);
    lcd.print("     5");
    delay(1000);
    lcd.setCursor(7, 1);
    lcd.print("    4 ");
    delay(1000);
    lcd.setCursor(7, 1);
    lcd.print("   3  ");
    delay(1000);
    lcd.setCursor(7, 1);
    lcd.print("  2   ");
    delay(1000);
    lcd.setCursor(7, 1);
    lcd.print(" 1    ");
    delay(1000);
    lcd.setCursor(7, 1);
    lcd.print(" START");
    delay(1000);
    start++;
  }
  if(digitalRead(3)==1){
    on++;
    if(on%2 == 0){
      Serial.println(on);
      var = 1;
      lcd.setCursor(7, 1);
      lcd.print(" UNMUTE");
      delay(1000);
    }
    else{
      var = 0;
      lcd.setCursor(7, 1);
      lcd.print(" MUTE  ");
      delay(1000);
    }
  }
  
  value = digitalRead(botton);
  tf_value = digitalRead(tf);//เทfood
  if(tf_value == 0){
    value = 1;
  }
  fs_value = digitalRead(fs);//food size
  if(fs_value == 0){
    foodsize = decryp[i%3];
    i++;
    lcd.setCursor(7, 1); // ไปที่ตัวอักษรที่ 0 บรรทัดที่ 1
    if(foodsize == 1){
      lcd.print(" SIZE 1");
      time_delay = 3000;
      delay(1000);
    }
    else if(foodsize == 2){
      lcd.print(" SIZE 2");
      time_delay = 6000;
      delay(1000);
    }
    else if(foodsize == 3){
      lcd.print(" SIZE 3");
      time_delay = 9000;
      delay(1000);
    }
  }

  if(value == 0){
    myservo.write(0);
    lcd.setCursor(7, 1); // ไปที่ตัวอักษรที่ 0 บรรทัดที่ 1
    lcd.print(" CLOSE ");
   }
   else if(value == 1){
    myservo.write(90);
    lcd.setCursor(7, 1); // ไปที่ตัวอักษรที่ 0 บรรทัดที่ 1
    lcd.print(" OPEN ");
    delay(time_delay);
    myservo.write(0);
    lcd.setCursor(7, 1); // ไปที่ตัวอักษรที่ 0 บรรทัดที่ 1
    lcd.print(" CLOSE ");
    if(var == 1) Despacito();
  }
}

//led music
void red_on(){
  digitalWrite(8, HIGH); 
}
void red_off(){
  digitalWrite(8, LOW);
}
void blue_on(){
  digitalWrite(7, HIGH);
}
void blue_off(){
  digitalWrite(7, LOW);
}


void Despacito() {
    tone(tonePin, 587, 709.720327982);
    red_on();
    delay(788.578142202);
    delay(10.3082110092);
    red_off();
    tone(tonePin, 554, 709.720327982);
    blue_on();
    delay(788.578142202);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 493, 273.683002294);
    red_on();
    delay(304.092224771);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 369, 273.683002294);
    blue_on();
    delay(304.092224771);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 369, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 369, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 369, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 369, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 369, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 493, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 493, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 493, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 493, 273.683002294);
    red_on();
    delay(304.092224771);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 440, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 493, 273.683002294);
    red_on();
    delay(304.092224771);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 391, 412.843850917);
    blue_on();
    delay(458.715389908);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 391, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 391, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 391, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 391, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 391, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 493, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 493, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 493, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 493, 273.683002294);
    red_on();
    delay(304.092224771);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 554, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 587, 273.683002294);
    red_on();
    delay(304.092224771);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 440, 412.843850917);
    blue_on();
    delay(458.715389908);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 440, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 440, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 440, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 440, 41.7482545872);
    blue_on();
    delay(46.3869495413);
    delay(36.0787385321);
    blue_off();
    tone(tonePin, 440, 37.109559633);
    red_on();
    delay(41.2328440367);
    delay(30.9246330275);
    red_off();
    tone(tonePin, 440, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 587, 134.52215367);
    red_on();
    delay(149.469059633);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 587, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 587, 46.3869495413);
    red_on();
    delay(51.5410550459);
    delay(30.9246330275);
    red_off();
    tone(tonePin, 587, 46.3869495413);
    blue_on();
    delay(51.5410550459);
    delay(20.6164220183);
    blue_off();
    tone(tonePin, 587, 273.683002294);
    red_on();
    delay(304.092224771);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 659, 134.52215367);
    blue_on();
    delay(149.469059633);
    delay(5.15410550459);
    blue_off();
    tone(tonePin, 659, 273.683002294);
    red_on();
    delay(304.092224771);
    delay(5.15410550459);
    red_off();
    tone(tonePin, 554, 691.165548165);
    blue_on();
    red_on();
    delay(500);
    red_off();
    blue_off();
}
