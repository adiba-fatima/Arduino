#include <Servo.h>

Servo myServo;

int trigPin = 6;
int echoPin = 7;
int servoPin = 9;

long duration;
float distance;

int currentAngle = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(0);

  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Object is within 20 cm
  if (distance <= 20) {

    // Slowly move to 90°
    if (currentAngle < 90) {
      currentAngle++;
      myServo.write(currentAngle);
      delay(20);
    }
  }

  // Object is farther than 20 cm
  else {

    // Slowly return to 0°
    if (currentAngle > 0) {
      currentAngle--;
      myServo.write(currentAngle);
      delay(20);
    }
  }
}
//servo + ultrasonic sensor.