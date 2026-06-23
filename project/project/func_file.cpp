#include "func_file.h"
#include "class.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct dataBase {
    std::vector<character> character;
    std::vector<anime> anime;
    std::vector<charRel> charRelations;
    std::vector<animeCharRel> animeCharRelations;
    std::vector<animeRel> animeRelations;
};

int topId(table tb, mode md, int explicitValue) {
    if (tb == table::CHARACTER_RELATION || tb == table::ANIME_RELATION) {
        std::cout << "ERROR: wrong table\n";
        return -1;
    }

    std::string metaFileName = "meta.txt";
    std::ifstream meta(metaFileName);

    if (!meta) {
        std::ofstream createMeta(metaFileName);
        createMeta << "topCharId: 0\ntopAnimeId: 0\n";
        createMeta.close();
        meta.open(metaFileName);
    }

    int value = -1;
    std::string temp, key;

    auto getKey = [](const std::string& line) {
        return line.substr(0, line.find(':'));
        };

    auto getValue = [](const std::string& line) {
        return std::stoi(line.substr(line.find(':') + 2, line.size()));
        };

    while (std::getline(meta, temp))
    {
        key = getKey(temp);

        switch (tb) {
        case table::CHARACTER:
            if (key == "topCharId")
                value = getValue(temp);
            break;
        case table::ANIME:
            if (key == "topAnimeId")
                value = getValue(temp);
            break;
        default:
            return -1;
        }
        if (value != -1)
            break;
    }

    auto valueChange = [getKey, getValue](const std::string& key, const int value, const std::string& fileName) {
        std::ifstream metaIn(fileName);
        if (!metaIn) return;
        std::string mtLine;
        std::vector<std::string> mtVec;
        while (std::getline(metaIn, mtLine)) {
            mtVec.push_back(mtLine);
        }
        metaIn.close();
        std::ofstream metaOut(fileName);
        for (auto val : mtVec) {
            if (getKey(val) == key) {
                metaOut << key << ": " << value << "\n";
            }
            else {
                metaOut << val << "\n";
            }
        }
        metaOut.close();
        };

    switch (md) {
    case mode::GET:
        break;
    case mode::INC:
        valueChange(key, ++value, metaFileName);
        break;
    case mode::DEC:
        valueChange(key, --value, metaFileName);
        break;
    case mode::SET:
        value = explicitValue;
        valueChange(key, value, metaFileName);
        break;
    default:
        std::cout << "ERROR: bad mode\n";
        return -1;
    }
    meta.close();
    return value;
}

int saveDb(const dataBase& db) {
    std::ofstream fChar("characters.txt");
    for (const auto& c : db.character) {
        fChar << c.id << ";" << c.fName << ";" << c.mName << ";" << c.lName << ";" << c.bio << ";\n";
    }
    fChar.close();

    std::ofstream fAnime("anime.txt");
    for (const auto& a : db.anime) {
        fAnime << a.id << ";" << a.name << ";\n";
    }
    fAnime.close();

    std::ofstream fCharRel("char_relations.txt");
    for (const auto& r : db.charRelations) {
        fCharRel << r.firstObjId << ";" << r.secondObjId << ";" << r.desc << ";\n";
    }
    fCharRel.close();

    std::ofstream fAnimeCharRel("anime_char_relations.txt");
    for (const auto& r : db.animeCharRelations) {
        fAnimeCharRel << r.firstObjId << ";" << r.secondObjId << ";" << r.desc << ";\n";
    }
    fAnimeCharRel.close();

    std::ofstream fAnimeRel("anime_relations.txt");
    for (const auto& r : db.animeRelations) {
        fAnimeRel << r.firstObjId << ";" << r.secondObjId << ";" << r.desc << ";\n";
    }
    fAnimeRel.close();

    std::cout << "Database saved successfully.\n";
    return 1;
}

int loadDb(dataBase& db) {
    db.character.clear();
    db.anime.clear();
    db.charRelations.clear();
    db.animeCharRelations.clear();
    db.animeRelations.clear();

    std::string line;
    int maxCharId = 0;
    int maxAnimeId = 0;

    auto parseLine = [](const std::string& inputLine, size_t minFields) {
        std::vector<std::string> fields;
        if (inputLine.empty()) return fields;

        std::stringstream ss(inputLine);
        std::string cell;
        while (std::getline(ss, cell, ';')) {
            fields.push_back(cell);
        }
        while (fields.size() < minFields) {
            fields.push_back("");
        }
        return fields;
        };

    std::ifstream fChar("characters.txt");
    while (fChar && std::getline(fChar, line)) {
        auto fields = parseLine(line, 5);
        if (fields.empty()) continue;

        character c("");
        c.id = std::stoi(fields[0]);
        c.fName = fields[1];
        c.mName = fields[2];
        c.lName = fields[3];
        c.bio = fields[4];

        if (c.id > maxCharId) maxCharId = c.id;
        db.character.push_back(c);
    }
    fChar.close();

    std::ifstream fAnime("anime.txt");
    while (fAnime && std::getline(fAnime, line)) {
        auto fields = parseLine(line, 2);
        if (fields.empty()) continue;

        anime a("");
        a.id = std::stoi(fields[0]);
        a.name = fields[1];

        if (a.id > maxAnimeId) maxAnimeId = a.id;
        db.anime.push_back(a);
    }
    fAnime.close();

    std::ifstream fCharRel("char_relations.txt");
    while (fCharRel && std::getline(fCharRel, line)) {
        auto fields = parseLine(line, 3);
        if (fields.empty()) continue;
        db.charRelations.push_back(charRel(std::stoi(fields[0]), std::stoi(fields[1]), fields[2]));
    }
    fCharRel.close();

    std::ifstream fAnimeCharRel("anime_char_relations.txt");
    while (fAnimeCharRel && std::getline(fAnimeCharRel, line)) {
        auto fields = parseLine(line, 3);
        if (fields.empty()) continue;
        db.animeCharRelations.push_back(animeCharRel(std::stoi(fields[0]), std::stoi(fields[1]), fields[2]));
    }
    fAnimeCharRel.close();

    std::ifstream fAnimeRel("anime_relations.txt");
    while (fAnimeRel && std::getline(fAnimeRel, line)) {
        auto fields = parseLine(line, 3);
        if (fields.empty()) continue;
        db.animeRelations.push_back(animeRel(std::stoi(fields[0]), std::stoi(fields[1]), fields[2]));
    }
    fAnimeRel.close();

    topId(table::CHARACTER, mode::SET, maxCharId);
    topId(table::ANIME, mode::SET, maxAnimeId);

    std::cout << "Database loaded successfully. Counters updated (Max Char ID: "
        << maxCharId << ", Max Anime ID: " << maxAnimeId << ").\n";
    return 1;
}