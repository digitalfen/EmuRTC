# EmuRTC Library

This library provides functions to manage  and calculate the date and time for esp32, esp8266 and arduino boards with no clock support, using arduino internal millis function;

## Methods

### setSystemDateTime(DateTime dt)
Sets the system date and time.

### getSystemDateTime()
Returns the current date and time as a `DateTime` object.

## DateTime Structure

The `DateTime` structure contains the following fields:

- `year`: The year (e.g., 2024).
- `month`: The month (1–12).
- `day`: The day of the month (1–31).
- `hour`: The hour of the day (0–23).
- `minute`: The minute of the hour (0–59).
- `second`: The second of the minute (0–59).

## Example

```cpp
#include "EmuRTC.h"

void setup() {
  // Initialize the serial communication at 115200 baud rate
  Serial.begin(115200);
  Serial.println("Serial 115200");
  delay(500);

  // Define a DateTime object with specific date and time values
  DateTime datetime = { 2024, 12, 18, 14, 30, 0 };

  // Set the system date and time using the setSystemDateTime method
  EmuRTC::setSystemDateTime(datetime);

  // Get the current system date and time
  DateTime currentTime = EmuRTC::getSystemDateTime();
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
    currentTime = EmuRTC::getSystemDateTime();
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
```