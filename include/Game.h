#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <windows.h>
#include <array>
#include "Equipment.h"
#include "Inventory.h"
#include "LevelList.h"
#define _WIN32_WINNT 0x0500

class Game
{
    public:
        Game();
        ~Game();

    private:
        void play();
        bool gameOver;
        const int numberOfLevels = 2;
        int currentLevel, currentCoordinates, commandValue, itemIndexInt;
        std::string commandKey, itemIndex;
        std::map<std::string, int> commandMapping;
        std::map<std::string, int>::iterator commandMappingIterator;
        PlayerStats * playerStats;
        Equipment * equipment;
        EquipableItemList * equipableItemList;
        ConsumableItemList * consumableItemList;
        Inventory * inventory;
        LevelList * levelList;
        Level * level;
};

#endif
