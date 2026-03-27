#include <Wire.h>

int16_t AcX, AcY, AcZ;

void calculateTilt() {
  AcX = random(-16000, 16000);
  AcY = random(-16000, 16000);
  AcZ = 16000;

  Serial.print("Raw X: "); Serial.print(AcX);
  Serial.print(" | Raw Y: "); Serial.print(AcY);
  Serial.print(" | Raw Z: "); Serial.println(AcZ);

  float angleX = atan(AcY / sqrt(AcX * AcX + AcZ * AcZ)) * 180 / PI;
  float angleY = atan(-AcX / sqrt(AcY * AcY + AcZ * AcZ)) * 180 / PI;

  Serial.print("Tilt X: "); Serial.print(angleX);
  Serial.print(" | Tilt Y: "); Serial.println(angleY);

  Serial.println("----------------------");
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  calculateTilt();
  delay(1000);
}