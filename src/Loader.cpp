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

bool Loader::load_game(int& _levelNumber, int& _coordinates, Level*& level, PlayerStats*& playerStats, Equipment*& equipment,
                      Inventory*& inventory, std::vector<Perk*>& playerPerks, Bracelet& bracelet, std::string fileName) {
    std::string fullPath = "../../saves/" + fileName;
    std::ifstream saveFile(fullPath);
    std::string line;
    int lineNr = 0;
    while(std::getline(saveFile, line)) {
        ++lineNr;
        std::istringstream iss(line);
        switch(lineNr) {
            case 2 : {
                int levelNumber, coordinates;
                if(!(iss >> levelNumber >> coordinates)) {
                    return false;
                }
                else {
                    _levelNumber = levelNumber;
                    _coordinates = coordinates;
                    delete level;
                    LevelList levelList = LevelList();
                    level = levelList.get_level(levelNumber);
                }
                break;
            }
            case 4 : {
                bool isBossBeaten, isFountainUsed, isEquipableTreasureTaken, isConsumableTreasureTaken, isSecretItemTaken, isRuneTaken;
                if(!(iss >> isBossBeaten >> isFountainUsed >> isEquipableTreasureTaken
                         >>  isConsumableTreasureTaken >> isSecretItemTaken >> isRuneTaken)) {
                    return false;
                }
                else {
                    level->load_room_states(isBossBeaten, isFountainUsed, isEquipableTreasureTaken,
                                         isConsumableTreasureTaken, isSecretItemTaken, isRuneTaken);
                }
                break;
            }
            case 5 : {
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
                 break;
            }
            case 7 : {
                int currentHealthPoints, healthPoints, attack, strength, defense, luck, evasion;
                if(!(iss >> currentHealthPoints >> healthPoints >> attack >> strength >> defense >> luck >> evasion)) {
                    return false;
                }
                else {
                    playerStats->load_base_stats(currentHealthPoints, healthPoints, attack, strength, defense, luck, evasion);
                }
                break;
            }
            case 8 : {
                int tempHealthPoints, tempAttack, tempStrength, tempDefense, tempLuck, tempEvasion;
                if(!(iss >> tempHealthPoints >> tempAttack >> tempStrength >> tempDefense >> tempLuck >> tempEvasion)) {
                    return false;
                }
                else {
                    playerStats->modify_temp_stats(tempHealthPoints, tempAttack, tempStrength, tempDefense, tempLuck, tempEvasion);
                }
                break;
            }
            case 9 : {
                int dmgBonus, dmgReduction;
                if(!(iss >> dmgBonus >> dmgReduction)) {
                    return false;
                }
                else {
                    playerStats->load_damage_stats(dmgBonus, dmgReduction);
                }
                break;
            }
            case 10 : {
                int experience, hpRegen, bonusHealing, escapeBonus, currentCharges, maxCharges;
                if(!(iss >> experience >> hpRegen >> bonusHealing >> escapeBonus >> currentCharges >> maxCharges)) {
                    return false;
                }
                else {
                    playerStats->load_special_stats(experience, hpRegen, bonusHealing, escapeBonus, currentCharges, maxCharges);
                }
                break;
            }
            case 11 : {
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
                break;
            }
            case 13 : {
                int helmet, body, legs, gloves, boots, mainHand, offhand;
                if(!(iss >> helmet >> body >> legs >> gloves >> boots >> mainHand >> offhand)) {
                    return false;
                }
                else {
                    equipment->load_equipment(helmet, body, legs, gloves, boots, mainHand, offhand);
                }
                break;
            }
            case 15 : {
                int currentWeight, maxWeight;
                if(!(iss >> currentWeight >> maxWeight)) {
                    return false;
                }
                else {
                    inventory->load_weight(currentWeight, maxWeight);
                }
                break;
            }
            case 16 : {
                int itemId, itemCount;
                std::vector<ConsumableItem*> consumableItems;
                ConsumableItem* consumableItem;
                ConsumableItemList itemList = ConsumableItemList();
                while(iss >> itemId >> itemCount) {
                    consumableItem = itemList.get_consumable_item(itemId);
                    while(itemCount > 0) {
                        consumableItems.push_back(consumableItem);
                        itemCount--;
                    }
                }
                inventory->load_consumable_items(consumableItems);
                break;
            }
            case 17 : {
                int itemId, itemCount;
                std::vector<EquipableItem*> equipableItems;
                EquipableItem* equipableItem;
                EquipableItemList itemList = EquipableItemList();
                while(iss >> itemId >> itemCount) {
                    equipableItem = itemList.get_equipable_item(itemId);
                    while(itemCount > 0) {
                        equipableItems.push_back(equipableItem);
                        itemCount--;
                    }
                }
                inventory->load_equipable_items(equipableItems);
                break;
            }
            case 19 : {
                int perkId;
                bool perkState;
                PerkList perkList = PerkList();
                Perk* perk;
                playerPerks.clear();
                while(iss >> perkId >> perkState) {
                    perk = perkList.get_perk(perkId);
                    perk->set_state(perkState);
                    playerPerks.push_back(perk);
                }
                break;
            }
            case 21 : {
                int index = -1, runeWieldedIndex = -1;
                int runeId;
                bool isRuneWielded;
                std::vector<Rune*> runes;
                RuneList runeList = RuneList();
                Rune* rune;
                while(iss >> runeId >> isRuneWielded) {
                    index++;
                    rune = runeList.get_rune(runeId);
                    if(isRuneWielded == true) {
                        runeWieldedIndex = index;
                    }
                    runes.push_back(rune);
                }
                if(index >= 0) {
                    bracelet.load_runes(runes, runeWieldedIndex);
                }
                break;
            }
        }
    }
    return true;
}

Loader::~Loader() {}
