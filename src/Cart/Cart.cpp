#include "Cart/Cart.h"

Cart::Cart() {}

void Cart::setProducts(List products) {
  this->products = products;
}

List Cart::getProducts() {
  return this->products;
}

void Cart::setPromotion(int promotion) {
  this->promotion = promotion;
}

void Cart::addProduct(string name, int value, int quantity) {
  this->products.add(name, value, quantity);
}

void Cart::deleteAll() {
  List list;
  this->products = list;
}

void Cart::deleteProduct(int index) {
  this->products.remove(index);
}

void Cart::printTotal() {
  int total = 0;
  for(int i = 0; i < this->products.getSize(); i++) {
    total += this->products.getPrice(i) * this->products.getQuantity(i);
  }
  float finalPrice = (float)total - ( (float)total * ( (float)this->promotion / 100 ) );
  cout << "El total de su factura es: " + to_string(finalPrice) << "\n";
}

void Cart::printBill() {
  string result = "Cantidad:  Precio:  Nombre:  \n";
  int total = 0;
  for(int i = 0; i < this->products.getSize(); i++) {
    string product = "";
    string quantity = to_string(this->products.getQuantity(i));
    string price = to_string(this->products.getPrice(i));
    product += quantity + this->formatString(quantity, 11);   
    product += price + this->formatString(price, 9);
    product += this->products.getName(i);
    result += product + "\n";
    total += this->products.getPrice(i) * this->products.getQuantity(i);
  }
  float finalPrice = (float)total - ( (float)total * ( (float)this->promotion / 100 ) );
  result += "-----------------------------\n";
  result += "Descuento: " + to_string(this->promotion) + "\n";
  result += "Subtotal: " + to_string(total) + "\n";
  result += "Total: " + to_string(finalPrice) + "\n";
  cout << result;
}

string Cart::formatString(string text, int spaces) {
  string result = "";
  for(size_t i = text.size(); i < spaces; i++) {
    result += " ";
  }
  return result;
}