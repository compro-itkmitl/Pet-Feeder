#include <Servo.h> 

int botton = 8;
Servo myservo;   

void setup() 

{ 
  pinMode(botton, INPUT_PULLUP);
  myservo.attach(9); 

} 

void loop() 
{       
  int value = digitalRead(botton);

  if(value == 1){
    myservo.write(0); 
                        
  }else{
    myservo.write(90); 
  }
}
