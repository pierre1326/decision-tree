#ifndef BOT_H
#define BOT_H

#include "Tree/Tree.h"
#include "Cart/Cart.h"
#include "File/File.h"

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

class Bot {
  
  public:
    Bot(string path);
    void initBot();

  private:
    Tree tree;
    Cart cart;
    File file;
    string path;

    void executeOption(int option);
    void addNode();
    void deleteNode();

};

#endif