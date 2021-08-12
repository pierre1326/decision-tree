#include "Parser/Information.h"

Information::Information(int value, int device, int function) {
  this->error = false;
  this->value = value;
  this->device = device;
  this->function = function;
}

Information::Information(string errorMessage, string errorTitle, int device, int function, int exception) {
  this->error = true;
  this->errorMessage = errorMessage;
  this->errorTitle = errorTitle;
  this->device = device;
  this->value = exception;
  this->function = function;
}

bool Information::isError() {
  return this->error;
}

string Information::getErrorMessage() {
  return this->errorMessage;
}

string Information::getErrorTitle() {
  return this->errorTitle;
}

int Information::getDevice() {
  return this->device;
}

int Information::getFunction() {
  return this->function;
}

int Information::getValue() {
  return this->value;
}