#include "Level.h"

Level::Level(std::string levelName, std::string beginDesc, std::string endDesc, int textColorNr, EquipableItem* treasureEquipable,
             ConsumableItem* treasureConsumable, std::vector<Enemy*> enemyList, std::array<char, 225> roomLayout, int bossCoordinates,
             int fountainCoordinates, int equipableTreasureCoordinates, int consumableTreasureCoordinates)
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
    this->isBossBeaten = false;
    this->isFountainUsed = false;
    this->isEquipableTreasureTaken = false;
    this->isConsumableTreasureTaken = false;
}



Level::~Level()
{
    delete treasureEquipable;
    delete treasureConsumable;
    for(auto enemy : enemyList)
    {
        delete enemy;
    }
}
