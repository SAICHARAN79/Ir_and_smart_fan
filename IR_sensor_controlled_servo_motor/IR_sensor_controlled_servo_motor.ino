
//#include <Servo.h>

#include <Servo.h>

Servo tap_servo;

int sensor_pin = 4;
int tap_servo_pin =5;
int angle;
int count =0;
void setup(){
  pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
 Serial.begin(9600); 
}

void loop(){
  angle = digitalRead(sensor_pin);

  if (angle==0)
  { if (count % 2 == 0) {
      tap_servo.write(90);
      delay(1000);
      count++;
  
  }
 else  if (count % 2 == 1) 
  { tap_servo.write(0);
         delay(1000);
      count++;

   }
}
}
