#include "LevelList.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <array>

LevelList::LevelList()
{
    this->equipableList = new EquipableItemList();
    this->consumableList = new ConsumableItemList();
    this->enemyList = new EnemyList();
}

Level* LevelList::get_level(int index) {
    switch(index) {
        case 1 :
            std::string levelName = "Monster cave";
            std::string beginDesc = "You enter the cave. Behind you see the elders watch you. Feeling your hesitation, they remind you of what you must do. \nNot having much of a choice, you press on. After a couple of steps the cave entrance closes itself. \nYour only source of light is the torches that are laid along the cave walls. \nFor a moment, you wonder who or what placed them.";
            std::string endDesc = "With the abomination now dead, the way forward is wide open. It seems like you're going to have to venture deeper into the mines. \nBefore you do so, you grab a torch, fearing that there won't be any more of them down there.";
            int textColorNr = 14;
            EquipableItem* treasureEquipable = equipableList->get_equipable_item(261);
            ConsumableItem* treasureConsumable = consumableList->get_consumable_item(51);
            std::vector<Enemy*> enemies;
            enemies.push_back(enemyList->get_enemy(1));
            enemies.push_back(enemyList->get_enemy(2));
            enemies.push_back(enemyList->get_enemy(3));
            enemies.push_back(enemyList->get_enemy(4));
            enemies.push_back(enemyList->get_enemy(5));
            std::array<char, 225> roomLayout = {
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'B', 'X', 'X',
                'X', 'X', 'O', 'X', 'O', 'O', 'X', 'T', 'X', 'O', 'O', 'O', 'X', 'X', 'X',
                'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X',
                'X', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X',
                'X', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'T', 'X',
                'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'X',
                'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X',
                'X', 'X', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X',
                'X', 'O', 'O', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X',
                'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'X', 'O', 'O', 'X',
                'X', 'X', 'X', 'F', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X',
                'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'X', 'X', 'O', 'O', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'
            };
            int bossCoordinates = 27;
            int fountainCoordinates = 183;
            int equipableTreasureCoordinates = 88;
            int consumableTreasureCoordinates = 37;
            int initialCoordinates = 208;
            return new Level(levelName, beginDesc, endDesc, textColorNr, treasureEquipable, treasureConsumable, enemies, roomLayout,
                             bossCoordinates, fountainCoordinates, equipableTreasureCoordinates, consumableTreasureCoordinates, initialCoordinates);
    }
}

LevelList::~LevelList()
{
}
