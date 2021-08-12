#ifndef INFORMATION_H
#define INFORMATION_G

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Information {

  public:
    Information(string errorMessage, string errorTitle, int device, int function, int exception);
    Information(int value, int device, int function);
    bool isError();
    string getErrorMessage();
    string getErrorTitle();
    int getValue();
    int getDevice();
    int getFunction();

  private:
    bool error;
    string errorMessage;
    string errorTitle;
    int value, device, function;

};

#endif