#include <Servo.h>
Servo myServo;
int pirPin = 3;     // PIR sensor output pin
int pirState = 0;   // Current PIR state

void setup() {
  myServo.attach(9);       // Servo signal pin
  pinMode(pirPin, INPUT);  // PIR sensor input
}

void loop() {
  pirState = digitalRead(pirPin);  // Read PIR sensor
  if (pirState == HIGH) {
    
    myServo.write(90);     // Rotate servo to 90° when motion detected
    delay(100);
  } else {
    myServo.write(0);      // Return to 0° when no motion
  }
}
