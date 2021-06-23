#ifndef GUI_H
#define GUI_H

#include "Tree/Tree.h"
#include "Cart/Cart.h"
#include "File/File.h"

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

class Gui {
  
  public:
    Gui(string path);
    void init();

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