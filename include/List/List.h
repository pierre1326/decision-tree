#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

/**
 * Estructura que almacena la informacion de la lista
 **/
struct Node {
  int price;
  int quantity;
  string name;
  Node* next;
};

class List {
  
  public:

    /**
    * Constructor por defecto 
    **/
    List();

    /**
    * Agregar un nuevo elemento a la lista
    * 
    * @param  name      Nombre del producto
    * @param  price     Precio del producto
    * @param  quantity  Cantidad del producto
    **/
    void add(string name, int price, int quantity);

    /**
    * Retorna el nombre del producto en el indice dado
    * 
    * @param  index Indice del nodo
    * @return Nombre del producto
    **/
    string getName(int index);

    /**
    * Retorna el precio del producto en el indice dado
    * 
    * @param  index Indice del nodo
    * @return Precio del producto
    **/
    int getPrice(int index);

    /**
    * Retorna la cantidad del producto en el indice dado
    * 
    * @param  index Indice del nodo
    * @return Cantidad del producto
    **/
    int getQuantity(int index);

    /**
     * Retorna el largo de la lista
     **/
    int getSize();

    /**
     * Remueve un elemento de la lista
     * 
     * @param index Posicion del elemento a eliminar
     **/
    void remove(int index);

  private:
    //Raiz de la lista
    Node* root;
    //Largo de la lista
    int size = 0;

};

#endif