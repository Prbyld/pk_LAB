#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "global.h"

int topId(table tb, mode md) {
	
	if (tb == table::CHARACTER_RELATION || tb == table::ANIME_RELATION) {
		std::cout << "ERROR: wrong table";
		return -1;
	}
	
	std::string metaFileName = "meta.txt";

	std::ifstream meta(metaFileName);

	if (!meta) {
		std::cout << "ERROR: file fail";
		return -1;
	}

	int value = -1;
	std::string temp, key;

	auto getKey = [](const std::string& line) {
		return line.substr(0, line.find(':'));
	};

	auto getValue = [](const std::string& line) {
		return std::stoi(line.substr(line.find(':') + 2, line.size()));
	};

	while (std::getline(meta, temp))
	{
		key = getKey(temp);

		switch (tb) {
			case table::CHARACTER:
				if(key == "topCharId")
					value = getValue(temp);
				break;
			case table::ANIME:
				if (key == "topAnimeId")
					value = getValue(temp);
				break;
			default:
				return -1;
		}
		if (value != -1)
			break; 
	}

	auto valueChange = [getKey, getValue](const std::string& key, const int value, const std::string& fileName) {
		std::ifstream metaIn(fileName);
		if (!metaIn) {
			return;
		}
		std::string mtLine;
		std::vector<std::string> mtVec;
		while (std::getline(metaIn, mtLine)){
			mtVec.push_back(mtLine);
		}
		metaIn.close();
		std::ofstream metaOut(fileName);
		for (auto val : mtVec) {
			if (getKey(val) == key) {
				metaOut << key << ": " << value  << "\n";
			}
			else
			{
				metaOut << val << "\n";
			}
		}
		metaOut.close();
		return;
	};

	switch (md) {
		case mode::GET:
			break;
		case mode::INC:
			valueChange(key, ++value, metaFileName);
			break;
		case mode::DEC:
			valueChange(key, --value, metaFileName);
			break;
		default:
			std::cout << "ERROR: bad mode";
			return -1;
	}
	meta.close();
	return value;
}

