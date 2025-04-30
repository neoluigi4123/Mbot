void setup() {
  Serial.begin(115200);
  while (!Serial) {}
}

void loop() {
  // Send data:
  // Serial.println("Hello from Arduino");
  // delay(1000);

  // Receive data:
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil("\n");
    Serial.println(message);
  }
}
