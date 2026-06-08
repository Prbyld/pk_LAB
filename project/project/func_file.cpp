#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

enum table
{
	CHARACTER,
	CHAR,
	ANIME,
	CHARACTER_RELATION,
	CHAR_REL,
	ANIME_REL
};

enum mode
{
	GET,
	INC,
	DEC
};

int topId(table tb, mode md) {
	
	if (tb == CHARACTER_RELATION || tb == CHAR_REL || tb == ANIME_REL) {
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
			case CHAR:
			case CHARACTER:
				if(key == "topCharId")
					value = getValue(temp);
				break;
			case ANIME:
				if (key == "topAnimeId")
					value = getValue(temp);
				break;
			default:
				return -1;
		}
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
		std::ofstream metaOut(fileName);
		for (auto val : mtVec) {
			if (getKey(val) == key) {
				metaOut << key << ": " << getValue(val);
			}
			else
			{
				metaOut << val;
			}
		}
		return;
	};

	switch (md) {
		case GET:
			break;
		case INC:
			valueChange(key, ++value, metaFileName);
			break;
		case DEC:
			valueChange(key, --value, metaFileName);
			break;
		default:
			std::cout << "ERROR: bad mode";
			return -1;
	}
	return value;
}