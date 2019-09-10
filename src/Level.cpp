#include "Level.h"

Level::Level(std::string levelName, std::string beginDesc, std::string endDesc, int textColorNr, EquipableItem* treasureEquipable,
             ConsumableItem* treasureConsumable, std::vector<Enemy*> enemyList, std::array<char, 225> roomLayout, int bossCoordinates,
             int fountainCoordinates, int equipableTreasureCoordinates, int consumableTreasureCoordinates, int initialCoordinates)
{
    this->levelName = levelName;
    this->beginDesc = beginDesc;
    this->endDesc = endDesc;
    this->textColorNr = textColorNr;
    this->treasureEquipable = treasureEquipable;
    this->treasureConsumable = treasureConsumable;
    this->enemyList = enemyList;
    this->roomLayout = roomLayout;
    this->bossCoordinates = bossCoordinates;
    this->fountainCoordinates = fountainCoordinates;
    this->equipableTreasureCoordinates = equipableTreasureCoordinates;
    this->consumableTreasureCoordinates = consumableTreasureCoordinates;
    this->initialCoordinates = initialCoordinates;
    this->isBossBeaten = false;
    this->isFountainUsed = false;
    this->isEquipableTreasureTaken = false;
    this->isConsumableTreasureTaken = false;
    combat = new Combat();

    //changing console text color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, this->textColorNr);
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
}

std::string Level::get_possible_directions(int coordinates) { //todo: say in string if its a special room
    std::string directions = "The direction(s) you can move in are:";
    if (roomLayout.at(coordinates - 15) != 'X') {
        directions += " north";
        direction_details(directions, coordinates - 15);
    }
    if (roomLayout.at(coordinates + 1) != 'X') {
        directions += " east";
        direction_details(directions, coordinates + 1);
    }
    if (roomLayout.at(coordinates + 15) != 'X') {
        directions += " south";
        direction_details(directions, coordinates + 15);
    }
    if (roomLayout.at(coordinates - 1) != 'X') {
        directions += " west";
        direction_details(directions, coordinates - 1);
    }
    return directions;
}

bool Level::move_in_direction(int& coordinates, char direction, Equipment*& player, Inventory*& inventory) {
    switch(direction) {
        case('N') :
           if (roomLayout.at(coordinates - 15) != 'X') {
               coordinates-=15;
               }
           break;
        case('E') :
           if (roomLayout.at(coordinates + 1) != 'X') {
               coordinates++;
           }
           break;
        case('S') :
           if (roomLayout.at(coordinates + 15) != 'X') {
               coordinates+=15;
           }
           break;
        case('W') :
           if (roomLayout.at(coordinates - 1) != 'X') {
               coordinates--;
           }
           break;
        default :
           std::cout<<"Invalid direction.\n";
           return false;
    }
    bool playerDeath = false;
    if(roomLayout.at(coordinates) == 'O') {
        playerDeath = generic_room(coordinates, player, inventory);
    }
    else if(coordinates == bossCoordinates) {
        playerDeath = boss_room(player, inventory);
    }
    else if(coordinates == fountainCoordinates) {
        fountain_room(player);
    }
    else if(coordinates == equipableTreasureCoordinates) {
        equipable_treasure_room(inventory);
    }
    else if(coordinates == consumableTreasureCoordinates) {
        consumable_treasure_room(inventory);
    }
    return playerDeath;
}

bool Level::generic_room(int coordinates, Equipment*& player, Inventory*& inventory) {
    int encounterChance = rand() % 10 + 1;
    bool playerDeath = false;
    if(encounterChance == 2 || encounterChance == 5 || encounterChance == 8) {
        int valueForEncounter = rand() % 100 + coordinates + 1;
        Enemy* enemy;
        if(valueForEncounter < 120) {
            enemy = enemyList.at(4);
        }
        else if(valueForEncounter < 200) {
            enemy = enemyList.at(3);
        }
        else {
            valueForEncounter = rand() % 100 + 1;
            if(valueForEncounter <= 50) {
                enemy = enemyList.at(2);
            }
            else {
                enemy = enemyList.at(1);
            }
        }
        playerDeath = combat->encounter(player, inventory, enemy);
    }
    return playerDeath;
}

bool Level::boss_room(Equipment*& player, Inventory*& inventory) {
    if(isBossBeaten == false) {
        bool playerDeath = false;
        Enemy* boss = enemyList.at(5);
        playerDeath = combat->encounter(player, inventory, boss, true);
        if(playerDeath == false) {
            this->isBossBeaten = true;
        }
        return playerDeath;
    }
    else {
        return false;
    }
}

void Level::fountain_room(Equipment*& player) {
    if(isFountainUsed == false) {
        std::cout<<"You have reached the fountain room. Do you wish to accept its gift now?\n";
        std::string command;
        getline(std::cin, command);
        if(command == "Yes" || command == "yes") {
            player->get_player_stats()->gain_health(150);
            this->isFountainUsed = true;
        }
    }
    else {
        std::cout<<"You have already accepted the gift of the fountain.\n";
    }
}

void Level::equipable_treasure_room(Inventory*& inventory) {
    if(isEquipableTreasureTaken == false) {
        std::cout<<"You place your hand on the door to the treasure room. It lights up and the doors open shortly after. You go inside and find in"
                 <<" the middle of the room the " << treasureEquipable->get_name() << ". Do you take it?\n";
        std::string command;
        getline(std::cin, command);
        if(command == "Yes" || command == "yes") {
            inventory->pickup_item(treasureEquipable);
            isEquipableTreasureTaken = true;
        }
    }
    else {
        std::cout<<"The treasure room has lost its glow since you took the item. There's nothing more left to be done here.\n";
    }
}

void Level::consumable_treasure_room(Inventory*& inventory) {
    if(isConsumableTreasureTaken == false) {
        std::cout<<"You place your hand on the door to the treasure room. It lights up and the doors open shortly after. You go inside and find in"
                 <<" the middle of the room the " << treasureEquipable->get_name() << ". Do you take it?\n";
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

Level::~Level()
{
    if(isEquipableTreasureTaken == false) delete treasureEquipable;
    if(isConsumableTreasureTaken == false) delete treasureConsumable;
    delete combat;
    for(auto enemy : enemyList)
    {
        delete enemy;
    }
}
