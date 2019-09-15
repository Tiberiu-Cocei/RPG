#include "Level.h"

Level::Level(std::string levelName, std::string beginDesc, std::string endDesc, int textColorNr, EquipableItem* treasureEquipable,
             ConsumableItem* treasureConsumable, std::vector<Enemy*> enemyList, std::array<char, 225> roomLayout,
             int equipableTreasureCoordinates, int consumableTreasureCoordinates, int initialCoordinates, std::string clueDesc,
             EquipableItem* secretEquipable, std::vector<Perk*> fountainPerks, Rune* rune)
             : levelName(levelName), beginDesc(beginDesc), endDesc(endDesc), treasureEquipable(treasureEquipable),
               treasureConsumable(treasureConsumable), enemyList(enemyList), roomLayout(roomLayout), clueDesc(clueDesc),
               secretEquipable(secretEquipable), fountainPerks(fountainPerks), rune(rune) {
    this->textColorNr = textColorNr;
    this->equipableTreasureCoordinates = equipableTreasureCoordinates;
    this->consumableTreasureCoordinates = consumableTreasureCoordinates;
    this->initialCoordinates = initialCoordinates;
    this->isBossBeaten = false;
    this->isFountainUsed = false;
    this->isEquipableTreasureTaken = false;
    this->isConsumableTreasureTaken = false;
    this->isSecretItemTaken = false;
    this->isRuneTaken = false;
    combat = new Combat();

    directionalMapping.insert(std::make_pair('N',-15));
    directionalMapping.insert(std::make_pair('E',1));
    directionalMapping.insert(std::make_pair('S',15));
    directionalMapping.insert(std::make_pair('W',-1));

    userMap = {
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
            };
    userMap.at(initialCoordinates) = 'H';
    if(roomLayout.at(initialCoordinates + 1) != 'S') {
        userMap.at(initialCoordinates + 1) = roomLayout.at(initialCoordinates + 1);
    }
    else {
        userMap.at(initialCoordinates + 1) = 'X';
    }
    userMap.at(initialCoordinates - 1) = roomLayout.at(initialCoordinates - 1);
    userMap.at(initialCoordinates + 15) = roomLayout.at(initialCoordinates + 15);
    userMap.at(initialCoordinates - 15) = roomLayout.at(initialCoordinates - 15);

    //changing console text color
    SetConsoleTextAttribute(hConsole, this->textColorNr);
}

void Level::clue_room() {
    std::cout<<"\nWritten on the wall in darkness that does not yield to light you read:\n\n";
    SetConsoleTextAttribute(this->hConsole, 80);
    std::cout<<clueDesc<<"\n";
    SetConsoleTextAttribute(this->hConsole, this->textColorNr);
}

void Level::secret_room(Inventory*& inventory) {
    if(isSecretItemTaken == false) {
        std::cout<<"\nYou place your hand on the wall. To your surprise, it goes right through. You go through the wall and find"
                 <<"\nin the middle of the hidden section of the cave the " << secretEquipable->get_name() << ". Do you take it? (Yes/no)\n";
        std::string command;
        getline(std::cin, command);
        if(command == "Yes" || command == "yes") {
            inventory->pickup_item(secretEquipable);
            isSecretItemTaken = true;
        }
    }
    else {
        std::cout<<"There is nothing more for you in this place.\n";
    }
}

void Level::update_user_map(int coordinates) {
    for(int i = 0; i < 4; i++) {
        if(roomLayout.at(coordinates + valuesForDirections[i]) != 'S') {
        userMap.at(coordinates + valuesForDirections[i]) = roomLayout.at(coordinates + valuesForDirections[i]);
        }
        else {
            userMap.at(coordinates + valuesForDirections[i]) = 'X';
        }
    }
    userMap.at(coordinates) = 'H';
}

