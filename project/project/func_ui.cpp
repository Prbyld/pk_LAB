#include <string>
#include <iostream>

#include "func_db.h"

int cmdHandling(std::string& cmd) {
	std::string action, params;
	if (cmd.find(" ") != std::string::npos) {
		action = cmd.substr(0, cmd.find(" "));
		params = cmd.substr(cmd.find(" ")+1, cmd.length() - 1);
	}
	else {
		action = cmd;
		params = "";
	}

	if(action == "create")
		create(params);
	if (action == "connect") {
		std::string temp = params.substr(0, temp.find("", 0, 2));
		if (temp == "anime to character") {
			std::cout << "a to c";
		}
		if (temp == "character to character")
			std::cout << "c to c";

	}
	return 1;
}
