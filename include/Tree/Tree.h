#ifndef TREE_H
#define TREE_H

#include <nlohmann/json.hpp>

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using json = nlohmann::json;
using namespace std;

/**
 * Estructura utilizada para almacenar la informacion del arbol
 **/
struct TreeNode {
  int id = -1;
  string label = "";
  string product = "";
  int value = 0;
  TreeNode *next = NULL;
  TreeNode *child = NULL;
};

class Tree {
  
  public:

    /**
     *  Constructor por defecto
     **/
    Tree();

    /**
     * Agrega un nuevo nodo al arbol
     * 
     * @param id      ID del nodo padre
     * @param label   Pregunta del nodo
     * @param product Nombre del producto
     * @param value   Valor del producto
     * @return  Verdadero si logro insertar el nodo, falso en otro caso
     **/
    bool addNode(int id, string label, string product, int value);

    /**
     * Agrega un nuevo nodo al arbol
     * 
     * @param id      ID del nodo padre
     * @param product Nombre del producto
     * @param label   Pregunta del nodo
     * @return  Verdadero si logro insertar el nodo, falso en otro caso
     **/
    bool addNode(int id, string label, string product);

    /**
     * Agrega un nuevo nodo al arbol
     * 
     * @param id      ID del nodo padre
     * @param product Nombre del producto
     * @param value   Valor del producto
     * @return  Verdadero si logro insertar el nodo, falso en otro caso
     **/
    bool addNode(int id, string product, int value);

    /**
     * Elimina un nodo del arbol
     * 
     * @param id  ID del nodo a eliminar
     * @return Verdadero si logro eliminarlo, falso en otro caso
     **/
    bool deleteNode(int id);

    /**
     * Genera los nodos del arbol a partir de un json
     * 
     * @param json  String con la informacion del arbol
     **/
    void createTree(string json);

    /**
     * Convierte el arbol a formato json
     * 
     * @return  Texto con la informacion del arbol
     **/
    string convertTree();

    /**
     * Devuelve la cantidad de nodos hojas
     * 
     * @return  Numero de nodos hojas
     **/
    int totalLeafNodes();

    /**
     * Devuelve el maximo numero de nodos hojas encontrados para un nodo padre
     * 
     * @return  Maximo numero de nodos
     **/
    int maxLeafsNodes();

    /**
     * Imprime la informacion de nodos que solo poseen un nodo hijo
     **/
    void onlyOneLeafNode();

    /**
     * Devuelve la minima altura del arbol
     * 
     * @return  Altura del arbol
     **/
    int minHeight();

    /**
     * Devuelve la maxima altura del arbol
     * 
     * @return  Altura del arbol
     **/
    int maxHeight();

    /**
     * Imprime la informacion del arbol en preorden
     **/
    void preorderTransversal();

    /**
     * Imprime la informacion del arbol en orden
     **/
    void orderTransversal();

    /**
     * Imprime la informacion del arbol por cada rama
     **/
    void printTree();

    /**
     * Devuelve la raiz del arbol
     * 
     * @return Raiz del arbol
     **/
    TreeNode * getRoot();

  private:
    //Raiz del arbol
    TreeNode *root;
    //ID actual para el proximo nodo
    int actualID = 0;

    /**
     * Toma la informacion de un json y la convierte en un nuevo nodo
     * 
     * @param json  json con la informacion del nodo
     * @return  Nuevo nodo
     **/
    TreeNode * createNodeFromJson(json json);

    /**
     * Itera la lista de hijos en el json y los convierte en nuevos nodos
     * 
     * @param json json array con la informacion de los hijos
     * @return Nodo raiz de la lista de hijos
     **/
    TreeNode * iterateChilds(json json);

    /**
     * Convierte un nodo a json
     * 
     * @param node Nodo a convertir
     * @return json con la informacion del nodo
     **/
    json convertNode(TreeNode * node);  

    /**
     * Imprime la informacion de un nodo
     * 
     * @param node Nodo a imprimir
     **/
    void printNode(TreeNode * node);

    /**
     * Coloca la informacion de un nodo en una unica linea con el nivel segun los espacios indicados
     * 
     * @param node    Nodo a convertir a string
     * @param spaces  Espacios a agregar al inicio
     * @return string con el formato correcto
     **/
    string nodeToString(TreeNode * node, int spaces);

    bool addNodeAux(int id, TreeNode * root, TreeNode * newNode);
    bool deleteNodeAux(int id, TreeNode * root);
    int totalLeafNodesAux(TreeNode * root);
    int maxLeafsNodesAux(TreeNode * root);
    void onlyOneLeafNodeAux(TreeNode * root);
    int minHeightAux(TreeNode * root, int height);
    int maxHeightAux(TreeNode * root, int height);
    void preorderTransversalAux(TreeNode * root);
    void orderTransversalAux(TreeNode * root);
    string printTreeAux(TreeNode * root, int spaces);

};

#endif