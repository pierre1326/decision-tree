#ifndef CART_H
#define CART_H

#include "List/List.h"

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

class Cart {
  
  public:
    Cart();
    void printBill();
    void printTotal();
    void addProduct(string name, int value, int quantity);
    void deleteProduct(int index);

  private:
    List products;
    string formatString(string text, int spaces);

};

#endif