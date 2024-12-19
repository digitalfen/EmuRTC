#include "EmuRTC.h"

unsigned long EmuRTC::timestamp = 0;
unsigned long EmuRTC::millisref = 0;

bool EmuRTC::isLeapYear(unsigned long year) {
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void EmuRTC::setSystemDateTime(DateTime dt) {
  millisref = millis();

  unsigned long days = 0;
  for (unsigned long i = 1970; i < dt.year; i++) {
    days += isLeapYear(i) ? 366 : 365;
  }

  int daysInMonth[] = { 31, (isLeapYear(dt.year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  for (unsigned long i = 0; i < dt.month - 1; i++) {
    days += daysInMonth[i];
  }

  days += dt.day - 1;

  timestamp = days * 24 * 60 * 60;
  timestamp += dt.hour * 60 * 60;
  timestamp += dt.minute * 60;
  timestamp += dt.second;
}

DateTime EmuRTC::getSystemDateTime() {
  unsigned long updatedTimestamp = timestamp + (millis() - millisref) / 1000;
  unsigned long days = updatedTimestamp / (24 * 60 * 60);
  unsigned long hours = (updatedTimestamp / (60 * 60)) % 24;
  unsigned long minutes = (updatedTimestamp / 60) % 60;
  unsigned long seconds = updatedTimestamp % 60;

  unsigned long year = 1970;
  while (true) {
    unsigned long daysInYear = isLeapYear(year) ? 366 : 365;
    if (days >= daysInYear) {
      days -= daysInYear;
      year++;
    } else {
      break;
    }
  }

  int daysInMonth[] = { 31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  unsigned long month = 0;
  while (days >= daysInMonth[month]) {
    days -= daysInMonth[month];
    month++;
  }

  DateTime fdt;
  fdt.year = year;
  fdt.month = month + 1;
  fdt.day = days + 1;
  fdt.hour = hours;
  fdt.minute = minutes;
  fdt.second = seconds;

  return fdt;
}