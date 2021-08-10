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
	char * response = (char *)malloc(sizeof(char) * 5);
	response[0] = 0x0Au;
	response[1] = 0x81u;
	response[2] = 0x02u;
	response[3] = 0xB0u;
	response[4] = 0x53u;
	parser->readFrame(response);
	free(response);
	return 0;
}