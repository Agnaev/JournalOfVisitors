#pragma once

#include <string>

class InputOutput {
public:
  virtual bool input() = 0;
  virtual void output() = 0;
  virtual std::string format() = 0;
};