void Level::show_user_map() {
    std::cout<<"O - open area, T - treasure room, F - fountain room, C - clue room, B - boss room, X - unreachable\n";
    for(int i = 0; i<15; i++) {
        for(int j = 0; j<15; j++) {
            if(userMap.at(i*15 + j) != 'H') {
                std::cout<<userMap.at(i*15 + j)<<" ";
            }
            else {
                SetConsoleTextAttribute(this->hConsole, 45);
                std::cout<<" ";
                SetConsoleTextAttribute(this->hConsole, this->textColorNr);
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

int Level::get_initial_coordinates() {
    return initialCoordinates;
}

void Level::begin_level() {
    std::cout<<beginDesc<<"\n\n";
    std::cout<<"You are now playing the level: " + levelName + ".\n\n";
}

void Level::end_level() {
    std::cout<<endDesc<<"\n";
    std::cout<<"Congratulations! You have finished the level: " + levelName + ".\n\n";
}

void Level::direction_details(std::string& directions, int coordinates) {
    if(roomLayout.at(coordinates) == 'B') {
        directions += "(boss room)";
    }
    else if(roomLayout.at(coordinates) == 'T') {
        directions += "(treasure room)";
    }
    else if(roomLayout.at(coordinates) == 'F') {
        directions += "(fountain room)";
    }
    else if(roomLayout.at(coordinates) == 'C') {
        directions += "(clue room)";
    }
    else if(roomLayout.at(coordinates) == 'R') {
        directions += "(rune room)";
    }
}

std::string Level::get_possible_directions(int coordinates) {
    std::string directions = "The direction(s) you can move in are:";
    for(int i = 0; i < 4; i++) {
        if (roomLayout.at(coordinates + valuesForDirections[i]) != 'X' && roomLayout.at(coordinates + valuesForDirections[i]) != 'S') {
            directions += " " + stringForDirections[i];
            direction_details(directions, coordinates + valuesForDirections[i]);
        }
    }
    return directions;
}

bool Level::boss_warning() {
    if(isBossBeaten == false) {
        std::cout<<"You are about to enter the boss room. Escape is not an option when fighting. Are you sure you want to continue? (Yes/no)\n";
        std::string command;
        getline(std::cin, command);
        if(command == "Yes" || command == "yes") {
            return true;
        }
        return false;
    }
    else {
        return true;
    }
}

bool Level::move_in_direction(int& coordinates, char direction, Equipment*& equipment, PlayerStats*& playerStats, std::vector<Perk*>& playerPerks, Inventory*& inventory, Bracelet& bracelet) {
    bool bossFight = false;
    directionalMappingIterator = directionalMapping.find(direction);
    int directionValue = directionalMappingIterator->second;

    if (roomLayout.at(coordinates + directionValue) != 'X') {
        if(roomLayout.at(coordinates + directionValue) == 'B') {
            bossFight = boss_warning();
            if(bossFight == true) {
                coordinates+= directionValue;
                update_user_map(coordinates);
            }
        }
        else {
            coordinates+= + directionValue;
            update_user_map(coordinates);
        }
    }
    else {
        std::cout<<"You cannot move in that direction.";
    }

    bool playerDeath = false;
    if(roomLayout.at(coordinates) == 'O') {
        playerDeath = generic_room(coordinates, equipment, playerStats, playerPerks, inventory, bracelet);
    }
    else if(roomLayout.at(coordinates) == 'B') {
        playerDeath = boss_room(equipment, playerStats, playerPerks, inventory, bracelet);
    }
    else if(roomLayout.at(coordinates) == 'F') {
        fountain_room(playerStats, playerPerks);
    }
    else if(coordinates == equipableTreasureCoordinates) {
        equipable_treasure_room(inventory);
    }
    else if(coordinates == consumableTreasureCoordinates) {
        consumable_treasure_room(inventory);
    }
    else if(roomLayout.at(coordinates) == 'C') {
        clue_room();
    }
    else if(roomLayout.at(coordinates) == 'S') {
        secret_room(inventory);
    }
    else if(roomLayout.at(coordinates) == 'R') {
        rune_room(bracelet);
    }
    return playerDeath;
}

bool Level::generic_room(int coordinates, Equipment*& equipment, PlayerStats*& playerStats, std::vector<Perk*> &playerPerks, Inventory*& inventory, Bracelet& bracelet) {
    int encounterChance = rand() % 10 + 1;
    bool playerDeath = false;
    if(encounterChance == 2 || encounterChance == 5 || encounterChance == 8) {
        std::cout<<"\n";
        int valueForEncounter = rand() % 100 + coordinates + 1;
        Enemy* enemy;
        if(valueForEncounter < 120) {
            enemy = enemyList.at(3);
        }
        else if(valueForEncounter < 200) {
            enemy = enemyList.at(2);
        }
        else {
            valueForEncounter = rand() % 100 + 1;
            if(valueForEncounter <= 50) {
                enemy = enemyList.at(1);
            }
            else {
                enemy = enemyList.at(0);
            }
        }
        playerDeath = combat->encounter(equipment, playerStats, playerPerks, inventory, enemy, bracelet);
    }
    return playerDeath;
}

bool Level::boss_room(Equipment*& equipment, PlayerStats*& playerStats, std::vector<Perk*> &playerPerks, Inventory*& inventory, Bracelet& bracelet) {
    if(isBossBeaten == false) {
        bool playerDeath = false;
        Enemy* boss = enemyList.at(4);
        playerDeath = combat->encounter(equipment, playerStats, playerPerks, inventory, boss, bracelet, true);
        if(playerDeath == false) {
            this->isBossBeaten = true;
        }
        return playerDeath;
    }
    else {
        return false;
    }
}

void Level::fountain_room(PlayerStats*& playerStats, std::vector<Perk*> &playerPerks) {
    if(isFountainUsed == false) {
        std::cout<<"You have reached the fountain room. Do you wish to accept its gift now? (Yes/no)\n";
        std::string command;
        getline(std::cin, command);
        if(command == "Yes" || command == "yes") {
            playerStats->gain_health(250);
            for(auto perk : fountainPerks) {
                playerPerks.push_back(perk);
            }
            this->isFountainUsed = true;
            std::cout<<"The fountain has bestowed its knowledge upon you. You may now attune new perks.\n";
        }
    }
    else {
        std::cout<<"You have already accepted the gift of the fountain.\n";
    }
}

void Level::equipable_treasure_room(Inventory*& inventory) {
    if(isEquipableTreasureTaken == false) {
        std::cout<<"You place your hand on the door to the treasure room. It brightens up in a golden light and it opens shortly after. You go inside and find in"
                 <<" the middle of the room the " << treasureEquipable->get_name() << ". Do you take it? (Yes/no)\n";
        std::string command;
        getline(std::cin, command);
        if(command == "Yes" || command == "yes") {
            inventory->pickup_item(treasureEquipable);
            isEquipableTreasureTaken = true;
        }
    }
    else {
        std::cout<<"You bask in the warm golden light of the treasure room. There's nothing more left to be done here.\n";
    }
}

void Level::consumable_treasure_room(Inventory*& inventory) {
    if(isConsumableTreasureTaken == false) {
        std::cout<<"You place your hand on the door to the treasure room. It lights up it opens shortly after. You go inside and find in"
                 <<" the middle of the room the " << treasureConsumable->get_name() << ". Do you take it? (Yes/no)\n";
        std::string command;
        getline(std::cin, command);
        if(command == "Yes" || command == "yes") {
            inventory->pickup_item(treasureConsumable);
            isConsumableTreasureTaken = true;
        }
    }
    else {
        std::cout<<"The treasure room has lost its glow since you took the item. There's nothing more left to be done here.\n";
    }
}

void Level::rune_room(Bracelet& bracelet) {
    if(isRuneTaken == true) {
        std::cout<<"The magic workshop where you found the rune. There's nothing of value left in it.\n";
    }
    else {
        std::cout<<"You have entered what seems to be a magic workshop. There are plenty of arcane machinery laying around, all of which seem to be unusable.\n"
                 <<"Shining beneath some rubble, you find one of the magical stones the cloaked man told you about.\n"
                 <<"You determine that you have found a " << rune->get_name() << "! On a piece of paper underneath the stone you read the following:\n"
                 <<rune->get_description()<<"\n";
        bracelet.add_rune(this->rune);
        isRuneTaken = true;
    }
}

bool Level::is_boss_room(int coordinates) {
    if(this->roomLayout.at(coordinates) == 'B') {
        return true;
    }
    return false;
}

bool Level::is_boss_beaten() {
    return isBossBeaten;
}

int Level::get_text_color_number() {
    return textColorNr;
}

Level::~Level() {
    if(isEquipableTreasureTaken == false) delete treasureEquipable;
    if(isConsumableTreasureTaken == false) delete treasureConsumable;
    if(isSecretItemTaken == false) delete secretEquipable;
    if(isRuneTaken == false) delete rune;
    if(isFountainUsed == false) {
        for(auto fountainPerk : fountainPerks) {
            delete fountainPerk;
        }
    }
    delete combat;
    for(auto enemy : enemyList) {
        delete enemy;
    }
}
