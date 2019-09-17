#include "Loader.h"

Loader::Loader() {}

void Loader::show_save_files() {
    DIR *dir;
    struct dirent *ent;
    dir = opendir("../../saves/");
    int i = 0;
    std::cout<<"\n";
    while ((ent = readdir (dir)) != NULL) {
        if(++i > 2) {
            std::cout << i-2 << " - " << ent->d_name<<"\n";
        }
    }
    closedir (dir);
}

bool Loader::check_file_name(std::string fileName) {
    std::fstream fileStream;
    std::string fullPath = "../../saves/" + fileName;
    fileStream.open(fullPath);
    if(fileStream.fail()) {
        return false;
    }
    return true;
}

bool Loader::load_game(int& levelNumber, int& coordinates, Level*& level, PlayerStats*& playerStats, Equipment*& equipment,
                      Inventory*& inventory, std::vector<Perk*>& playerPerks, Bracelet& bracelet, std::string fileName) {
    std::string fullPath = "../../saves/" + fileName;
    std::ifstream saveFile(fullPath);
    std::string line;
    int lineNr = 0;
    while(std::getline(saveFile, line)) {
        ++lineNr;
        std::istringstream iss(line);
        switch(lineNr) {
            case 2 :
            {
                int a, b;
                if(!(iss >> a >> b)) {
                    return false;
                }
                else {
                    levelNumber = a;
                    coordinates = b;
                    LevelList levelList = LevelList();
                    delete level;
                    level = levelList.get_level(levelNumber);
                }
            }
            break;
            case 4 :
            {
                bool a, b, c, d, e, f;
                if(!(iss >> a >> b >> c >> d >> e >> f)) {
                    return false;
                }
                else {
                    level->load_booleans(a, b, c, d, e, f);
                }
            }
            break;
            case 5 :
            {
                 std::array<char, 225> userMap;
                 char position;
                 int positionCount = -1;
                 while(iss >> position) {
                    if(position != '_') {
                        userMap.at(++positionCount) = position;
                    }
                    else {
                        userMap.at(++positionCount) = ' ';
                    }
                 }
                 if(positionCount != 224) {
                    return false;
                 }
                 else {
                    level->load_user_map(userMap);
                 }
            }
            break;
            case 7 :
            {
                int a, b, c, d, e, f, g;
                if(!(iss >> a >> b >> c >> d >> e >> f >> g)) {
                    return false;
                }
                else {
                    playerStats->load_persistent_stats(a, b, c, d, e, f, g);
                }
            }
            break;
            case 8 :
            {
                int a, b, c, d, e, f;
                if(!(iss >> a >> b >> c >> d >> e >> f)) {
                    return false;
                }
                else {
                    playerStats->modify_temp_stats(a, b, c, d, e, f);
                }
            }
            break;
            case 9 :
            {
                int a, b;
                if(!(iss >> a >> b)) {
                    return false;
                }
                else {
                    playerStats->load_damage_extras(a, b);
                }
            }
            break;
            case 10 :
            {
                int a, b, c, d, e, f;
                if(!(iss >> a >> b >> c >> d >> e >> f)) {
                    return false;
                }
                else {
                    playerStats->load_extra_stats(a, b, c, d, e, f);
                }
            }
            break;
            case 11 :
            {
                bool attunedPerks[10];
                int perkCount = -1;
                bool perk;
                while(iss >> perk) {
                    attunedPerks[++perkCount] = perk;
                }
                if(perkCount != 9) {
                    return false;
                }
                else {
                    playerStats->load_unique_perks(attunedPerks);
                }
            }
            break;
            case 13 :
            {
                int a, b, c, d, e, f, g;
                if(!(iss >> a >> b >> c >> d >> e >> f >> g)) {
                    return false;
                }
                else {
                    equipment->load_save_data(a, b, c, d, e, f, g);
                }
            }
            break;
            case 15 :
            {
                int a, b;
                if(!(iss >> a >> b)) {
                    return false;
                }
                else {
                    inventory->set_weight(a, b);
                }
            }
            break;
            case 16 :
            {
                int a, b;
                std::vector<ConsumableItem*> consumableItems;
                ConsumableItem* consumableItem;
                ConsumableItemList itemList = ConsumableItemList();
                while(iss >> a >> b) {
                    consumableItem = itemList.get_consumable_item(a);
                    while(b > 0) {
                        consumableItems.push_back(consumableItem);
                        b--;
                    }
                }
                inventory->load_consumable_items(consumableItems);
            }
            break;
            case 17 :
            {
                int a, b;
                std::vector<EquipableItem*> equipableItems;
                EquipableItem* equipableItem;
                EquipableItemList itemList = EquipableItemList();
                while(iss >> a >> b) {
                    equipableItem = itemList.get_equipable_item(a);
                    while(b > 0) {
                        equipableItems.push_back(equipableItem);
                        b--;
                    }
                }
                inventory->load_equipable_items(equipableItems);
            }
            break;
            case 19 :
            {
                int a;
                bool b;
                PerkList perkList = PerkList();
                Perk* perk;
                playerPerks.clear();
                while(iss >> a >> b) {
                    perk = perkList.get_perk(a);
                    perk->set_state(b);
                    playerPerks.push_back(perk);
                }
            }
            break;
            case 21 :
            {
                int index = -1, runeWieldedIndex;
                int a;
                bool b;
                std::vector<Rune*> runes;
                RuneList runeList = RuneList();
                Rune* rune;
                while(iss >> a >> b) {
                    index++;
                    rune = runeList.get_rune(a);
                    if(b == true) {
                        runeWieldedIndex = index;
                    }
                    runes.push_back(rune);
                }
                if(index >= 0) {
                    bracelet.load_runes(runes, runeWieldedIndex);
                }
            }
            break;
        }
    }
    return true;
}

Loader::~Loader() {}
