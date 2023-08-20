#include <Servo.h>

Servo servo; //creates servo object

void setup() {
  Serial.begin(9600); //begins serial monitor
  pinMode(A0, INPUT); //declares flexsensor as input

  servo.attach(10); //creates servo object on pin 9
  
}

void loop() {
  int ServoPos = 0;
  int FlexVal = analogRead(A0); //reads value of sensor
  Serial.println(FlexVal);

  ServoPos = map(FlexVal, 550, 800, 180, 0); //maps sensor input to servo range of motion

  servo.write(ServoPos);

}
