#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <time.h>
int timezone = 7 * 3600; //ตั้งค่า TimeZone ตามเวลาประเทศไทย
int dst = 0; //กำหนดค่า Date Swing Time
int hr_m = 99, mint_m = 99, hr_n = 99, mint_n = 99;

const int pingPin = D1;
int inPin = D2;//อัลต้าโซนิค
int count_dogeat = 0;

char auth[] = "2ae4032458ec496e87333ff98fb0a775";//blynk key

BLYNK_WRITE(V1) {
  TimeInputParam t(param);

  // Process start time

  if (t.hasStartTime())
  {
    hr_m = t.getStartHour();
    mint_m = t.getStartMinute();
  }
}

BLYNK_WRITE(V2) {
  TimeInputParam t(param);

  // Process start time

  if (t.hasStartTime())
  {
    hr_n = t.getStartHour();
    mint_n = t.getStartMinute();
  }
}

void setup() {
  pinMode(D4, OUTPUT);
  
  Blynk.begin(auth, "AndroidAP", "55667744");
  Serial.begin(115200);
  
  configTime(timezone, dst, "pool.ntp.org", "time.nist.gov"); //ดึงเวลาจาก Server

}
void loop() {
  Blynk.run();
  
  Serial.println(String("Time set: ") + hr_m + ":" +mint_m);
  Serial.println(String("Time set: ") + hr_n + ":" +mint_n);
  
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  Serial.print(p_tm->tm_hour);
  Serial.print(":");
  Serial.print(p_tm->tm_min);
  Serial.print(":");
  Serial.print(p_tm->tm_sec);
  Serial.println("");
  delay(1000);

  if(((hr_m == p_tm->tm_hour) && (mint_m == p_tm->tm_min) && (p_tm->tm_sec == 0)) || ((hr_n == p_tm->tm_hour) && (mint_n == p_tm->tm_min) && (p_tm->tm_sec == 0))){
    Serial.println(digitalRead(D4));
    if(digitalRead(D4) != 1){
      digitalWrite(D4, HIGH);
      Serial.println(digitalRead(D4));
      delay(300);
      digitalWrite(D4, LOW);
    }
  }

  long duration, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  if(cm > 0 && cm < 61){
    Serial.print(cm);
    Serial.println(" cm\n");
    delay(1000);
    if(cm < 30){
      count_dogeat += 1;
      Serial.print("dog in: ");
      Serial.print(count_dogeat);
      Serial.print(" sec\n");
      if(count_dogeat == 4){
        Blynk.notify("Your dog is enjoy eating now!!!");
      }
    }
    else count_dogeat = 0;
  }
  else count_dogeat = 0;
}
  
 long microsecondsToCentimeters(long microseconds)
 {
  // ความเร็วเสียงในอากาศประมาณ 340 เมตร/วินาที หรือ 29 ไมโครวินาที/เซนติเมตร
  // ระยะทางที่ส่งเสียงออกไปจนเสียงสะท้อนกลับมาสามารถใช้หาระยะทางของวัตถุได้
  // เวลาที่ใช้คือ ระยะทางไปกลับ ดังนั้นระยะทางคือ ครึ่งหนึ่งของที่วัดได้
  return microseconds / 29 / 2;
 }

