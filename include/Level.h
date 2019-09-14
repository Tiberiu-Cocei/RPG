#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <string.h>
#include <ConsumableItem.h>
#include <EquipableItem.h>
#include <Enemy.h>
#include <vector>
#include <array>
#include <windows.h>
#include <Combat.h>
#include "Perk.h"


class Level
{
    public:
        Level(std::string, std::string, std::string, int, EquipableItem*, ConsumableItem*,
              std::vector<Enemy*>, std::array<char, 225>, int, int, int, int, int, int, int, std::string, EquipableItem*, std::vector<Perk*>);
        ~Level();
        void begin_level();
        void end_level();
        std::string get_possible_directions(int);
        bool move_in_direction(int&, char, Equipment*&, PlayerStats*&, std::vector<Perk*>&, Inventory*&);
        int get_initial_coordinates();
        int get_boss_coordinates();
        bool is_boss_beaten();
        void show_user_map();
        int get_text_color_number();

    private:
        bool boss_warning();
        bool generic_room(int, Equipment*&, PlayerStats*&, std::vector<Perk*>&, Inventory*&);
        bool boss_room(Equipment*&, PlayerStats*&, std::vector<Perk*>&, Inventory*&);
        void fountain_room(PlayerStats*&, std::vector<Perk*>&);
        void equipable_treasure_room(Inventory*&);
        void consumable_treasure_room(Inventory*&);
        void direction_details(std::string&, int);
        void clue_room();
        void secret_room(Inventory*&);
        void update_user_map(int);

        const int valuesForDirections[4] = {-15, 1, 15, -1};
        const std::string stringForDirections[4] = {"north", "east", "south", "west"};
        std::map<char, int> directionalMapping;
        std::map<char, int>::iterator directionalMappingIterator;
        const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        std::string levelName;
        std::string beginDesc;
        std::string endDesc;
        std::string clueDesc;
        int textColorNr;
        EquipableItem* treasureEquipable;
        EquipableItem* secretEquipable;
        ConsumableItem* treasureConsumable;
        std::vector<Enemy*> enemyList;
        std::array<char, 225> roomLayout;
        std::array<char, 225> userMap;
        int bossCoordinates;
        int fountainCoordinates;
        int equipableTreasureCoordinates;
        int consumableTreasureCoordinates;
        int initialCoordinates;
        int clueCoordinates;
        int secretCoordinates;
        bool isBossBeaten;
        bool isFountainUsed;
        bool isEquipableTreasureTaken;
        bool isConsumableTreasureTaken;
        bool isSecretItemTaken;
        Combat* combat;
        std::vector<Perk*> fountainPerks;
};

#endif
