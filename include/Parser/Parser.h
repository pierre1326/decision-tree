#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Parser {

  public:
    virtual char * createFrame(string id, string address, string registers) { return 0; }
    virtual void readFrame(char * buffer) {}

};

#endif