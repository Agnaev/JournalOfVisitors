#pragma once

#include <iostream>
#include <string>
#include "InputOutput.h"
#include "maps.h"

class Employee : public InputOutput {
  int employeeId = 0;
  std::string lastName;
  std::string position;

public:

  bool input() override {
    int employeeId;
    std::cout << "Input employeeId: ";
    std::cin >> employeeId;
    if (employeesMap.count(employeeId) > 0) {
      std::cout << "Employee with specified id exist" << std::endl;
      return false;
    }
    this->employeeId = employeeId;
    std::cout << "Input last name: ";
    std::cin >> lastName;
    std::cout << "and position: ";
    std::cin >> position;

    employeesMap[employeeId] = *this;
    return true;
  }

  std::string format() override {
    char buf[100];
    std::snprintf(
      buf,
      100,
      "Employee: \nemployeeId: %d\nlast name: %s\nposition: %s",
      employeeId,
      lastName.c_str(),
      position.c_str()
    );
    return std::string(buf);
  }

  void output() override {
    std::cout << this->format();
  }
};
