/// @file

#ifndef CLASS_H
#define CLASS_H

#include <string>

#include "global.h"
#include "func_file.h"

class character {
	int id;
	std::string fName, mName, lName, bio;
	
public:
	character(std::string fName) 
		:fName(fName), id(topId(table::CHARACTER, mode::INC)) {};

	character(std::string fName, std::string lName) 
		:fName(fName), lName(lName), id(topId(table::CHARACTER, mode::INC)) { };

	character(std::string fName, std::string mName, std::string lName) 
		:fName(fName), mName(mName), lName(lName), id(topId(table::CHARACTER, mode::INC)) {};

	~character();
};

class anime
{
	int id;
	std::string name;

public:
	anime(std::string name) 
		:name(name), id(topId(table::ANIME, mode::INC)) {};

	~anime();

};

class relation
{
	int firstObjId, secoundObjId;
	std::string desc;
public:
	relation();
	~relation();

};

//	charRel : relation
//	animeCharRel : relation
//	animeRel : relation

#endif


