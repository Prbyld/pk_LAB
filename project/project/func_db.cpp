#include "func_db.h"
#include "class.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

struct dataBase {
    std::vector<character> character;
    std::vector<anime> anime;
    std::vector<charRel> charRelations;
    std::vector<animeCharRel> animeCharRelations;
    std::vector<animeRel> animeRelations;
};

std::vector<std::string> parseArguments(const std::string& paramsStr) {
    std::vector<std::string> args;
    std::string current;
    bool inQuotes = false;

    for (size_t i = 0; i < paramsStr.length(); ++i) {
        char c = paramsStr[i];
        if (c == '"') {
            inQuotes = !inQuotes;
        }
        else if (c == ' ' && !inQuotes) {
            if (!current.empty()) {
                args.push_back(current);
                current.clear();
            }
        }
        else {
            current += c;
        }
    }
    if (!current.empty()) {
        args.push_back(current);
    }
    return args;
}

bool isNumber(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

int findCharacterId(const std::string& identifier, const dataBase& db) {
    if (isNumber(identifier)) {
        return std::stoi(identifier);
    }
    for (const auto& c : db.character) {
        std::string fullName = c.fName;
        if (!c.mName.empty()) fullName += " " + c.mName;
        if (!c.lName.empty()) fullName += " " + c.lName;

        if (fullName == identifier || c.fName == identifier) {
            return c.id;
        }
    }
    return -1;
}

int findAnimeId(const std::string& identifier, const dataBase& db) {
    if (isNumber(identifier)) {
        return std::stoi(identifier);
    }
    for (const auto& a : db.anime) {
        if (a.name == identifier) {
            return a.id;
        }
    }
    return -1;
}

int create(std::string& params, dataBase& db) {
    std::vector<std::string> args = parseArguments(params);

    if (args.empty() || args[0] == "help") {
        std::cout << "Usage: create [character|anime] [parameters...]\n"
            << "\tcharacter \"[fName]\" \"[optional: mName]\" \"[optional: lName]\"\n"
            << "\tanime \"[name]\"\n";
        return 0;
    }

    std::string type = args[0];

    if (type == "character") {
        if (args.size() < 2) {
            std::cout << "ERROR: Character needs at least a first name.\n";
            return -1;
        }
        if (args.size() == 2) {
            db.character.push_back(character(args[1]));
            std::cout << "Character created: " << args[1] << "\n";
        }
        else if (args.size() == 3) {
            db.character.push_back(character(args[1], args[2]));
            std::cout << "Character created: " << args[1] << " " << args[2] << "\n";
        }
        else if (args.size() >= 4) {
            db.character.push_back(character(args[1], args[2], args[3]));
            std::cout << "Character created: " << args[1] << " " << args[2] << " " << args[3] << "\n";
        }
    }
    else if (type == "anime") {
        if (args.size() < 2) {
            std::cout << "ERROR: Anime needs a name.\n";
            return -1;
        }
        db.anime.push_back(anime(args[1]));
        std::cout << "Anime created: " << args[1] << "\n";
    }
    return 1;
}

int connectCharToAnime(std::string& params, dataBase& db) {
    std::vector<std::string> args = parseArguments(params);
    if (args.size() < 2) {
        std::cout << "ERROR: Usage: connect anime to character \"[anime ID/Name]\" \"[char ID/Name]\" \"[optional: desc]\"\n";
        return -1;
    }

    int animeId = findAnimeId(args[0], db);
    int charId = findCharacterId(args[1], db);

    if (animeId == -1 || charId == -1) {
        std::cout << "ERROR: Could not find Anime (" << args[0] << ") or Character (" << args[1] << ")\n";
        return -1;
    }

    std::string desc = (args.size() >= 3) ? args[2] : "";
    db.animeCharRelations.push_back(animeCharRel(animeId, charId, desc));
    std::cout << "Connected Anime [ID: " << animeId << "] with Character [ID: " << charId << "]\n";
    return 1;
}

int connectCharToChar(std::string& params, dataBase& db) {
    std::vector<std::string> args = parseArguments(params);
    if (args.size() < 2) {
        std::cout << "ERROR: Usage: connect character to character \"[char1 ID/Name]\" \"[char2 ID/Name]\" \"[optional: desc]\"\n";
        return -1;
    }

    int charId1 = findCharacterId(args[0], db);
    int charId2 = findCharacterId(args[1], db);

    if (charId1 == -1 || charId2 == -1) {
        std::cout << "ERROR: One or both characters not found.\n";
        return -1;
    }

    std::string desc = (args.size() >= 3) ? args[2] : "";
    db.charRelations.push_back(charRel(charId1, charId2, desc));
    std::cout << "Connected Character [ID: " << charId1 << "] with Character [ID: " << charId2 << "]\n";
    return 1;
}

int connectAnimeToAnime(std::string& params, dataBase& db) {
    std::vector<std::string> args = parseArguments(params);
    if (args.size() < 2) {
        std::cout << "ERROR: Usage: connect anime to anime \"[anime1 ID/Name]\" \"[anime2 ID/Name]\" \"[optional: desc]\"\n";
        return -1;
    }

    int animeId1 = findAnimeId(args[0], db);
    int animeId2 = findAnimeId(args[1], db);

    if (animeId1 == -1 || animeId2 == -1) {
        std::cout << "ERROR: One or both anime titles not found.\n";
        return -1;
    }

    std::string desc = (args.size() >= 3) ? args[2] : "";
    db.animeRelations.push_back(animeRel(animeId1, animeId2, desc));
    std::cout << "Connected Anime [ID: " << animeId1 << "] with Anime [ID: " << animeId2 << "]\n";
    return 1;
}

int updateData(std::string& params, dataBase& db) {
    std::vector<std::string> args = parseArguments(params);

    if (args.size() < 4) {
        std::cout << "ERROR: Usage: update [character|anime] \"[ID/Name]\" [field] \"[new_value]\"\n"
            << "\tAvailable character fields: fName, mName, lName, bio\n"
            << "\tAvailable anime fields: name\n";
        return -1;
    }

    std::string type = args[0];
    std::string identifier = args[1];
    std::string field = args[2];
    std::string newValue = args[3];

    if (type == "character") {
        int targetId = findCharacterId(identifier, db);
        if (targetId == -1) {
            std::cout << "ERROR: Character '" << identifier << "' not found.\n";
            return -1;
        }

        for (auto& c : db.character) {
            if (c.id == targetId) {
                if (field == "fName") c.fName = newValue;
                else if (field == "mName") c.mName = newValue;
                else if (field == "lName") c.lName = newValue;
                else if (field == "bio") c.bio = newValue;
                else {
                    std::cout << "ERROR: Invalid field '" << field << "' for character.\n";
                    return -1;
                }
                std::cout << "Character ID " << targetId << " updated successfully.\n";
                return 1;
            }
        }
    }
    else if (type == "anime") {
        int targetId = findAnimeId(identifier, db);
        if (targetId == -1) {
            std::cout << "ERROR: Anime '" << identifier << "' not found.\n";
            return -1;
        }

        for (auto& a : db.anime) {
            if (a.id == targetId) {
                if (field == "name") {
                    a.name = newValue;
                    std::cout << "Anime ID " << targetId << " updated successfully.\n";
                    return 1;
                }
                else {
                    std::cout << "ERROR: Invalid field '" << field << "' for anime.\n";
                    return -1;
                }
            }
        }
    }
    else {
        std::cout << "ERROR: Unknown type '" << type << "'. Use 'character' or 'anime'.\n";
    }
    return -1;
}

int removeData(std::string& params, dataBase& db) {
    std::vector<std::string> args = parseArguments(params);

    if (args.size() < 2) {
        std::cout << "ERROR: Usage: remove [character|anime] \"[ID/Name]\"\n";
        return -1;
    }

    std::string type = args[0];
    std::string identifier = args[1];

    if (type == "character") {
        int targetId = findCharacterId(identifier, db);
        if (targetId == -1) {
            std::cout << "ERROR: Character not found.\n";
            return -1;
        }

        auto it = std::remove_if(db.character.begin(), db.character.end(),
            [targetId](const character& c) { return c.id == targetId; });

        if (it != db.character.end()) {
            db.character.erase(it, db.character.end());
            std::cout << "Character ID " << targetId << " removed.\n";

            auto r1 = std::remove_if(db.charRelations.begin(), db.charRelations.end(),
                [targetId](const charRel& r) { return r.firstObjId == targetId || r.secondObjId == targetId; });
            db.charRelations.erase(r1, db.charRelations.end());

            auto r2 = std::remove_if(db.animeCharRelations.begin(), db.animeCharRelations.end(),
                [targetId](const animeCharRel& r) { return r.secondObjId == targetId; });
            db.animeCharRelations.erase(r2, db.animeCharRelations.end());

            std::cout << "Cascaded relations cleaned up.\n";
            return 1;
        }
    }
    else if (type == "anime") {
        int targetId = findAnimeId(identifier, db);
        if (targetId == -1) {
            std::cout << "ERROR: Anime not found.\n";
            return -1;
        }

        auto it = std::remove_if(db.anime.begin(), db.anime.end(),
            [targetId](const anime& a) { return a.id == targetId; });

        if (it != db.anime.end()) {
            db.anime.erase(it, db.anime.end());
            std::cout << "Anime ID " << targetId << " removed.\n";

            auto r1 = std::remove_if(db.animeRelations.begin(), db.animeRelations.end(),
                [targetId](const animeRel& r) { return r.firstObjId == targetId || r.secondObjId == targetId; });
            db.animeRelations.erase(r1, db.animeRelations.end());

            auto r2 = std::remove_if(db.animeCharRelations.begin(), db.animeCharRelations.end(),
                [targetId](const animeCharRel& r) { return r.firstObjId == targetId; });
            db.animeCharRelations.erase(r2, db.animeCharRelations.end());

            std::cout << "Cascaded relations cleaned up.\n";
            return 1;
        }
    }
    else {
        std::cout << "ERROR: Unknown type. Use 'character' or 'anime'.\n";
    }
    return -1;
}

int showData(std::string& params, const dataBase& db) {
    std::vector<std::string> args = parseArguments(params);
    if (args.empty()) return -1;

    std::string mainType = args[0];

    auto getCharName = [&db](int id) {
        for (const auto& c : db.character) {
            if (c.id == id) {
                std::string full = c.fName;
                if (!c.mName.empty()) full += " " + c.mName;
                if (!c.lName.empty()) full += " " + c.lName;
                return full;
            }
        }
        return std::string("Unknown Character");
        };

    auto getAnimeName = [&db](int id) {
        for (const auto& a : db.anime) {
            if (a.id == id) return a.name;
        }
        return std::string("Unknown Anime");
        };

    if (mainType == "characters") {
        int targetId = -1;
        if (args.size() >= 2) {
            targetId = findCharacterId(args[1], db);
        }

        std::cout << "=== CHARACTERS LIST ===\n";
        int count = 0;
        for (const auto& c : db.character) {
            if (args.size() < 2 || c.id == targetId) {
                std::cout << "[" << c.id << "] " << c.fName;
                if (!c.mName.empty()) std::cout << " " << c.mName;
                if (!c.lName.empty()) std::cout << " " << c.lName;
                if (!c.bio.empty()) std::cout << " (Bio: " << c.bio << ")";
                std::cout << "\n";
                count++;
            }
        }
        if (count == 0 && args.size() >= 2) std::cout << "Character '" << args[1] << "' not found.\n";
    }
    else if (mainType == "anime") {
        int targetId = -1;
        if (args.size() >= 2) {
            targetId = findAnimeId(args[1], db);
        }

        std::cout << "=== ANIME LIST ===\n";
        int count = 0;
        for (const auto& a : db.anime) {
            if (args.size() < 2 || a.id == targetId) {
                std::cout << "[" << a.id << "] " << a.name << "\n";
                count++;
            }
        }
        if (count == 0 && args.size() >= 2) std::cout << "Anime '" << args[1] << "' not found.\n";
    }
    else if (mainType == "relations") {
        std::string subType = (args.size() >= 2) ? args[1] : "";

        int targetId = -1;
        if (args.size() >= 3 && subType != "anime_char") {
            targetId = findCharacterId(args[2], db);
            if (targetId == -1) {
                targetId = findAnimeId(args[2], db);
            }
        }

        bool showAll = subType.empty();
        std::cout << "=== RELATIONS LIST ===\n";

        if (showAll || subType == "char") {
            std::cout << "  -- Character to Character --\n";
            for (const auto& r : db.charRelations) {
                if (targetId == -1 || r.firstObjId == targetId || r.secondObjId == targetId) {
                    std::cout << "  [" << r.firstObjId << "] " << getCharName(r.firstObjId)
                        << " <-> [" << r.secondObjId << "] " << getCharName(r.secondObjId);
                    if (!r.desc.empty()) std::cout << " | " << r.desc;
                    std::cout << "\n";
                }
            }
        }

        if (showAll || subType == "anime_char") {
            std::cout << "  -- Anime to Character --\n";

            int targetAnimeId = -1;
            int targetCharId = -1;
            bool filterApplied = false;

            if (args.size() >= 5 && args[2] == "by") {
                std::string searchType = args[3];
                std::string searchKey = args[4];

                if (searchType == "anime") {
                    targetAnimeId = findAnimeId(searchKey, db);
                    filterApplied = true;
                    if (targetAnimeId != -1) {
                        std::cout << "[Filter: Searching explicitly BY ANIME '" << searchKey << "' (ID: " << targetAnimeId << ")]\n";
                    }
                    else {
                        std::cout << "[Filter: Anime '" << searchKey << "' not found.]\n";
                    }
                }
                else if (searchType == "character") {
                    targetCharId = findCharacterId(searchKey, db);
                    filterApplied = true;
                    if (targetCharId != -1) {
                        std::cout << "[Filter: Searching explicitly BY CHARACTER '" << searchKey << "' (ID: " << targetCharId << ")]\n";
                    }
                    else {
                        std::cout << "[Filter: Character '" << searchKey << "' not found.]\n";
                    }
                }
                else {
                    std::cout << "ERROR: Invalid search type '" << searchType << "'. Use 'by anime' or 'by character'.\n";
                    return -1;
                }
            }
            else if (args.size() >= 3) {
                std::cout << "ERROR: To filter anime_char, use syntax: show relations anime_char by [anime|character] \"[Name]\"\n";
                return -1;
            }

            int count = 0;
            for (const auto& r : db.animeCharRelations) {
                bool matchAnime = (targetAnimeId != -1 && r.firstObjId == targetAnimeId);
                bool matchChar = (targetCharId != -1 && r.secondObjId == targetCharId);

                if (!filterApplied || matchAnime || matchChar) {
                    std::cout << "  [" << r.firstObjId << "] " << getAnimeName(r.firstObjId)
                        << " <-> [" << r.secondObjId << "] " << getCharName(r.secondObjId);
                    if (!r.desc.empty()) std::cout << " | Description: " << r.desc;
                    std::cout << "\n";
                    count++;
                }
            }

            if (count == 0) {
                std::cout << "  No matching Anime-Character relations found.\n";
            }
        }

        if (showAll || subType == "anime") {
            std::cout << "  -- Anime to Anime --\n";
            for (const auto& r : db.animeRelations) {
                if (targetId == -1 || r.firstObjId == targetId || r.secondObjId == targetId) {
                    std::cout << "  [" << r.firstObjId << "] " << getAnimeName(r.firstObjId)
                        << " <-> [" << r.secondObjId << "] " << getAnimeName(r.secondObjId);
                    if (!r.desc.empty()) std::cout << " | " << r.desc;
                    std::cout << "\n";
                }
            }
        }
    }
    return 1;
}