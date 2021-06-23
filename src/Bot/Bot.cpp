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
      this->buffer.add(this->actualPosition->product, this->actualPosition->value, 0);
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
  //TODO
  cout << "Solicitud finalizada. El chatbot se reiniciara para realizar nuevas operaciones." << "\n\n";
  this->actualPosition = this->tree.getRoot();
}