#ifndef BOT_H
#define BOT_H

#include "Cart/Cart.h"
#include "Tree/Tree.h"
#include "Queue/Queue.h"

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
    Queue buffer;
    Tree tree;
    TreeNode * actualPosition;
    Cart cart;
    bool stop = false;

    void executeOption(int option);
    void finalizeOption();
    void addProduct();
    void applyPromotion();
    void printBill();
    void deleteProduct();
    void deleteOneProduct();

};

#endif