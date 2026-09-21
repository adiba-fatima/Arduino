const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int RELAY_PIN = 8;

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF initially

  Serial.begin(9600);
  Serial.println("Ultrasonic + Relay + Bulb");
}

void loop()
{
  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo duration
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert to distance (cm)
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control relay based on distance
  if (distance > 0 && distance < 20)
  {
    digitalWrite(RELAY_PIN, LOW);   // Relay ON
    Serial.println("Bulb ON");
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
    Serial.println("Bulb OFF");
  }

  delay(200);
}
