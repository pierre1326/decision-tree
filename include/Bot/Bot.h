#ifndef BOT_H
#define BOT_H

#include "Cart/Cart.h"
#include "Tree/Tree.h"
#include "Queue/Queue.h"

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

class Bot {
  
  public:

    /**
     * Constructor por defecto
     * */
    Bot();

    /**
     * Constructor de la clase Bot
     * 
     * @param   Tree  Arbol utilizado para el chatbot para el despliegue de mensajes
     * @return  Bot listo para iniciar  
     **/
    Bot(Tree tree);

    /**
     * Inicia el flujo del chatbot
     * */
    void init();

  private:

    //Almacena los valores iterados en la conversacion
    Queue buffer;
    //Arbol con la informacion para el flujo de la conversacion
    Tree tree;
    //Punto actual de la conversacion en el arbol
    TreeNode * actualPosition;
    //Carrito de compras del usuario
    Cart cart;
    //Condicional para indicar si el usuario se retiro del chatbot
    bool stop = false;

    /**
     * Ejecuta la opcion indicada en los hijos del nodo padre
     * 
     * @param option  Hijo seleccionado por el usuario
     **/
    void executeOption(int option);

    /**
     * Ejecuta la funcion correspondiente al llegar a un nodo hoja segun el valor inicial obtenido en la cola
     **/
    void finalizeOption();

    /**
     * Agrega un producto al carrito de compras 
     **/
    void addProduct();

    /**
     * Aplica un descuento a la compra del usuario
     **/
    void applyPromotion();

    /**
     * Imprime la factura del usuario con o sin detalle
     **/
    void printBill();

    /**
     * Elimina los productos del carrito de compras
     **/
    void deleteProduct();

    /**
     * Elimina un unico producto indicado por el usuario del carrito de compras
     **/
    void deleteOneProduct();

};

#endif