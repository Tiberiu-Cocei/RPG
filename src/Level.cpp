#include "Level.h"

Level::Level(std::string levelName, std::string beginDesc, std::string endDesc, int textColorNr, EquipableItem* treasureEquipable,
             ConsumableItem* treasureConsumable, std::vector<Enemy*> enemyList, std::array<char, 225> roomLayout, int bossCoordinates,
             int fountainCoordinates, int equipableTreasureCoordinates, int consumableTreasureCoordinates, int initialCoordinates,
             int clueCoordinates, int secretCoordinates, std::string clueDesc, EquipableItem* secretEquipable)
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
    this->clueCoordinates = clueCoordinates;
    this->secretCoordinates = secretCoordinates;
    this->isBossBeaten = false;
    this->isFountainUsed = false;
    this->isEquipableTreasureTaken = false;
    this->isConsumableTreasureTaken = false;
    this->isSecretItemTaken = false;
    this->clueDesc = clueDesc;
    this->secretEquipable = secretEquipable;
    combat = new Combat();

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
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
                 <<"\nin the middle of the hidden section of the cave the " << secretEquipable->get_name() << ". Do you take it?\n";
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
    if(roomLayout.at(coordinates + 1) != 'S') {
        userMap.at(coordinates + 1) = roomLayout.at(coordinates + 1);
    }
    else {
        userMap.at(coordinates + 1) = 'X';
    }
    if(roomLayout.at(coordinates - 1) != 'S') {
        userMap.at(coordinates - 1) = roomLayout.at(coordinates - 1);
    }
    else {
        userMap.at(coordinates - 1) = 'X';
    }
    if(roomLayout.at(coordinates + 15) != 'S') {
        userMap.at(coordinates + 15) = roomLayout.at(coordinates + 15);
    }
    else {
        userMap.at(coordinates + 15) = 'X';
    }
    if(roomLayout.at(coordinates - 15) != 'S') {
        userMap.at(coordinates - 15) = roomLayout.at(coordinates - 15);
    }
    else {
        userMap.at(coordinates - 15) = 'X';
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
}

std::string Level::get_possible_directions(int coordinates) { //todo: say in string if its a special room
    std::string directions = "The direction(s) you can move in are:";
    if (roomLayout.at(coordinates - 15) != 'X' && roomLayout.at(coordinates - 15) != 'S') {
        directions += " north";
        direction_details(directions, coordinates - 15);
    }
    if (roomLayout.at(coordinates + 1) != 'X' && roomLayout.at(coordinates + 1) != 'S') {
        directions += " east";
        direction_details(directions, coordinates + 1);
    }
    if (roomLayout.at(coordinates + 15) != 'X' && roomLayout.at(coordinates + 15) != 'S') {
        directions += " south";
        direction_details(directions, coordinates + 15);
    }
    if (roomLayout.at(coordinates - 1) != 'X' && roomLayout.at(coordinates - 1) != 'S') {
        directions += " west";
        direction_details(directions, coordinates - 1);
    }
    return directions;
}

bool Level::boss_warning() {
    if(isBossBeaten == false) {
        std::cout<<"You are about to enter the boss room. Escape is not an option when fighting. Are you sure you want to continue?\n";
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

bool Level::move_in_direction(int& coordinates, char direction, Equipment*& player, Inventory*& inventory) {
    bool bossFight = false;
    switch(direction) {
        case('N') :
           if (roomLayout.at(coordinates - 15) != 'X') {
               if(coordinates - 15 == bossCoordinates) {
                    bossFight = boss_warning();
                    if(bossFight == true) {
                        coordinates-=15;
                        update_user_map(coordinates);
                    }
               }
               else {
                    coordinates-=15;
                    update_user_map(coordinates);
               }
           }
           else {
               std::cout<<"You cannot move north.";
           }
           break;
        case('E') :
           if (roomLayout.at(coordinates + 1) != 'X') {
               if(coordinates + 1 == bossCoordinates) {
                    bossFight = boss_warning();
                    if(bossFight == true) {
                        coordinates++;
                        update_user_map(coordinates);
                    }
               }
               else {
                    coordinates++;
                    update_user_map(coordinates);
               }
           }
           else {
               std::cout<<"You cannot move east.";
           }
           break;
        case('S') :
           if (roomLayout.at(coordinates + 15) != 'X') {
               if(coordinates + 15 == bossCoordinates) {
                    bossFight = boss_warning();
                    if(bossFight == true) {
                        coordinates+=15;
                        update_user_map(coordinates);
                    }
               }
               else {
                    coordinates+=15;
                    update_user_map(coordinates);
               }
           }
           else {
               std::cout<<"You cannot move south.";
           }
           break;
        case('W') :
           if (roomLayout.at(coordinates - 1) != 'X') {
               if(coordinates - 1 == bossCoordinates) {
                    bossFight = boss_warning();
                    if(bossFight == true) {
                        coordinates--;
                        update_user_map(coordinates);
                    }
               }
               else {
                    coordinates--;
                    update_user_map(coordinates);
               }
           }
           else {
               std::cout<<"You cannot move west.";
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
    else if(coordinates == clueCoordinates) {
        clue_room();
    }
    else if(coordinates == secretCoordinates) {
        secret_room(inventory);
    }
    return playerDeath;
}

bool Level::generic_room(int coordinates, Equipment*& player, Inventory*& inventory) {
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
        playerDeath = combat->encounter(player, inventory, enemy);
    }
    return playerDeath;
}

bool Level::boss_room(Equipment*& player, Inventory*& inventory) {
    if(isBossBeaten == false) {
        bool playerDeath = false;
        Enemy* boss = enemyList.at(4);
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
        std::cout<<"You place your hand on the door to the treasure room. It brightens up in a golden light and it opens shortly after. You go inside and find in"
                 <<" the middle of the room the " << treasureEquipable->get_name() << ". Do you take it?\n";
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
        std::cout<<"You place your hand on the door to the treasure room. It lights up and the doors open shortly after. You go inside and find in"
                 <<" the middle of the room the " << treasureConsumable->get_name() << ". Do you take it?\n";
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

int Level::get_boss_coordinates() {
    return bossCoordinates;
}

bool Level::is_boss_beaten() {
    return isBossBeaten;
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
