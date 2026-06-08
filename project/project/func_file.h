#pragma once

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

int topId(table tb, mode md);