#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

class File {
  
  public:
    File();
    string load(string path);
    bool write(string path, string text);

};

#endif