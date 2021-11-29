#include <string>
#include <fstream>
#include <iostream>

#define LOGFILENAME "journalLog.log"

class Logger {
public:
	virtual void write(std::string) = 0;
};

class Journal : public Logger {
private:
  std::string name;
  std::string legalAddress;
  std::string kindOfActivity;
  int numberOfVisitingDaysPerWeek = 0;

  std::ofstream file;

  ~Journal() {
    this->close();
  }
  Journal() {}
  Journal(const Journal&);
  Journal& operator=(Journal&);

  void open() {
    this->file.open(LOGFILENAME, std::ios::app);
  }

  void close() {
    this->file.close();
  }

public:

  void write(std::string message) override {
    try {
      this->open();
      if (!this->file.is_open()) {
        std::cout << "Can't write to file" << std::endl;
        return;
      }
      std::cout << "writed to file" << std::endl;
      file << message << std::endl << "--------------------------------------------" << std::endl;
    }
    catch(std::exception&) {
      std::cout << "Can't write to file" << std::endl;
    }
    std::cout << "finnaly vlock" << std::endl;
    this->close();
  }

  static Journal& getInstance() {
    static Journal p_instance;
    return p_instance;
  }
};
