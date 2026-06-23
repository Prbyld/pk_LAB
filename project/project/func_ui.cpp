#include "func_ui.h"
#include "func_db.h"
#include "func_file.h"
#include "class.h"
#include <string>
#include <iostream>

int cmdHandling(std::string& cmd, dataBase& db, CommandHistory& history) {
    if (cmd.empty()) return 0;

    std::string action, params;
    size_t spacePos = cmd.find(" ");

    if (spacePos != std::string::npos) {
        action = cmd.substr(0, spacePos);
        params = cmd.substr(spacePos + 1);
    }
    else {
        action = cmd;
        params = "";
    }

    if (action != "history") {
        history += cmd;
    }

    if (action == "help") {
        std::cout << "=== AVAILABLE COMMANDS ===\n"
            << "  create character [fName] [mName] [lName]\n"
            << "  create anime [name]\n\n"
            << "  update character [ID/Name] [fName|mName|lName|bio] [new_value]\n" 
            << "  update anime [ID/Name] name [new_value]\n" 
            << "  remove character [ID/Name]\n"    
            << "  remove anime [ID/Name]\n\n"  
            << "  connect anime to character [anime] [char] [desc]\n"
            << "  connect character to character [char1] [char2] [desc]\n"
            << "  connect anime to anime [anime1] [anime2] [desc]\n\n"
            << "  show characters [optional: id/name]\n"
            << "  show anime [optional: id/name]\n"
            << "  show relations [optional: char|anime|anime_char] [optional: id/name]\n\n"
            << "  history\n"
            << "  save\n"
            << "  load\n"
            << "  exit\n";
    }
    else if (action == "update") {
        updateData(params, db); 
    }
    else if (action == "remove") {
        removeData(params, db); 
    }
    else if (action == "history") {
        history.printHistory();
    }
    else if (action == "create") {
        create(params, db);
    }
    else if (action == "show") {
        showData(params, db);
    }
    else if (action == "save") {
        saveDb(db);
    }
    else if (action == "load") {
        loadDb(db);
    }
    else if (action == "connect") {
        std::string prefix1 = "anime to character";
        std::string prefix2 = "character to character";
        std::string prefix3 = "anime to anime";

        if (params.compare(0, prefix1.length(), prefix1) == 0) {
            std::string subParams = params.substr(prefix1.length());
            connectCharToAnime(subParams, db);
        }
        else if (params.compare(0, prefix2.length(), prefix2) == 0) {
            std::string subParams = params.substr(prefix2.length());
            connectCharToChar(subParams, db);
        }
        else if (params.compare(0, prefix3.length(), prefix3) == 0) {
            std::string subParams = params.substr(prefix3.length());
            connectAnimeToAnime(subParams, db);
        }
        else {
            std::cout << "ERROR: Unknown connection type.\n";
        }
    }
    else {
        std::cout << "ERROR: Unknown command: " << action << ". Type 'help' for instructions.\n";
    }

    return 1;
}