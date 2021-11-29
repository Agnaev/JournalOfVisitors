#include <iostream>
#include <string>
#include <array>
#include <map>
#include "Journal.h"
#include "InputOutput.h"
#include "DateTime.h"
#include "Employee.h"
#include "Visitor.h"
#include "Visit.h"
#include "maps.h"

void printMenu() {
  std::cout << "\n1) add employee\n2) add visitor\n3) add visit\n4) show logs\n0) exit" << std::endl;
}

void add(InputOutput* obj) {
  if (!obj->input()) {
    std::cout << "Invalid data" << std::endl;
    return;
  }
  Journal::getInstance().write(
    obj->format()
  );
}

InputOutput* createObject(int num) {
  switch (num)
  {
  case 1:
    return new Employee;
  case 2:
    return new Visitor;
  case 3:
    return new Visit;
  }
  return nullptr;
}

void showLogs() {
  system((std::string("notepad "), std::string(LOGFILENAME)).c_str());
}

int main() {
  setlocale(LC_ALL, "Russian");
  std::cout << "Журнал регистрации посетителей организации" << std::endl;

  int command;
  do {
    printMenu();
    std::cout << "command >> ";
    std::cin >> command;

    if (command > 0 && command < 4) {
      add(
        createObject(command)
      );
    }
    else if (4 == command) {
      showLogs();
    }
    else {
      std::cout << "Unrecognized command " << command << std::endl;
    }
  } while (command != 0);

  return 0;
}
