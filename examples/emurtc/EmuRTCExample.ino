#include "ArtificialRTC.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Serial 115200");
  delay(500);

  // Define a DateTime object with specific date and time values
  DateTime datetime = { 2024, 12, 18, 14, 30, 0 };

  // Set the system date and time using the setSystemDateTime method
  ArtificialRTC::setSystemDateTime(datetime);

  // Get the current system date and time
  DateTime currentTime = ArtificialRTC::getSystemDateTime();
  Serial.print("Current date and time: ");
  Serial.print(currentTime.year);
  Serial.print("-");
  Serial.print(currentTime.month);
  Serial.print("-");
  Serial.print(currentTime.day);
  Serial.print(" ");
  Serial.print(currentTime.hour);
  Serial.print(":");
  Serial.print(currentTime.minute);
  Serial.print(":");
  Serial.println(currentTime.second);

  // Print the date and time every 1000 milliseconds
  for (int i = 0; i < 10; i++) {
    delay(500);

    // Set the system date and time using the setSystemDateTime method
    currentTime = ArtificialRTC::getSystemDateTime();
    Serial.print("Every 1000ms date and time: ");
    Serial.print(currentTime.year);
    Serial.print("-");
    Serial.print(currentTime.month);
    Serial.print("-");
    Serial.print(currentTime.day);
    Serial.print(" ");
    Serial.print(currentTime.hour);
    Serial.print(":");
    Serial.print(currentTime.minute);
    Serial.print(":");
    Serial.println(currentTime.second);

    delay(500);
  }
}

void loop() {
}