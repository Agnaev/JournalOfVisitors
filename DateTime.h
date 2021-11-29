#pragma once

#include <string>
#include <iostream>
#include "InputOutput.h"

class DateTime : public InputOutput {
  int day = 0, month = 0, year = 0, hour = 0, minute = 0;

public:

  bool input() override {
    std::cout << "Input date(dd MM YYYY hh mm):" << std::endl;
    std::cin >> day >> month >> year >> hour >> minute;
    return true;
  }

  std::string format() override {
    char buf[17];
    std::snprintf(
      buf,
      17,
      "%02d.%02d.%d %02d:%02d",
      day,
      month,
      year,
      hour,
      minute
    );
    return std::string(buf);
  }

  void output() override {
    std::cout << this->format();
  }
};
