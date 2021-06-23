#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

/**
 * Estructura que almacena los valores de la cola 
 **/
struct NodeQueue {
  string product;
  int value;
  NodeQueue* next;
};

class Queue {
  
  public:
    /**
     * Constructor por defecto
    **/
    Queue();

    /**
     * Agrega un nuevo elemento a la cola
     * 
     * @param product Nombre del producto
     * @param value   Valor del producto
    **/
    void add(string product, int value);

    /**
     * Retorna el siguiente nodo de la cola
     * 
     * @return  Primer nodo en la cola
    **/
    NodeQueue * getNext();

    /**
     * Retorna el largo de la cola
    **/
    int getSize();

  private:
    //Raiz de la cola
    NodeQueue* root;
    //Largo de la cola
    int size = 0;

};

#endif