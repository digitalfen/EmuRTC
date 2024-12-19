#ifndef DateTime_h
#define DateTime_h

/**
 * @brief Struct that represents a date and time.
 * 
 * This structure holds the year, month, day, hour, minute, and second values
 * of a specific point in time. It can be used for various date and time calculations.
 */
struct DateTime {
  unsigned long year;    ///< Year of the date (e.g., 2024).
  unsigned long month;   ///< Month of the year (1-12).
  unsigned long day;     ///< Day of the month (1-31).
  unsigned long hour;    ///< Hour of the day (0-23).
  unsigned long minute;  ///< Minute of the hour (0-59).
  unsigned long second;  ///< Second of the minute (0-59).

  /**
   * @brief Default constructor. Initializes the date and time to a default value.
   */
  DateTime();

  /**
   * @brief Constructor with parameters. Initializes the date and time with provided values.
   * 
   * @param year Year of the date.
   * @param month Month of the year (1-12).
   * @param day Day of the month (1-31).
   * @param hour Hour of the day (0-23).
   * @param minute Minute of the hour (0-59).
   * @param second Second of the minute (0-59).
   */
  DateTime(unsigned long year, unsigned long month, unsigned long day,
           unsigned long hour, unsigned long minute, unsigned long second);

  /**
   * @brief Gets the year.
   * @return The year of the date.
   */
  unsigned long getYear() const;

  /**
   * @brief Gets the month.
   * @return The month of the year.
   */
  unsigned long getMonth() const;

  /**
   * @brief Gets the day.
   * @return The day of the month.
   */
  unsigned long getDay() const;

  /**
   * @brief Gets the hour.
   * @return The hour of the day.
   */
  unsigned long getHour() const;

  /**
   * @brief Gets the minute.
   * @return The minute of the hour.
   */
  unsigned long getMinute() const;

  /**
   * @brief Gets the second.
   * @return The second of the minute.
   */
  unsigned long getSecond() const;

  /**
   * @brief Sets the year.
   * 
   * If the provided year is invalid (less than 1), it resets the date to epoch time (January 1st, 1970).
   * @param year Year to be set.
   * @return true if the year was set successfully, false if invalid.
   */
  bool setYear(unsigned long year);

  /**
   * @brief Sets the month.
   * 
   * If the provided month is invalid (less than 1 or greater than 12), it resets the date to epoch time.
   * @param month Month to be set.
   * @return true if the month was set successfully, false if invalid.
   */
  bool setMonth(unsigned long month);

  /**
   * @brief Sets the day.
   * 
   * If the provided day is invalid (less than 1 or greater than the number of days in the month), 
   * it resets the date to epoch time.
   * @param day Day to be set.
   * @return true if the day was set successfully, false if invalid.
   */
  bool setDay(unsigned long day);

  /**
   * @brief Sets the hour.
   * 
   * If the provided hour is invalid (less than 0 or greater than 23), it resets the date to epoch time.
   * @param hour Hour to be set.
   * @return true if the hour was set successfully, false if invalid.
   */
  bool setHour(unsigned long hour);

  /**
   * @brief Sets the minute.
   * 
   * If the provided minute is invalid (less than 0 or greater than 59), it resets the date to epoch time.
   * @param minute Minute to be set.
   * @return true if the minute was set successfully, false if invalid.
   */
  bool setMinute(unsigned long minute);

  /**
   * @brief Sets the second.
   * 
   * If the provided second is invalid (less than 0 or greater than 59), it resets the date to epoch time.
   * @param second Second to be set.
   * @return true if the second was set successfully, false if invalid.
   */
  bool setSecond(unsigned long second);

private:
  /**
   * @brief Resets the date to epoch time (January 1st, 1970).
   */
  void resetToEpoch();
};

#endif
