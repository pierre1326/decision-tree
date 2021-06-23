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
    void setProducts(List products);
    void printBill();
    void printTotal();
    void addProduct(string name, int value, int quantity);
    void deleteProduct(int index);
    void setPromotion(int promotion);
    void deleteAll();
    List getProducts();

  private:
    List products;
    int promotion = 0;
    string formatString(string text, int spaces);

};

#endif