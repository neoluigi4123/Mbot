#include <MeMegaPi.h>

MeUltrasonicSensor ultraSensorLeft(PORT_7);
MeUltrasonicSensor ultraSensorRight(PORT_8);

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
}

void loop() {
  // Send data:
  // Serial.println("Hello from Arduino");
  // delay(1000);

  // Receive data:
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil("\n");
    // Works fine:
    if (message == "ping") {
      Serial.println("Hello from Arduino");
    }
    if (message == "get_dist") {
      float dist_left = ultraSensorLeft.distanceCm();
      float dist_right = ultraSensorRight.distanceCm();
      Serial.print("distance_L_R=" + String(dist_left) + ";" + String(dist_right));
    }
    if (message == "get_dist_left") {
      float dist = ultraSensorLeft.distanceCm();
      Serial.print("distance_L=" + String(dist));
    }
    if (message == "get_dist_right") {
      float dist = ultraSensorRight.distanceCm();
      Serial.print("distance_R=" + String(dist));
    }
  }
}
