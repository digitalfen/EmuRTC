#ifndef EmuRTC_h
#define EmuRTC_h

#include "DateTime.h"

#include <Arduino.h>

/**
 * @class EmuRTC
 * @brief A class for handling date and time functions on ESP8266, ESP32 and Arduino boards.
 * 
 * This class allows you to set and retrieve the system date and time based on seconds since Unix epoch (1970-01-01 00:00:00 UTC).
 * You can set the system time using a DateTime object and get the current time.
 * The time is stored as a timestamp in seconds, making it easy to handle and manipulate.
 */
class EmuRTC {
public:
  /**
     * @brief Set the system date and time.
     * 
     * This method sets the system date and time using a DateTime object. It calculates
     * the number of days since 1970-01-01 and converts it into seconds.
     * 
     * @param dt A DateTime object representing the desired date and time.
     */
  static void setSystemDateTime(DateTime dt);

  /**
     * @brief Get the current date and time.
     * 
     * This method retrieves the current date and time based on the stored timestamp and the elapsed time.
     * It returns a DateTime object representing the current date and time.
     * 
     * @return A DateTime object with the current date and time.
     */
  static DateTime getSystemDateTime();

private:
  /**
     * @brief Helper function to check if a year is a leap year.
     * 
     * @param year The year to check.
     * @return true if the year is a leap year, false otherwise.
     */
  static bool isLeapYear(unsigned long year);

  static unsigned long timestamp;  ///< The timestamp in seconds since the Unix epoch.
  static unsigned long millisref;  ///< Reference to the time when the system time was last set (in milliseconds).
};

#endif
