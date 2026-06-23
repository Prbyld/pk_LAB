#ifndef GLOBAL_H
#define GLOBAL_H

/**
 * @enum table
 * @brief Reprezentuje tabele bazodanowe dostêpne w systemie.
 */
enum class table
{
	CHARACTER,
	ANIME,
	CHARACTER_RELATION,
	ANIME_RELATION
};

/**
 * @enum mode
 * @brief Definiuje tryby operacji na licznikach ID (metadanych).
 */
enum class mode
{
	GET,
	INC,
	DEC,
	SET
};


#endif