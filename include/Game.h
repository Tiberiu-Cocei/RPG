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
#include "Perk.h"
#define _WIN32_WINNT 0x0500
#include "Bracelet.h"
#include "Saver.h"
#include "Loader.h"

class Game
{
    public:
        Game();
        ~Game();

    private:
        void play();
        void game_introduction();
        bool gameOver;
        const int numberOfLevels = 4;
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
        std::vector<Perk*> playerPerks;
        Bracelet bracelet;
        Saver saver;
        Loader loader;
};

#endif
