#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

struct Node {
  int price;
  int quantity;
  string name;
  Node* next;
};

class List {
  
  public:
    List();
    void add(string name, int price, int quantity);
    string getName(int index);
    int getPrice(int index);
    int getQuantity(int index);
    int getSize();
    void remove(int index);

  private:
    Node* root;
    int size = 0;

};

#endif