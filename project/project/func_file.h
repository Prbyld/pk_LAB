#ifndef FUNC_FILE_H
#define FUNC_FILE_H

#include "global.h"

struct dataBase;

/**
 * @brief Pobiera, aktualizuje lub ustawia najwy¿sze ID w pliku metadanych bazy.
 * @param tb Typ tabeli, dla której operujemy na ID.
 * @param md Tryb operacji (GET, INC, DEC, SET).
 * @param explicitValue Wartoœæ do wymuszenia (u¿ywana tylko z trybem SET).
 * @return Wartoœæ ID po wykonaniu operacji.
 */
int topId(table tb, mode md, int explicitValue = -1);

/**
 * @brief Zapisuje aktualny stan ca³ej bazy danych (obiekty i relacje) do plików tekstowych.
 * @param db Referencja do struktury bazy danych przeznaczonej do zapisu.
 * @return Wartoœæ 1 przy powodzeniu, -1 w przypadku b³êdu zapisu plików.
 */
int saveDb(const dataBase& db);

/**
 * @brief Wczytuje stan bazy danych (obiekty i relacje) z zewnêtrznych plików tekstowych.
 * @param db Referencja do struktury bazy danych, do której zostan¹ za³adowane dane.
 * @return Wartoœæ 1 przy powodzeniu, -1 w przypadku b³êdu odczytu.
 */
int loadDb(dataBase& db);

#endif