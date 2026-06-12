#include <iostream>
#include <vector>

#include "class.h"
#include "func_db.h"
#include "func_ui.h"
#include "func_file.h"
#include "global.h"

struct dataBase
{
	std::vector<character> character;
	std::vector<anime> anime;
};


int main() {

	std::string cmd;

	while (true) {
		std::cout << "\n>";
		std::getline(std::cin, cmd);
		std::cout << "\n";
		if (cmd == "exit")
			break;
		else
			cmdHandling(cmd);
	}
}