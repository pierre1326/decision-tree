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

    /**
     * Constructor
     **/
    Cart();

    /**
     * Actualiza el atributo de productos
     * 
     * @param products  Lista de productos
     **/
    void setProducts(List products);

    /**
     * Imprime la factura con los productos del carrito
     **/
    void printBill();

    /**
     * Imprime el monto total de la factura
     **/
    void printTotal();

    /**
     * Agrega un nuevo producto a la lista 
     **/
    void addProduct(string name, int value, int quantity);

    /**
     * Elimina un producto del carrito
     **/
    void deleteProduct(int index);

    /**
     * Aplica un descuento a la compra
     **/
    void setPromotion(int promotion);

    /**
     * Elimina todos los productos del carrito
     **/
    void deleteAll();

    /**
     * Retorna la lista de productos
     * 
     * @return  lista de productos
     **/
    List getProducts();

  private:

    //Productos agregados por el usuario
    List products;
    //Descuento aplicado a la compra
    int promotion = 0;
    
    /**
     * Da formato a un valor para acomodarlo en la factura
     * 
     * @param text    Texto a arreglar
     * @param spaces  Espacios totales del string
     * @return  String con formato correcto
     **/
    string formatString(string text, int spaces);

};

#endif