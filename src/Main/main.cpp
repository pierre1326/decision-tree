#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

#include "GUI/GUI.h"

using namespace std;

int main() {	
	Gui gui("tree.json");
	gui.init();
	return 0;
}