#include "DateTime.h"

DateTime::DateTime() {
  year = 1970;
  month = 1;
  day = 1;
  hour = 0;
  minute = 0;
  second = 0;
}

DateTime::DateTime(unsigned long year, unsigned long month, unsigned long day,
                   unsigned long hour, unsigned long minute, unsigned long second) {
  setYear(year);
  setMonth(month);
  setDay(day);
  setHour(hour);
  setMinute(minute);
  setSecond(second);
}

unsigned long DateTime::getYear() const {
  return year;
}

unsigned long DateTime::getMonth() const {
  return month;
}

unsigned long DateTime::getDay() const {
  return day;
}

unsigned long DateTime::getHour() const {
  return hour;
}

unsigned long DateTime::getMinute() const {
  return minute;
}

unsigned long DateTime::getSecond() const {
  return second;
}

bool DateTime::setYear(unsigned long year) {
  if (year < 1) {
    resetToEpoch();
    return false;
  }
  this->year = year;
  return true;
}

bool DateTime::setMonth(unsigned long month) {
  if (month < 1 || month > 12) {
    resetToEpoch();
    return false;
  }
  this->month = month;
  return true;
}

bool DateTime::setDay(unsigned long day) {
  if (day < 1 || day > 31) {
    resetToEpoch();
    return false;
  }

  const unsigned long daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (month == 2) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
      if (day > 29) {
        resetToEpoch();
        return false;
      }
    } else {
      if (day > 28) {
        resetToEpoch();
        return false;
      }
    }
  } else if (day > daysInMonth[month - 1]) {
    resetToEpoch();
    return false;
  }

  this->day = day;
  return true;
}

bool DateTime::setHour(unsigned long hour) {
  if (hour < 0 || hour > 23) {
    resetToEpoch();
    return false;
  }
  this->hour = hour;
  return true;
}

bool DateTime::setMinute(unsigned long minute) {
  if (minute < 0 || minute > 59) {
    resetToEpoch();
    return false;
  }
  this->minute = minute;
  return true;
}

bool DateTime::setSecond(unsigned long second) {
  if (second < 0 || second > 59) {
    resetToEpoch();
    return false;
  }
  this->second = second;
  return true;
}

void DateTime::resetToEpoch() {
  year = 1970;
  month = 1;
  day = 1;
  hour = 0;
  minute = 0;
  second = 0;
}
