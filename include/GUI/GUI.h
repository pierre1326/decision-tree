#ifndef GUI_H
#define GUI_H

#include "Tree/Tree.h"
#include "File/File.h"
#include "Bot/Bot.h"

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

class Gui {
  
  public:
    /**
     * Constructor de la consola principal
     * 
     * @param path  Ruta del arbol a cargar
     **/
    Gui(string path);

    /**
     * Inicia la interfaz por consola 
     **/
    void init();

  private:
    //Arbol con la informacion del chatbot
    Tree tree;
    //Bot usado para la conversacion
    Bot bot;
    //Archivo con la informacion del arbol
    File file;
    //Ruta del archivo
    string path;

    /**
     * Ejecuta la opcion indicado por el usuario
     * 
     * @param option  Opcion ingresada por el usuario
     **/
    void executeOption(int option);

    /**
     * Solicita la informacion e ingresa el nodo al arbol
     **/
    void addNode();

    /**
     * Elimina el nodo del arbol con el ID dado por el usuario
     **/
    void deleteNode();

    /**
     * Inicia la conversacion con el chatbot
     **/
    void initBot();

};

#endif