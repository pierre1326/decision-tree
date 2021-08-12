#ifndef PARSERMODBUS_H
#define PARSERMODBUS_H

#include <iostream>
#include <string>
#include <sstream>

#include "Parser/Parser.h"
#include "Parser/Information.h"

using namespace std;

class ParserModbus: public Parser {

  public:   
    virtual char * createFrame(string id, string address, string registers);
    virtual Information * readFrame(char * buffer, bool isSigned);

  private:
    string getID(string data);
    string getFunction(string address);
    string getBits(string data);
    string getAddress(string data);
    string calculateCRC(char * buff, int size);
    Information * readError(char * buffer);
    Information * readData(char * bufffer, bool isSigned);
    string hexToString(char value);
    int processValue(string value);

};

#endif