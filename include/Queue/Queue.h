#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

struct NodeQueue {
  string product;
  int value;
  NodeQueue* next;
};

class Queue {
  
  public:
    Queue();
    void add(string product, int value);
    NodeQueue * getNext();
    int getSize();

  private:
    NodeQueue* root;
    int size = 0;

};

#endif