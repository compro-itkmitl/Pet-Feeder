
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2ae4032458ec496e87333ff98fb0a775";
 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "iPad", "29592959");
}
 
void loop()
{
  Blynk.run();
  int value1 = 50;
  int value2 = 45;
  Blynk.virtualWrite(10,value1);
  Blynk.virtualWrite(11,value2);
}
