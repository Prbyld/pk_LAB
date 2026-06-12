/// @file

#ifndef FUNC_FILE_H
#define FUNC_FILE_H

#include "global.h"

/** podaje zapisane wartosci dal najwiekszych id
* @param tb tablica do sprawdzenia (tylko character, char, i anime sa operowane)
* @param md tryb operacji (get - czytaj, inc - inkrementuj, dec - dekrementuj)
* @return maks id po wykonaniu funkcji
*/
int topId(table tb, mode md);

int saveDb();

int loadDb();

int getChar();

int getAnime();


#endif