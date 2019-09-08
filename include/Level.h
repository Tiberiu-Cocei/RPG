#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <string.h>
#include <ConsumableItem.h>
#include <EquipableItem.h>
#include <Enemy.h>
#include <vector>
#include <array>


class Level
{
    public:
        Level(std::string, std::string, std::string, int, EquipableItem*, ConsumableItem*,
              std::vector<Enemy*>, std::array<char, 225>, int, int, int, int);
        ~Level();

    private:
        std::string levelName;
        std::string beginDesc;
        std::string endDesc;
        int textColorNr;
        EquipableItem* treasureEquipable;
        ConsumableItem* treasureConsumable;
        std::vector<Enemy*> enemyList;
        std::array<char, 225> roomLayout;
        int bossCoordinates;
        int fountainCoordinates;
        int equipableTreasureCoordinates;
        int consumableTreasureCoordinates;
        bool isBossBeaten;
        bool isFountainUsed;
        bool isEquipableTreasureTaken;
        bool isConsumableTreasureTaken;
};

#endif
