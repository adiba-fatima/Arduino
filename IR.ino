const int IR_PIN = 2;   // Sensor OUT pin

void setup() {
  pinMode(IR_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("IR Sensor Test");
}

void loop() {
  int sensorValue = digitalRead(IR_PIN);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  delay(200);
}
