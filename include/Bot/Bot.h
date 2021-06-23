#ifndef BOT_H
#define BOT_H

#include "Cart/Cart.h"
#include "Tree/Tree.h"
#include "List/List.h"

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

class Bot {
  
  public:
    Bot();
    Bot(Tree tree);
    void init();

  private:
    List buffer;
    Tree tree;
    TreeNode * actualPosition;
    Cart cart;
    bool stop = false;

    void executeOption(int option);
    void finalizeOption();

};

#endif