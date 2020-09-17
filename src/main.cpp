#include <Arduino.h>

#define BAUD_RATE 115200

#define INPUT_PIN A0
#define MODE INPUT

#define DELAY 1000

long calculateVoltage(int analogVoltage);

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.printf("Starting setup (baud rate: '%s') ...%n", BAUD_RATE);

  Serial.println("Setting pin A0 to INPUT.");
  pinMode(INPUT_PIN, MODE);
}

void loop() {
  Serial.println("---------");

  Serial.println("Reading pin A0 ...");
  int analogVoltage = analogRead(INPUT_PIN);
  Serial.printf("Analog read got '%s'.%n", analogVoltage);

  Serial.println("Calculating voltage ...");
  long voltage = calculateVoltage(analogVoltage);
  Serial.printf("Calculated '%s' volt.%n", voltage);

  Serial.println("---------");
  delay(DELAY);
}

long calculateVoltage(int analogVoltage) {
  return (long) analogVoltage / 1024 * 3.3;
}