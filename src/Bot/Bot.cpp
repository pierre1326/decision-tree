#include "Bot/Bot.h"

Bot::Bot(string path) {
  File file;
  string json = file.load(path);
  Tree tree;
  tree.createTree(json);
  Cart cart;
  this->tree = tree;
  this->file = file;
  this->cart = cart;
  this->path = path;
}

void Bot::initBot() {
  while(true) {
    int option;
    cout << "1. Ingresar al chatbot" << "\n";
    cout << "2. Agregar nueva opcione de comida" << "\n";
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

void Bot::executeOption(int option) {
  switch(option) {
    case 1:

      break;
    case 2:
      this->addNode();
      break;
    case 3:
      this->deleteNode();
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

void Bot::addNode() {
  string product;
  int price;
  cout << "Indique el nombre del product: ";
  cin >> product;
  cout << "\n" << "Indique el precio del product: ";
  cin >> price;
  string label = "Que tipo de " + product + " desea?";
  
}

void Bot::deleteNode() {
  
}