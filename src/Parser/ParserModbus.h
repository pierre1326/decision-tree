#ifndef PARSERMODBUS_H
#define PARSERMODBUS_H

#include <iostream>
#include <string>
#include <sstream>

#include "Parser/Parser.h"

using namespace std;

class ParserModbus: public Parser {

  public:   
    virtual char * createFrame(string id, string address, string registers);
    virtual void readFrame(char * buffer);

  private:
    string getID(string data);
    string getFunction(string address);
    string getBits(string data);
    string getAddress(string data);
    string calculateCRC(char * buff, int size);
    void readError(char * buffer);
    void readData(char * bufffer);
    string hexToString(char value);

};

#endif