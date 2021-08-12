#include "ParserModbus.h"

Information * ParserModbus::readFrame(char * buffer, bool isSigned) {
  char function = buffer[1];
  if(function == 0x03 || function == 0x04) {
    return readData(buffer, isSigned);
  }
  else {
    return readError(buffer);
  }
}

Information * ParserModbus::readData(char * buffer, bool isSigned) {
  int id = (int)buffer[0];
  int function = (int)buffer[1];
  int count = (int)buffer[2];
  string value = "";
  for(int i = 0; i < count; i++) {
    char data = buffer[3 + i];
    value = value + hexToString(data);
  }
  int transform = stoi(value, 0, 16);
  if(isSigned) {
    transform = this->processValue(value);
  }
  Information * information = new Information(transform, id, function);
  return information;
}

Information * ParserModbus::readError(char * buffer) {
  int id = (int)buffer[0];
  int function = (int)buffer[1];
  int exception = (int)buffer[2];
  Information * information = new Information("Error in frame modbus from device", "Device read error", id, function, exception);
  return information;
}

int ParserModbus::processValue(string value) {
  return stoi(value);
}

string ParserModbus::hexToString(char value) {
  int temp = (int)value;
  stringstream streamHex;
  streamHex << hex << temp;
  string result(streamHex.str());
  if(result.length() < 2) {
    result = "0" + result;
  }
  return result;
}

char * ParserModbus::createFrame(string id, string address, string registers) {
  string frame = getID(id) + getFunction(address) + getAddress(address) + getBits(registers);
	char * buffer = (char *)malloc(sizeof(char) * 8);
  for(int i = 0, j = 0; i < 6; i++, j += 2) {
    string result = frame.substr(j, 2);
    int num = stoi(result, 0, 16);
    buffer[i] = num;
  }
  string crc = calculateCRC(buffer, 6);
  buffer[6] = stoi(crc.substr(0, 2), 0, 16);
  buffer[7] = stoi(crc.substr(2, 2), 0, 16);
  return buffer;
}

string ParserModbus::getID(string data) {
  int value = stoi(data);
  stringstream streamHex;
  streamHex << hex << value;
  string result(streamHex.str());
  return result;
}

string ParserModbus::getFunction(string address) {
  char first = address.at(0);
  if(first == '3') {
    return "04";
  }
  else {
    return "03";
  }
}

string ParserModbus::getBits(string data) {
  int value = stoi(data);
  stringstream streamHex;
  streamHex << hex << value;
  string result(streamHex.str());
  size_t len = strlen(result.c_str());
  for(int i = 0; i < 4 - len; i++) {
    result = "0" + result;
  }
  return result;
}

string ParserModbus::getAddress(string data) {
  int offset = (stoi(data.substr(0,1)) * ( strlen(data.c_str()) == 5 ? 10000 : 100000 )) + 1;
  int startAddress = stoi(data) - offset;
  stringstream streamHex;
  streamHex << hex << startAddress;
  string result(streamHex.str());
  size_t len = strlen(result.c_str());
  for(int i = 0; i < 4 - len; i++) {
    result = "0" + result;
  }
  return result;
}

string ParserModbus::calculateCRC(char * buff, int size) {
  unsigned short tmp = 0xffff;
  unsigned short ret = 0;
  for(int n = 0; n < size; n ++) {
    tmp = buff[n] ^ tmp;
    for(int i = 0; i < 8; i ++) {
      if(tmp & 0x01) {
        tmp = tmp >> 1;
        tmp = tmp ^ 0xa001;
      }   
      else {
        tmp = tmp >> 1;
      }   
    }   
  }   
  ret = tmp >> 8;
  ret = ret | (tmp << 8);
  stringstream streamHex;
  streamHex << hex << ret;
  string result(streamHex.str());
  return result;
}