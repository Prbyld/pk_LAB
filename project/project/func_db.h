#ifndef FUNC_DB_H
#define FUNC_DB_H

#include <string>
#include "global.h"

struct dataBase;

/**
 * @brief Analizuje parametry wejœciowe i tworzy nowy obiekt (postaæ lub anime).
 * @param params Ci¹g tekstowy zawieraj¹cy argumenty tworzenia obiektu.
 * @param db Referencja do g³ównej struktury bazy danych.
 * @return 1 przy sukcesie, 0 dla wywo³ania pomocy, -1 przy b³êdzie parsowania.
 */
int create(std::string& params, dataBase& db);

/**
 * @brief Tworzy i zapisuje powi¹zanie pomiêdzy obiektem Anime a obiektem Character.
 * @param params Ci¹g znaków zwieraj¹cy parametry po³¹czenia (ID anime, ID postaci, opis).
 * @param db Referencja do g³ównej struktury bazy danych.
 * @return 1 przy sukcesie, -1 przy b³êdzie parsowania danych wejœciowych.
 */
int connectCharToAnime(std::string& params, dataBase& db);

/**
 * @brief Tworzy i zapisuje powi¹zanie pomiêdzy dwoma obiektami Character.
 * @param params Ci¹g znaków zawieraj¹cy parametry po³¹czenia (ID postaci 1, ID postaci 2, opis).
 * @param db Referencja do g³ównej struktury bazy danych.
 * @return 1 przy sukcesie, -1 przy b³êdzie parsowania danych wejœciowych.
 */
int connectCharToChar(std::string& params, dataBase& db);

/**
 * @brief Tworzy i zapisuje powi¹zanie pomiêdzy dwoma obiektami Anime.
 * @param params Ci¹g znaków zawieraj¹cy parametry po³¹czenia (ID anime 1, ID anime 2, opis).
 * @param db Referencja do g³ównej struktury bazy danych.
 * @return 1 przy sukcesie, -1 przy b³êdzie parsowania danych wejœciowych.
 */
int connectAnimeToAnime(std::string& params, dataBase& db);

/**
 * @brief Wyœwietla zawartoœæ bazy danych w zale¿noœci od podanych parametrów i filtrów.
 * @param params Typ danych i opcjonalne filtry (np. "relations char 1").
 * @param db Referencja do g³ównej struktury bazy danych.
 * @return 1 przy sukcesie, -1 przy b³êdnym argumencie.
 */
int showData(std::string& params, const dataBase& db);

/**
 * @brief Aktualizuje wybrane pole w istniej¹cym obiekcie (Postaæ/Anime).
 */
int updateData(std::string& params, dataBase& db);

/**
 * @brief Usuwa obiekt z bazy oraz kaskadowo wszystkie powi¹zane z nim relacje.
 */
int removeData(std::string& params, dataBase& db);

#endif