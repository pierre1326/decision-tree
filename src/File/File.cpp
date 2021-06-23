#include "File/File.h"

File::File() {}

string File::load(string path) {
  ifstream file(path, ios::binary);
  string fileStr;
  istreambuf_iterator<char> inputIt(file), emptyInputIt;
  back_insert_iterator<string> stringInsert(fileStr);
  copy(inputIt, emptyInputIt, stringInsert);
  return fileStr;
}

bool File::write(string path, string text) {
  ofstream myfile;
  myfile.open(path);
  myfile << text;
  myfile.close();
  return true;
}