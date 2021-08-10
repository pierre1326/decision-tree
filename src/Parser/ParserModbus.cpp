#include "ParserModbus.h"

void ParserModbus::readFrame(char * buffer) {
  char function = buffer[1];
  if(function == 0x03 || function == 0x04) {
    //TO DO
  }
  else {
    readError(buffer);
  }
}

void ParserModbus::readError(char * buffer) {
  char id = buffer[0];
  char function = buffer[1];
  char exception = buffer[2];
  string crc = hexToString(buffer[3]) + hexToString(buffer[4]);
  string crcVerification = calculateCRC(buffer, 3);
  cout << crc << endl;
  cout << crcVerification << endl;
  if(crc == crcVerification) {
    cout << "Valor valido" << endl;
    //LOG DE ERROR
  }
  else {
    //LOG DE CORRUPCION DE DATOS
  }
}

string ParserModbus::hexToString(char value) {
  ostringstream os;
  os << hex << value;
  string result = os.str();
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