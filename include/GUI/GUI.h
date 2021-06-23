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
    Gui(string path);
    void init();

  private:
    Tree tree;
    Bot bot;
    File file;
    string path;

    void executeOption(int option);
    void addNode();
    void deleteNode();
    void initBot();

};

#endif