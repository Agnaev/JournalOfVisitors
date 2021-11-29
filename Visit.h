#pragma once

#include <iostream>
#include <string>
#include "InputOutput.h"
#include "DateTime.h"
#include "maps.h"

class Visit : public InputOutput {
  DateTime dateTimeOfVisit;
  int visitorId = 0;
  int employeeId = 0;
  std::string reasonOfVisit;

public:

  bool input() override {
    int visitorId, employeeId;
    std::cout << "Input employee id: ";
    std::cin >> employeeId;
    if (employeesMap.count(employeeId) == 0) {
      std::cout << "Employee not exist" << std::endl;
      return false;
    }
    std::cout << "Input visitor id: ";
    std::cin >> visitorId;
    if (visitorsMap.count(visitorId) == 0) {
      std::cout << "Visitor not found" << std::endl;
      return false;
    }

    this->visitorId = visitorId;
    this->employeeId = employeeId;

    std::cout << "Input date and time of visit: ";
    this->dateTimeOfVisit.input();

    std::cout << "Input reason of visit: ";
    std::cin >> this->reasonOfVisit;
    return true;
  }

  std::string format() override {
    char buf[100];
    std::snprintf(
      buf,
      100,
      "Employee:\nvisitor id: %d\nemployee id: %d\nreason of visit: %s\n date of visit: %s",
      visitorId,
      employeeId,
      reasonOfVisit.c_str(),
      dateTimeOfVisit.format().c_str()
    );
    return std::string(buf);
  }

  void output() override {
    std::cout << this->format();
  }
};

