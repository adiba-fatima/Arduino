#include <Servo.h>

const int IR_PIN = 2;     // IR sensor OUT pin
const int SERVO_PIN = 9;  // Servo signal pin

Servo myServo;

void setup() {
  pinMode(IR_PIN, INPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0); // Start at 0 degrees
  Serial.begin(9600);
  Serial.println("IR + Servo Test");
}

void loop() {
  int sensorValue = digitalRead(IR_PIN);

  if (sensorValue == LOW) {   // Object detected (active LOW)
    myServo.write(90);        // Move servo to 90 degrees
    Serial.println("Object Detected → Servo at 90°");
  } else {
    myServo.write(0);         // Return to 0 degrees
    Serial.println("No Object → Servo at 0°");
  }

  delay(200);
}
