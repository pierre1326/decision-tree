#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#include <streambuf>
#include <fstream>
#include <string>

#include "Parser/Parser.h"
#include "Parser/ParserModbus.h"

using namespace std;


class ParserFactory {

  public:

    enum Protocol {
      MODBUS
    };

    static Parser * getInstance(Protocol protocol) {
      if(protocol == MODBUS) {
        Parser * ptr = new ParserModbus;
        return ptr;
      }
      else {
        throw "The protocol does not exist";
      }
    }

};

#endif