#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

#include "Parser/Parser.h"
#include "Parser/ParserFactory.h"

using namespace std;

int main() {	
	Parser * parser = ParserFactory::getInstance(ParserFactory::Protocol::MODBUS);
	parser->createFrame("17", "40108", "3");
	char * response = (char *)malloc(sizeof(char) * 7);
	response[0] = 0x11u;
	response[1] = 0x04u;
	response[2] = 0x02u;
	response[3] = 0x00u;
	response[4] = 0x0Au;
	response[5] = 0xF8u;
	response[6] = 0xF4u;
	parser->readFrame(response, false);
	free(response);
	return 0;
}