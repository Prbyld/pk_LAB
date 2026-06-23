#include <iostream>
#include "class.h"

character::character(std::string fName)
    : fName(fName), id(topId(table::CHARACTER, mode::INC)) {
}

character::character(std::string fName, std::string lName)
    : fName(fName), lName(lName), id(topId(table::CHARACTER, mode::INC)) {
}

character::character(std::string fName, std::string mName, std::string lName)
    : fName(fName), mName(mName), lName(lName), id(topId(table::CHARACTER, mode::INC)) {
}

character::~character() {}

anime::anime(std::string name)
    : name(name), id(topId(table::ANIME, mode::INC)) {
}

anime::~anime() {}

relation::relation(int firstId, int secondId, std::string desc)
    : firstObjId(firstId), secondObjId(secondId), desc(desc) {
}

relation::~relation() {}

charRel::charRel(int charId1, int charId2, std::string desc)
    : relation(charId1, charId2, desc) {
}

charRel::~charRel() {}

animeCharRel::animeCharRel(int animeId, int charId, std::string desc)
    : relation(animeId, charId, desc) {
}

animeCharRel::~animeCharRel() {}

animeRel::animeRel(int animeId1, int animeId2, std::string desc)
    : relation(animeId1, animeId2, desc) {
}

animeRel::~animeRel() {}

CommandHistory::CommandHistory() : head(nullptr), size(0) {}

CommandHistory::~CommandHistory() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

CommandHistory& CommandHistory::operator+=(const std::string& cmd) {
    Node* newNode = new Node(cmd); 
    newNode->next = head;          
    head = newNode;
    size++;
    return *this;
}

void CommandHistory::printHistory() const {
    std::cout << "=== COMMAND HISTORY ===\n";
    if (head == nullptr) {
        std::cout << "History is empty.\n";
        return;
    }
    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        std::cout << "  " << index++ << ". " << current->command << "\n";
        current = current->next;
    }
}