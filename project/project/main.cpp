#include <iostream>
#include <vector>
#include <string>

#include "class.h"
#include "func_db.h"
#include "func_ui.h"
#include "func_file.h"
#include "global.h"

struct dataBase {
    std::vector<character> character;
    std::vector<anime> anime;
    std::vector<charRel> charRelations;
    std::vector<animeCharRel> animeCharRelations;
    std::vector<animeRel> animeRelations;
};

int main() {
    dataBase db;
    CommandHistory history;
    std::string cmd;

    loadDb(db);

    std::cout << "=== Anime & Character Database System ===\n";
    std::cout << "Type 'help' to see the list of available commands.\n";

    while (true) {
        std::cout << "\n>";
        if (!std::getline(std::cin, cmd)) break;

        if (cmd == "exit") {
            std::string saveConf;
            std::cout << "\nDo you want to save (y/n)";
            std::cin >> saveConf;
            if (saveConf == "y")
                saveDb(db);
            break;
        }
        else {
            cmdHandling(cmd, db, history);
        }
    }
    return 0;
}