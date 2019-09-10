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
    std::string levelName, beginDesc, endDesc;
    int textColorNr, bossCoordinates, fountainCoordinates, equipableTreasureCoordinates, consumableTreasureCoordinates, initialCoordinates;
    EquipableItem* treasureEquipable;
    ConsumableItem* treasureConsumable;
    std::vector<Enemy*> enemies;
    std::array<char, 225> roomLayout;
    switch(index) {
        case 1 :
            levelName = "Monster cave";
            beginDesc = "You enter the cave. Behind you see the elders watch you. Feeling your hesitation, they remind you of what you must do. \nNot having much of a choice, you press on. After a couple of steps the cave entrance closes itself. \nYour only source of light is the torches that are laid along the cave walls. \nFor a moment, you wonder who or what placed them.";
            endDesc = "With the abomination now dead, the way forward is wide open. It seems like you're going to have to venture deeper into the mines. \nBefore you do so, you grab a torch, fearing that there won't be any more of them down there.";
            textColorNr = 14;
            treasureEquipable = equipableList->get_equipable_item(261);
            treasureConsumable = consumableList->get_consumable_item(51);
            enemies.push_back(enemyList->get_enemy(1));
            enemies.push_back(enemyList->get_enemy(2));
            enemies.push_back(enemyList->get_enemy(3));
            enemies.push_back(enemyList->get_enemy(4));
            enemies.push_back(enemyList->get_enemy(5));
            roomLayout = {
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
            bossCoordinates = 27;
            fountainCoordinates = 183;
            equipableTreasureCoordinates = 88;
            consumableTreasureCoordinates = 37;
            initialCoordinates = 208;
            return new Level(levelName, beginDesc, endDesc, textColorNr, treasureEquipable, treasureConsumable, enemies, roomLayout,
                             bossCoordinates, fountainCoordinates, equipableTreasureCoordinates, consumableTreasureCoordinates, initialCoordinates);

        case 2 :
            levelName = "Scientist's Lair";
            beginDesc = "There's only one way forward: down a hole. You pick up a rock and throw it down. \nAfter a few seconds, you hear a water splash. Would it be safe to jump down? \nWhat if the water is shallow? What if there's nothing but water? \nYou shake your head, trying to think away these thoughts. \nFinally, you find the courage to jump. After what felt like an eternity, you hit the water. \nYou surface and swim in a random direction, being too dark to see clearly. After a couple minutes you finally reach the shore. \nYou try to relight the torch using two rocks that you found nearby. After a long time you finally succeed. \nYou can now find your way around, and you see unlit torches along the cave walls which you light along the way.";
            endDesc = "As the scientist lies dead, you explore the surroundings to find your way forward. \nThere's a heavily boarded off section which you start to open up. \nWith every plank that you remove, more light penetrates the room. \nYou're glad that you'll finally see the sun again, though you realize that your quest is not over yet.";
            textColorNr = 11;
            treasureEquipable = equipableList->get_equipable_item(262);
            treasureConsumable = consumableList->get_consumable_item(52);
            enemies.push_back(enemyList->get_enemy(11));
            enemies.push_back(enemyList->get_enemy(12));
            enemies.push_back(enemyList->get_enemy(13));
            enemies.push_back(enemyList->get_enemy(14));
            enemies.push_back(enemyList->get_enemy(15));
            roomLayout = {
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'B', 'O', 'O', 'O', 'X', 'X',
                'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X',
                'X', 'O', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'X',
                'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'X',
                'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X',
                'X', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X',
                'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'T', 'X', 'X', 'X', 'X',
                'X', 'O', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'X',
                'X', 'O', 'O', 'F', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'X', 'X',
                'X', 'O', 'X', 'X', 'X', 'O', 'T', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X',
                'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'
            };
            bossCoordinates = 24;
            fountainCoordinates = 153;
            equipableTreasureCoordinates = 171;
            consumableTreasureCoordinates = 115;
            initialCoordinates = 204;
            return new Level(levelName, beginDesc, endDesc, textColorNr, treasureEquipable, treasureConsumable, enemies, roomLayout,
                             bossCoordinates, fountainCoordinates, equipableTreasureCoordinates, consumableTreasureCoordinates, initialCoordinates);

        default :
            levelName = "ERROR_LEVEL";
            beginDesc = "ERROR_LEVEL";
            endDesc = "ERROR_LEVEL";
            textColorNr = 12;
            treasureEquipable = equipableList->get_equipable_item(0);
            treasureConsumable = consumableList->get_consumable_item(0);
            enemies.push_back(enemyList->get_enemy(0));
            enemies.push_back(enemyList->get_enemy(0));
            enemies.push_back(enemyList->get_enemy(0));
            enemies.push_back(enemyList->get_enemy(0));
            enemies.push_back(enemyList->get_enemy(0));
            roomLayout = {
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'
            };
            bossCoordinates = 0;
            fountainCoordinates = 0;
            equipableTreasureCoordinates = 0;
            consumableTreasureCoordinates = 0;
            initialCoordinates = 0;
            return new Level(levelName, beginDesc, endDesc, textColorNr, treasureEquipable, treasureConsumable, enemies, roomLayout,
                             bossCoordinates, fountainCoordinates, equipableTreasureCoordinates, consumableTreasureCoordinates, initialCoordinates);
    }
}

LevelList::~LevelList()
{
}
