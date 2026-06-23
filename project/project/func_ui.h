#ifndef FUNC_UI_H
#define FUNC_UI_H

#include <string>

struct dataBase;
class CommandHistory;

/**
 * @brief G³ówny parser interfejsu tekstowego u¿ytkownika. Rozpoznaje i wywo³uje akcje.
 * @param cmd Pe³na linia komendy wpisana przez u¿ytkownika w konsoli.
 * @param db Referencja do g³ównej struktury bazy danych, na której operuj¹ komendy.
 * @return Status wykonania polecenia.
 */
int cmdHandling(std::string& cmd, dataBase& db, CommandHistory& history);

#endif