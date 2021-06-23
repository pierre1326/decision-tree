#include "Bot/Bot.h"

Bot::Bot() {}

Bot::Bot(Tree tree) {
  this->tree = tree;
  this->actualPosition = tree.getRoot();
}

void Bot::init() {
  while(!this->stop) {
    if(this->actualPosition->child != NULL) {
      cout << this->actualPosition->label << "\n\n";
      int number = 1;
      TreeNode * child = this->actualPosition->child;
      while(child != NULL) {
        cout << to_string(number) + ". " + child->product << "\n";
        number++;
        child = child->next;
      }
      cout << to_string(number) + ". Salir del chatbot" << "\n\n";
      int option;
      cout << "Opcion: ";
      cin >> option;
      cout << "\n";
      this->executeOption(option);
    }
    else {
      this->finalizeOption();
    }
  }
  cout << "Gracias por utilizar el sistema de chatbot. Lamentamos que se vaya :(" << "\n\n";
  this->stop = false;
}

void Bot::executeOption(int option) {
  TreeNode * child = this->actualPosition->child;
  int actualPosition = 1;
  while(child != NULL) {
    if(actualPosition == option) {
      this->actualPosition = child;
      this->buffer.add(this->actualPosition->product, this->actualPosition->value);
      return;
    }
    child = child->next;
    actualPosition++;
  }
  if(option == actualPosition) {
    this->stop = true;
  }
  else {
    cout << "La opcion indicada no existe, por favor intentelo nuevamente" << "\n\n";
  }
}

void Bot::finalizeOption() {
  int operation = this->buffer.getNext()->value;
  switch(operation) {
    case -2:
      this->printBill();
      break;
    case -3:
      this->addProduct();
      break;
    case -4:
      this->deleteProduct();
      break;
    case -5:
      this->applyPromotion();
      break;
    default:
      cout << "Algo salio mal al procesar su solicitud, por favor revise la estructura del arbol." << "\n\n";
      break;
  }
  cout << "Solicitud finalizada. El chatbot se reiniciara para realizar nuevas operaciones." << "\n\n";
  this->actualPosition = this->tree.getRoot();
}

void Bot::deleteProduct() {
  NodeQueue* node = this->buffer.getNext(); 
  int type = node->value;
  switch(type) {
    case 1:
      this->cart.deleteAll();
      cout << "Se eliminaron todos los productos de tu carrito de compras" << "\n\n";
      break;
    default:
      this->deleteOneProduct();
      break;
  }
}

void Bot::deleteOneProduct() {
  List products = this->cart.getProducts();
  if(products.getSize() == 0) {
    cout << "El carrito se encuentra vacio" << "\n\n";
  }
  else {
    int index;
    for(int i = 0; i < products.getSize(); i++) {
      cout << to_string(i + 1) + ". " + products.getName(i) + "\n";
    }
    cout << "\n" << "Indique el producto que sea eliminar: ";
    cin >> index;
    index--;
    cout << "\n";
    if(index >= products.getSize()) {
      cout << "El numero indicado no es valido. No se logro eliminar el producto" << "\n\n";
    }
    else {
      products.remove(index);
      this->cart.setProducts(products);
      cout << "El producto fue eliminado correctamente!" << "\n\n";
    }
  }
}

void Bot::addProduct() {
  int quantity;
  cout << "Indique la cantidad que desea: ";
  cin >> quantity;
  cout << "\n";
  string finalName = "";
  int price = 0;
  for(int i = 0; i <= this->buffer.getSize(); i++) {
    NodeQueue * node = this->buffer.getNext();
    price = node->value;
    finalName += node->product;
    if(i != this->buffer.getSize()) {
      finalName += " - ";
    }
  }
  if(quantity > 0) {
    this->cart.addProduct(finalName, price, quantity);
    cout << "Producto agregado al carrito!" << "\n\n";
  }
  else {
    cout << "La cantidad ingresa no es valida." << "\n\n";
  }
}

void Bot::applyPromotion() {
  NodeQueue* node = this->buffer.getNext(); 
  int type = node->value;
  switch(type) {
    case 1:
      this->cart.setPromotion(10);
      break;
    case 2:
      this->cart.setPromotion(25);
      break;
    default:
      this->cart.setPromotion(50);
      break;
  }
  cout << node->product + " aplicado!" << "\n\n";
}

void Bot::printBill() {
  int type = this->buffer.getNext()->value;
  switch(type) {
    case 1:
      this->cart.printTotal();
      cout << "\n";
      break;
    default:
      this->cart.printBill();
      cout << "\n";
      break;
  }
}