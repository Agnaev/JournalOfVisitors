#pragma once

#include <iostream>
#include <string>
#include "InputOutput.h"
#include "maps.h"

class Visitor : public InputOutput {
  int visitorId = 0;
  std::string fullName;

public:

  bool input() override {
    int visitorId;
    std::cout << "Input visitor id: ";
    std::cin >> visitorId;
    if (visitorsMap.count(visitorId) > 0) {
      std::cout << "Visitor with specific id exist" << std::endl;
      return false;
    }
    this->visitorId = visitorId;
    std::cout << "Input name: ";
    std::cin >> fullName;

    visitorsMap[visitorId] = *this;
    return true;
  }

  std::string format() override {
    char buf[100];
    std::snprintf(
      buf,
      100,
      "Visitor:\nvisitor id: %d\nfull name: %s\n",
      visitorId,
      fullName.c_str()
    );
    return std::string(buf);
  }

  void output() override {
    std::cout << this->format();
  }
};
