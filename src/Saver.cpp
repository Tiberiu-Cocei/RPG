#include "Saver.h"

Saver::Saver() {}

bool Saver::save_game(int levelNumber, int coordinates, Level* level, PlayerStats* playerStats, Equipment* equipment,
                      Inventory* inventory, std::vector<Perk*> playerPerks, Bracelet bracelet, std::string file) {
    std::string fileName = "../../saves/" + file + ".txt";
    std::ofstream saveFile(fileName);
    std::string saveData;
    saveData += "1\n" + std::to_string(levelNumber) + " " + std::to_string(coordinates) + "\n";
    level->get_save_data(saveData);
    playerStats->get_save_data(saveData);
    equipment->get_save_data(saveData);
    inventory->get_save_data(saveData);
    saveData += "6\n";
    if(playerPerks.size() == 0) {
        saveData += "03\n";
    }
    else {
        for(auto perk : playerPerks) {
            perk->get_save_data(saveData);
        }
        saveData += "\n";
    }
    bracelet.get_save_data(saveData);
    saveFile << saveData;
    saveFile.close();
    return true;
}

Saver::~Saver() {}
