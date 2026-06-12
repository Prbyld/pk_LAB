#include <string>
#include <iostream>

int create(std::string& params) {
	if (params == "" || params == "help")
		std::cout << "create [Object] [parameters]\n\tobject -> character/anime, type of object you want to create.\n\tparameters -> values to use when creating object.";
	return 1;
}