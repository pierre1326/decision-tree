#include "GUI/GUI.h"

Gui::Gui(string path) {
  File file;
  string json = file.load(path);
  Tree tree;
  tree.createTree(json);
  Bot bot(tree);
  this->tree = tree;
  this->file = file;
  this->bot = bot;
  this->path = path;
}

void Gui::init() {
  while(true) {
    int option;
    cout << "1. Ingresar al chatbot" << "\n";
    cout << "2. Agregar nueva opcion de comida" << "\n";
    cout << "3. Eliminar opcion de comida" << "\n";
    cout << "4. Determinar cantidad de nodos hoja del arbol" << "\n";
    cout << "5. Determinar la altura maxima y minima del arbol " << "\n";
    cout << "6. Determinar la cantidad maxima de hijos de nodos padre " << "\n";
    cout << "7. Determinar la cantidad de padres con un solo hijo e imprimir la informacion de esos nodos padres " << "\n";
    cout << "8. Imprimir la informacion completa del arbol en preorden" << "\n";
    cout << "9. Imprimir la informacion completa del arbol en orden" << "\n";
    cout << "10. Imprimir la informacion del archivo completa de forma secuencial" << "\n";
    cout << "11. Imprimir la informacion completa del arbol por cada flujo de informacion  " << "\n";
    cout << "12. Salir del sistema  " << "\n\n";
    cout << "Ingrese el numero de la opcion que desea realizar: ";
    cin >> option;
    cout << "\n";
    if(option == 12) {
      cout << "Saliendo del sistema" << "\n";
      break;
    }
    else {
      this->executeOption(option);
    }
  }
}

void Gui::executeOption(int option) {
  switch(option) {
    case 1:
      this->initBot();
      cout << "\n";
      break;
    case 2:
      this->addNode();
      cout << "\n";
      break;
    case 3:
      this->deleteNode();
      cout << "\n";
      break;
    case 4:
      cout << "Total de hojas en el arbol: " + to_string(this->tree.totalLeafNodes()) << "\n\n";
      break;
    case 5:
      cout << "Altura maxima: " + to_string(this->tree.maxHeight()) + " Altura minima: " + to_string(this->tree.minHeight()) << "\n\n";
      break;
    case 6:
      cout << "Cantidad de hijos: " + to_string(this->tree.maxLeafsNodes()) << "\n\n";
      break;
    case 7:
      this->tree.onlyOneLeafNode();
      cout << "\n";
      break;
    case 8:
      this->tree.preorderTransversal();
      cout << "\n";
      break;
    case 9:
      this->tree.orderTransversal();
      cout << "\n";
      break;
    case 10:
      cout << this->file.load(this->path) << "\n\n";
      break;
    case 11:
      this->tree.printTree();
      cout << "\n";
      break;
    default:
      cout << "La opcion indicada no esta disponible, por favor intentelo nuevamente" << "\n\n";
      break;
  }
}

void Gui::initBot() {
  this->bot.init();
}

void Gui::addNode() {
  string product;
  string pregunta;
  int price;
  int id;
  cout << "Indique el nombre del producto: ";
  cin >> product;
  cout << "\n" << "Indique el precio del producto: ";
  cin >> price;
  cout << "\n" << "Indique la pregunta a mostrar al usuario: ";
  cin >> pregunta;
  cout << "\n\n";
  this->tree.printTree();
  cout << "\n" << "Indique el ID del nodo donde desea colocar el producto (Asegurese que sea dentro del nodo para comidas, de no ser asi puede eliminarlo posteriormente): ";
  cin >> id;
  if(price > 0 && product.size() > 0 && id > 0 && pregunta.size() > 0) {
    bool result = this->tree.addNode(id, pregunta, product, price);
    if(result) {
      this->file.write(this->path, this->tree.convertTree());
      cout << "\n\n" << "El nodo se agrego con exito" << "\n";
    }
    else {
      cout << "\n\n" << "Fallo al agregar el nodo" << "\n";
    }
  }
  else {
    cout << "\n\n" << "La informacion ingresada no es valida, no fue posible agregar el nodo" << "\n";
  }
}

void Gui::deleteNode() {
  int id;
  this->tree.printTree();
  cout << "\n\n";
  cout << "Indique el ID del nodo que quiere eliminar(Aquellos con valor negativo fallaran al intentar borrarse): ";
  cin >> id;
  bool res = this->tree.deleteNode(id);
  if(res) {
    this->file.write(this->path, this->tree.convertTree());
    cout << "\n\n" << "El nodo se elimino con exito" << "\n";
  }
  else {
    cout << "\n\n" << "Fallo al eliminar el nodo o no posee permiso para realizarlo" << "\n";
  }
}