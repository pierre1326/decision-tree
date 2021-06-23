#include "Queue/Queue.h"

Queue::Queue() {}

void Queue::add(string product, int value) {
  NodeQueue *node = new NodeQueue;
  node->product = product;
  node->value = value;
  node->next = NULL;
  if(this->size == 0) {
    this->root = node;
  }
  else {
    NodeQueue* temp = root;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = node;
  }
  this->size++;
}

NodeQueue * Queue::getNext() {
  NodeQueue * result = this->root;
  this->root = this->root->next;
  this->size--;
  return result;
}

int Queue::getSize() {
  return this->size;
}