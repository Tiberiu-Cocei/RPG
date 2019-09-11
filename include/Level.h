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


class Level
{
    public:
        Level(std::string, std::string, std::string, int, EquipableItem*, ConsumableItem*,
              std::vector<Enemy*>, std::array<char, 225>, int, int, int, int, int);
        ~Level();
        void begin_level();
        void end_level();
        std::string get_possible_directions(int);
        bool move_in_direction(int&, char, Equipment*&, Inventory*&);
        int get_initial_coordinates();
        int get_boss_coordinates();
        bool is_boss_beaten();
        void show_user_map();

    private:
        bool boss_warning();
        bool generic_room(int, Equipment*&, Inventory*&);
        bool boss_room(Equipment*&, Inventory*&);
        void fountain_room(Equipment*&);
        void equipable_treasure_room(Inventory*&);
        void consumable_treasure_room(Inventory*&);
        void direction_details(std::string&, int);
        void update_user_map(int);

        HANDLE hConsole;
        std::string levelName;
        std::string beginDesc;
        std::string endDesc;
        int textColorNr;
        EquipableItem* treasureEquipable;
        ConsumableItem* treasureConsumable;
        std::vector<Enemy*> enemyList;
        std::array<char, 225> roomLayout;
        std::array<char, 225> userMap;
        int bossCoordinates;
        int fountainCoordinates;
        int equipableTreasureCoordinates;
        int consumableTreasureCoordinates;
        int initialCoordinates;
        bool isBossBeaten;
        bool isFountainUsed;
        bool isEquipableTreasureTaken;
        bool isConsumableTreasureTaken;
        Combat* combat;
};

#endif
