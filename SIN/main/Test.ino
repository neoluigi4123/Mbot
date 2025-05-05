#include <MeMegaPi.h>

MeGyro gyro(PORT_5);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  gyro.begin();
}

void loop() {
  // Send data:
  // Serial.println("Hello from Arduino");
  // delay(1000);

  // Receive data:
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil("\n");
    // Works fine:
    if (message = "ping") {
      Serial.println("Hello from Arduino");
    }
    // Need to be fixed:
    if (message = "gyro") {
      gyro.update();

      uint8_t x = gyro.getAngleX();
      uint8_t y = gyro.getAngleY();
      uint8_t z = gyro.getAngleZ();

      Serial.println(x + y + z);
    }
  }
}
