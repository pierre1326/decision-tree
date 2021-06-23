#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

#include "Bot/Bot.h"

using namespace std;

int main() {	
	Bot bot("tree.json");
	bot.initBot();
	return 0;
}