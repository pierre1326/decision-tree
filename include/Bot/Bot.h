#ifndef BOT_H
#define BOT_H

#include "Cart/Cart.h"

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

class Bot {
  
  public:
    Bot();
    void init();

  private:
    Cart cart;

};

#endif