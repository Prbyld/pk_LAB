#ifndef CLASS_H
#define CLASS_H

#include <string>
#include "global.h"
#include "func_file.h"

/**
 * @class character
 * @brief Klasa reprezentuj¹ca postaæ w bazie danych.
 */
class character {
public:
    int id;
    std::string fName, mName, lName, bio;

public:
    /**
     * @brief Tworzy postaæ tylko z imieniem.
     * @param fName Imiê postaci.
     */
    character(std::string fName);

    /**
     * @brief Tworzy postaæ z imieniem i nazwiskiem.
     * @param fName Imiê postaci.
     * @param lName Nazwisko postaci.
     */
    character(std::string fName, std::string lName);

    /**
     * @brief Tworzy postaæ z pe³nymi danymi osobowymi.
     * @param fName Imiê postaci.
     * @param mName Drugie imiê postaci.
     * @param lName Nazwisko postaci.
     */
    character(std::string fName, std::string mName, std::string lName);

    /**
     * @brief Destruktor klasy character.
     */
    ~character();
};

/**
 * @class anime
 * @brief Klasa reprezentuj¹ca tytu³ anime w bazie danych.
 */
class anime {
public:
    int id;
    std::string name;

public:
    /**
     * @brief Tworzy nowy obiekt anime.
     * @param name Nazwa serii anime.
     */
    anime(std::string name);

    /**
     * @brief Destruktor klasy anime.
     */
    ~anime();
};

/**
 * @class relation
 * @brief Abstrakcyjna klasa bazowa s³u¿¹ca do modelowania relacji.
 */
class relation {
public:
    int firstObjId;  /**< ID pierwszego obiektu w relacji */
    int secondObjId; /**< ID drugiego obiektu w relacji */
    std::string desc; /**< Opcjonalny opis relacji */

public:
    /**
     * @brief Konstruktor klasy bazowej relacji.
     * @param firstId Identyfikator pierwszego obiektu.
     * @param secondId Identyfikator drugiego obiektu.
     * @param desc Tekstowy opis relacji (domyœlnie pusty).
     */
    relation(int firstId, int secondId, std::string desc = "");

    /**
     * @brief Wirtualny destruktor klasy bazowej.
     */
    virtual ~relation();
};

/**
 * @class charRel
 * @brief Reprezentuje relacjê zachodz¹c¹ pomiêdzy dwoma postaciami (character -> character).
 */
class charRel : public relation {
public:
    /**
     * @brief Konstruktor relacji miêdzy postaciami.
     * @param charId1 ID pierwszej postaci.
     * @param charId2 ID drugiej postaci.
     * @param desc Opis relacji.
     */
    charRel(int charId1, int charId2, std::string desc = "");
    ~charRel() override;
};

/**
 * @class animeCharRel
 * @brief Reprezentuje powi¹zanie postaci z konkretnym anime (anime -> character).
 */
class animeCharRel : public relation {
public:
    /**
     * @brief Konstruktor relacji miêdzy anime a postaci¹.
     * @param animeId ID powi¹zanego anime.
     * @param charId ID powi¹zanej postaci.
     * @param desc Opis roli lub typu powi¹zania.
     */
    animeCharRel(int animeId, int charId, std::string desc = "");
    ~animeCharRel() override;
};

/**
 * @class animeRel
 * @brief Reprezentuje powi¹zanie chronologiczne lub fabularne miêdzy dwoma anime (anime -> anime).
 */
class animeRel : public relation {
public:
    /**
     * @brief Konstruktor relacji miêdzy dwoma tytu³ami anime.
     * @param animeId1 ID pierwszego anime.
     * @param animeId2 ID drugiego anime.
     * @param desc Opis typu relacji (np. sequel).
     */
    animeRel(int animeId1, int animeId2, std::string desc = "");
    ~animeRel() override;
};

/**
 * @struct Node
 * @brief Wêze³ dynamicznej listy jednokierunkowej przechowuj¹cy historiê komend.
 */
struct Node {
    std::string command; /**< Tekst wpisanej komendy */
    Node* next;          /**< WskaŸnik na nastêpny wêze³ */

    Node(std::string cmd) : command(cmd), next(nullptr) {}
};

/**
 * @class CommandHistory
 * @brief Klasa zarz¹dzaj¹ca histori¹ komend za pomoc¹ w³asnej listy dynamicznej.
 * Klasa nie dziedziczy po ¿adnej innej, co spe³nia warunek samodzielnych klas.
 */
class CommandHistory {
private:
    Node* head; /**< WskaŸnik na pocz¹tek listy (najnowsza komenda) */
    int size;   /**< Aktualna liczba elementów w historii */

public:
    /**
     * @brief Konstruktor tworz¹cy pust¹ historiê.
     */
    CommandHistory();

    /**
     * @brief Destruktor zwalniaj¹cy ca³¹ pamiêæ dynamiczn¹ wêz³ów.
     */
    ~CommandHistory();

    /**
     * @brief Przeci¹¿ony operator += do dodawania nowej komendy na pocz¹tek listy.
     * @param cmd Tekst komendy do dodania.
     * @return Referencja do obiektu historii.
     */
    CommandHistory& operator+=(const std::string& cmd);

    /**
     * @brief Wyœwietla ca³¹ historiê komend od najnowszej do najstarszej.
     */
    void printHistory() const;
};

#endif