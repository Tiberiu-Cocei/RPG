#include "LevelList.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <array>
#include "Perk.h"

LevelList::LevelList() {
    this->equipableList = new EquipableItemList();
    this->consumableList = new ConsumableItemList();
    this->enemyList = new EnemyList();
    this->perkList = new PerkList();
    this->runeList = RuneList();
}

Level* LevelList::get_level(int index) {
    std::string levelName, beginDesc, endDesc, clueDesc;
    int textColorNr, equipableTreasureCoordinates, consumableTreasureCoordinates, initialCoordinates;
    EquipableItem* treasureEquipable;
    EquipableItem* secretEquipable;
    ConsumableItem* treasureConsumable;
    Rune* playerRune;
    Rune* bossRune;
    Rune* enemyRune;
    std::vector<Enemy*> enemies;
    std::vector<Perk*> fountainPerks;
    std::array<char, 225> roomLayout;
    switch(index) {
        case 1 :
            levelName = "Monster cave";
            beginDesc = "You enter the cave. Behind you see the elders watch you. Feeling your hesitation, they remind you of what you must do. \nNot having much of a choice, you press on. After a couple of steps the cave entrance closes itself. \nYour only source of light is the torches that are laid along the cave walls. For a moment, you wonder who or what placed them.";
            endDesc = "What was that you just fought? Was it truly part of the trial, you ask yourself. It did not seem like it would spare you, were you to lose the fight. \nWith the abomination now dead, the way forward is wide open. It seems like you're going to have to venture deeper into the mines. \nBefore you do so, you grab a torch, fearing that there won't be any more of them down there.";
            textColorNr = 14;
            treasureEquipable = equipableList->get_equipable_item(261);
            treasureConsumable = consumableList->get_consumable_item(51);
            secretEquipable = equipableList->get_equipable_item(61);
            playerRune = runeList.get_rune(1);
            bossRune = runeList.get_rune(11);
            enemies.push_back(enemyList->get_enemy(1));
            enemies.push_back(enemyList->get_enemy(2));
            enemies.push_back(enemyList->get_enemy(3));
            enemies.push_back(enemyList->get_enemy(4));
            enemies.push_back(enemyList->get_enemy(5));
            fountainPerks.push_back(perkList->get_perk(1));
            fountainPerks.push_back(perkList->get_perk(2));
            fountainPerks.push_back(perkList->get_perk(3));
            fountainPerks.push_back(perkList->get_perk(4));
            fountainPerks.push_back(perkList->get_perk(5));
            fountainPerks.push_back(perkList->get_perk(6));
            fountainPerks.push_back(perkList->get_perk(7));
            fountainPerks.push_back(perkList->get_perk(8));
            roomLayout = {
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'B', 'X', 'X',
                'X', 'X', 'O', 'X', 'O', 'O', 'X', 'T', 'X', 'O', 'O', 'O', 'X', 'X', 'X',
                'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X',
                'X', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X',
                'X', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'T', 'X',
                'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'X',
                'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X',
                'X', 'X', 'O', 'O', 'R', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X',
                'X', 'O', 'O', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X',
                'X', 'O', 'X', 'X', 'X', 'O', 'C', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'X', 'O', 'O', 'X',
                'X', 'X', 'X', 'F', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X',
                'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'X', 'X', 'O', 'S', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'
            };
            equipableTreasureCoordinates = 88;
            consumableTreasureCoordinates = 37;
            initialCoordinates = 207;
            clueDesc = "I greeteth thee, burden'd one. I wisheth to bringeth a glimm'r of hope to thee. \nFrom whence thee beganeth, walketh towards wh're the darkness reclaim the landeth as the travelling lamp sets.";
            return new Level(levelName, beginDesc, endDesc, textColorNr, treasureEquipable, treasureConsumable, enemies, roomLayout, equipableTreasureCoordinates,
                             consumableTreasureCoordinates, initialCoordinates, clueDesc, secretEquipable, fountainPerks, playerRune, bossRune);

        case 2 :
            levelName = "Scientist's Lair";
            beginDesc = "There's only one way forward: down a hole. You pick up a rock and throw it down. \nAfter a few seconds, you hear a water splash. Would it be safe to jump down? \nWhat if the water is shallow? What if there's nothing but water? \nYou shake your head, trying to think away these thoughts. \nFinally, you find the courage to jump. After what felt like an eternity, you hit the water. \nYou surface and swim in a random direction, being too dark to see clearly. After a couple minutes you finally reach the shore. \nYou try to relight the torch using two rocks that you found nearby. After a long time you finally succeed. \nYou can now find your way around, and you see unlit torches along the cave walls which you light along the way.";
            endDesc = "As the scientist lies dead, you explore the surroundings to find your way forward. \nThere's a heavily boarded off section which you start to open up. \nWith every plank that you remove, more light penetrates the room. \nYou're glad that you'll finally see the sun again, though you realize that your quest is not over yet. \nYou wonder if you will have to fight any more of these unholy creatures and how has nobody died during the trial.";
            textColorNr = 11;
            treasureEquipable = equipableList->get_equipable_item(262);
            treasureConsumable = consumableList->get_consumable_item(52);
            secretEquipable = equipableList->get_equipable_item(11);
            playerRune = runeList.get_rune(2);
            bossRune = runeList.get_rune(12);
            enemies.push_back(enemyList->get_enemy(11));
            enemies.push_back(enemyList->get_enemy(12));
            enemies.push_back(enemyList->get_enemy(13));
            enemies.push_back(enemyList->get_enemy(14));
            enemies.push_back(enemyList->get_enemy(15));
            fountainPerks.push_back(perkList->get_perk(11));
            fountainPerks.push_back(perkList->get_perk(12));
            fountainPerks.push_back(perkList->get_perk(13));
            fountainPerks.push_back(perkList->get_perk(14));
            fountainPerks.push_back(perkList->get_perk(15));
            fountainPerks.push_back(perkList->get_perk(16));
            fountainPerks.push_back(perkList->get_perk(17));
            fountainPerks.push_back(perkList->get_perk(18));
            roomLayout = {
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'B', 'O', 'O', 'O', 'X', 'X',
                'X', 'R', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X',
                'X', 'O', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'X',
                'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'X',
                'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X',
                'X', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X',
                'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'T', 'X', 'X', 'X', 'X',
                'X', 'O', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'X',
                'X', 'O', 'O', 'F', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'X', 'X',
                'X', 'O', 'X', 'X', 'X', 'O', 'T', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X',
                'X', 'O', 'X', 'X', 'X', 'X', 'S', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X',
                'X', 'C', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'
            };
            equipableTreasureCoordinates = 171;
            consumableTreasureCoordinates = 115;
            initialCoordinates = 204;
            clueDesc = "I greeteth thee, burden'd one. I wisheth to bringeth a glimm'r of hope to thee. \nFrom whence thee w're shower'd by golden lighteth, walketh towards wh're the meek reside.";
            return new Level(levelName, beginDesc, endDesc, textColorNr, treasureEquipable, treasureConsumable, enemies, roomLayout, equipableTreasureCoordinates,
                             consumableTreasureCoordinates, initialCoordinates,  clueDesc, secretEquipable, fountainPerks, playerRune, bossRune);

        case 3 :
            levelName = "Labyrinth Forest";
            beginDesc = "You find yourself in an extraordinarily dense forest. So dense, in fact, that you are unable to do anything besides follow the paths that already exist. \nPreparing yourself for the horrors that you might encounter, you move forward.";
            endDesc = "With the gate guardian now dead, you ponder. What happened to those who failed to finish the trial? \nThey could not have died, else they would not have returned. Was their punishment of a different kind? \nWith many questions and no answers, you open the gates. A wave of intense heat immediately hits you as a fiery landscape shows itself. \nIt seems that you have reached the Volcano, but there are no ruins in sight.";
            textColorNr = 10;
            treasureEquipable = equipableList->get_equipable_item(263);
            treasureConsumable = consumableList->get_consumable_item(53);
            secretEquipable = equipableList->get_equipable_item(311);
            playerRune = runeList.get_rune(3);
            bossRune = runeList.get_rune(13);
            enemies.push_back(enemyList->get_enemy(21));
            enemies.push_back(enemyList->get_enemy(22));
            enemies.push_back(enemyList->get_enemy(23));
            enemies.push_back(enemyList->get_enemy(24));
            enemies.push_back(enemyList->get_enemy(25));
            fountainPerks.push_back(perkList->get_perk(21));
            fountainPerks.push_back(perkList->get_perk(22));
            fountainPerks.push_back(perkList->get_perk(23));
            fountainPerks.push_back(perkList->get_perk(24));
            fountainPerks.push_back(perkList->get_perk(25));
            fountainPerks.push_back(perkList->get_perk(26));
            fountainPerks.push_back(perkList->get_perk(27));
            fountainPerks.push_back(perkList->get_perk(28));
            fountainPerks.push_back(perkList->get_perk(29));
            roomLayout = {
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'B', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X',
                'X', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'O', 'X',
                'X', 'O', 'X', 'X', 'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X', 'T', 'O', 'X',
                'X', 'O', 'X', 'T', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X', 'X',
                'X', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O', 'X',
                'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X', 'F', 'X', 'O', 'X', 'X', 'O', 'X',
                'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X',
                'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X',
                'X', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'X', 'O', 'X', 'R', 'X',
                'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X',
                'X', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'S', 'X',
                'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X',
                'X', 'O', 'X', 'O', 'X', 'C', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'O', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'
            };
            equipableTreasureCoordinates = 63;
            consumableTreasureCoordinates = 57;
            initialCoordinates = 196;
            clueDesc = "I greeteth thee, burden'd one. I wisheth to bringeth a glimm'r of hope to thee. \nWhen thee ent'r the lodging with a windy stone thy mirr'r ent'rs the hidden one.";
            return new Level(levelName, beginDesc, endDesc, textColorNr, treasureEquipable, treasureConsumable, enemies, roomLayout, equipableTreasureCoordinates,
                             consumableTreasureCoordinates, initialCoordinates,  clueDesc, secretEquipable, fountainPerks, playerRune, bossRune);

        case 4 :
            levelName = "Volcano";
            beginDesc = "Heat is the only thing you can feel at this point. You're sweaty and feel very uncomfortable, but must press on nonetheless.";
            endDesc = "Knowing you do not have much of a choice, you follow him out of the volcanic ruins and prepare for a new life.";
            textColorNr = 12;
            treasureEquipable = equipableList->get_equipable_item(264);
            treasureConsumable = consumableList->get_consumable_item(54);
            secretEquipable = equipableList->get_equipable_item(271);
            playerRune = runeList.get_rune(4);
            enemyRune = runeList.get_rune(14);
            bossRune = runeList.get_rune(15);
            enemies.push_back(enemyList->get_enemy(31));
            enemies.push_back(enemyList->get_enemy(32));
            enemies.push_back(enemyList->get_enemy(33));
            enemies.push_back(enemyList->get_enemy(34));
            enemies.push_back(enemyList->get_enemy(35));
            fountainPerks.push_back(perkList->get_perk(31));
            fountainPerks.push_back(perkList->get_perk(32));
            fountainPerks.push_back(perkList->get_perk(33));
            fountainPerks.push_back(perkList->get_perk(34));
            fountainPerks.push_back(perkList->get_perk(35));
            fountainPerks.push_back(perkList->get_perk(36));
            fountainPerks.push_back(perkList->get_perk(37));
            roomLayout = {
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'X',
                'X', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'T', 'O', 'X', 'B', 'X',
                'X', 'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'X',
                'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X',
                'X', 'O', 'X', 'O', 'X', 'X', 'O', 'S', 'O', 'O', 'X', 'O', 'X', 'X', 'X',
                'X', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'C', 'X',
                'X', 'O', 'O', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X',
                'X', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X',
                'X', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'R', 'X',
                'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X',
                'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X',
                'X', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'X', 'O', 'O', 'O', 'X',
                'X', 'F', 'O', 'O', 'O', 'O', 'T', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'
            };
            equipableTreasureCoordinates = 201;
            consumableTreasureCoordinates = 40;
            initialCoordinates = 198;
            clueDesc = "I greeteth thee, burden'd one. I wisheth to bringeth a glimm'r of hope to thee. \nThe illusi'n lies in the he'rt of the volcano.";
            return new Level(levelName, beginDesc, endDesc, textColorNr, treasureEquipable, treasureConsumable, enemies, roomLayout, equipableTreasureCoordinates,
                             consumableTreasureCoordinates, initialCoordinates,  clueDesc, secretEquipable, fountainPerks, playerRune, bossRune, enemyRune);

        default :
            levelName = "ERROR_LEVEL";
            beginDesc = "ERROR_LEVEL";
            endDesc = "ERROR_LEVEL";
            textColorNr = 12;
            treasureEquipable = equipableList->get_equipable_item(0);
            treasureConsumable = consumableList->get_consumable_item(0);
            secretEquipable = equipableList->get_equipable_item(0);
            playerRune = runeList.get_rune(0);
            bossRune = runeList.get_rune(0);
            enemies.push_back(enemyList->get_enemy(0));
            enemies.push_back(enemyList->get_enemy(0));
            enemies.push_back(enemyList->get_enemy(0));
            enemies.push_back(enemyList->get_enemy(0));
            enemies.push_back(enemyList->get_enemy(0));
            fountainPerks.push_back(perkList->get_perk(0));
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
            equipableTreasureCoordinates = 0;
            consumableTreasureCoordinates = 0;
            initialCoordinates = 0;
            clueDesc = "ERROR_LEVEL";
            return new Level(levelName, beginDesc, endDesc, textColorNr, treasureEquipable, treasureConsumable, enemies, roomLayout, equipableTreasureCoordinates,
                             consumableTreasureCoordinates,  initialCoordinates, clueDesc, secretEquipable, fountainPerks, playerRune, bossRune);
    }
}

LevelList::~LevelList() {}
