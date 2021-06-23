#include "List/List.h"

 List::List() {}

void List::add(string name, int price, int quantity) {
  Node *node = new Node;
  node->name = name;
  node->price = price;
  node->quantity = quantity;
  node->next = NULL;
  if(this->size == 0) {
    this->root = node;
  }
  else {
    Node* temp = root;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = node;
  }
  this->size++;
}

int List::getQuantity(int index) {
  Node* temp = root;
  int actualIndex = 0;
  while(actualIndex != index) {
    temp = temp->next;
    actualIndex++;
  }
  return temp->quantity;
}

string List::getName(int index) {
  Node* temp = root;
  int actualIndex = 0;
  while(actualIndex != index) {
    temp = temp->next;
    actualIndex++;
  }
  return temp->name;
}

int List::getPrice(int index) {
  Node* temp = root;
  int actualIndex = 0;
  while(actualIndex != index) {
    temp = temp->next;
    actualIndex++;
  }
  return temp->price;
}

void List::remove(int index) {
  if(index == 0) {
    this->root = root->next;
  }
  else {
    Node *temp = root;
    int actualIndex = 0;
    while(actualIndex != (index - 1)) {
      temp = temp->next;
      actualIndex++;
    }
    temp->next = temp->next->next;
  }
  this->size--;
}

int List::getSize() {
  return size;
}