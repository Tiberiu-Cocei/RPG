#include "EnemyList.h"

EnemyList::EnemyList()
{
    consumableItemList = new ConsumableItemList();
    equipableItemList = new EquipableItemList();
}

Enemy* EnemyList::get_enemy(int index) {
    EnemyStats* enemyStats;
    std::vector<ConsumableItem*> consumableDrops;
    std::vector<EquipableItem*> equipableDrops;
    switch(index) {
        //1-10: first level
        case 1:
            enemyStats = new EnemyStats(30, 15, 29, 11, 17);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(102));
            consumableDrops.push_back(consumableItemList->get_consumable_item(1));
            consumableDrops.push_back(consumableItemList->get_consumable_item(71));
            equipableDrops.push_back(equipableItemList->get_equipable_item(2));
            equipableDrops.push_back(equipableItemList->get_equipable_item(152));
            return new Enemy(enemyStats, "Goblin", "You notice something green hide between the rocks. You realize that it's a goblin and prepare for battle!",
                             "The goblin falls down, dying before hitting the ground.", consumableDrops, equipableDrops, 17, 10);
        case 2:
            enemyStats = new EnemyStats(25, 18, 28, 5, 28);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(1));
            consumableDrops.push_back(consumableItemList->get_consumable_item(71));
            equipableDrops.push_back(equipableItemList->get_equipable_item(152));
            equipableDrops.push_back(equipableItemList->get_equipable_item(202));
            return new Enemy(enemyStats, "Skeleton", "From the darkness of the cave something leaps towards you. You realize that it's a skeleton, something that should not be capable of standing let alone fighting. You prepare yourself for battle!",
                             "The bones that form the skeleton break and fall to the ground.", consumableDrops, equipableDrops, 18, 10);
        case 3:
            enemyStats = new EnemyStats(45, 12, 36, 26, 11);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(101));
            consumableDrops.push_back(consumableItemList->get_consumable_item(1));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            equipableDrops.push_back(equipableItemList->get_equipable_item(102));
            equipableDrops.push_back(equipableItemList->get_equipable_item(302));
            return new Enemy(enemyStats, "Giant Rat", "You hear loud squeaking noises come from somewhere near you. You prepare yourself for battle. Moments later, a giant rat jumps in front of you!",
                             "The giant rat falls over, dying shortly after.", consumableDrops, equipableDrops, 21, 20);
        case 4:
            enemyStats = new EnemyStats(60, 23, 37, 16, 23);
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(104));
            consumableDrops.push_back(consumableItemList->get_consumable_item(1));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            equipableDrops.push_back(equipableItemList->get_equipable_item(52));
            equipableDrops.push_back(equipableItemList->get_equipable_item(252));
            return new Enemy(enemyStats, "Hobgoblin", "You see a weakly goblin trip on a rock and fall to the ground. It turns around whimpering and pleading, to your confusion. Then you see the reason: a Hobgoblin towering above it. It raises its weapon to kill the goblin when it notices you. The goblin escapes, and the hobgoblin charges towards you. You prepare for combat!",
                             "The hobgoblin falls with a loud thud, never to get up again.", consumableDrops, equipableDrops, 26, 35);
        case 5:
            enemyStats = new EnemyStats(150, 25, 45, 25, 15);
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            consumableDrops.push_back(consumableItemList->get_consumable_item(61));
            equipableDrops.push_back(equipableItemList->get_equipable_item(252));
            equipableDrops.push_back(equipableItemList->get_equipable_item(252));
            return new Enemy(enemyStats, "Mass of flesh", "You're hit by a strong scent of rotting flesh. Before you find the source of the odor an appendage narrowly misses you and loudly hits the floor. That's when you see it: a massive mass of flesh, contracting and moving unnaturally. You prepare for battle!",
                             "The mass of flesh dissolves into a puddle of bones and blood.", consumableDrops, equipableDrops, 37, 500);

        //11-20: second level
        case 11:
            enemyStats = new EnemyStats(50, 26, 36, 19, 27);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(102));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(72));
            equipableDrops.push_back(equipableItemList->get_equipable_item(3));
            equipableDrops.push_back(equipableItemList->get_equipable_item(153));
            return new Enemy(enemyStats, "Abomination", "You see something run towards you. It has many limbs and its flesh is mutated. You prepare for battle!",
                             "The abomination falls down and starts convulsing. You put it out of its misery with your weapon.", consumableDrops, equipableDrops, 26, 50);
        case 12:
            enemyStats = new EnemyStats(60, 35, 32, 15, 38);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(72));
            equipableDrops.push_back(equipableItemList->get_equipable_item(153));
            equipableDrops.push_back(equipableItemList->get_equipable_item(203));
            return new Enemy(enemyStats, "Man-spider", "Loud chewing noises can be heard from somewhere close to you. You get closer to investigate, and find a man with six hands, using them to stand. It twists its head towards you, pausing its feast. You prepare for combat!",
                             "With its limbs cut off, the man-spider falls down, bleeding out.", consumableDrops, equipableDrops, 30, 50);
        case 13:
            enemyStats = new EnemyStats(75, 33, 40, 28, 26);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            equipableDrops.push_back(equipableItemList->get_equipable_item(103));
            equipableDrops.push_back(equipableItemList->get_equipable_item(303));
            return new Enemy(enemyStats, "Chimera", "A creature jumps down from one of the openings in the cave above, landing meters in front of you. It looks as if many beasts were merged into one: a chimera. You prepare for combat!",
                             "The chimera falls apart into a puddle of flesh and bones.", consumableDrops, equipableDrops, 33, 75);
        case 14:
            enemyStats = new EnemyStats(80, 28, 43, 35, 26);
            consumableDrops.push_back(consumableItemList->get_consumable_item(103));
            consumableDrops.push_back(consumableItemList->get_consumable_item(104));
            consumableDrops.push_back(consumableItemList->get_consumable_item(2));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            equipableDrops.push_back(equipableItemList->get_equipable_item(53));
            equipableDrops.push_back(equipableItemList->get_equipable_item(253));
            return new Enemy(enemyStats, "Giant Mutant", "You hear something charge towards you. You roll to the side and avoid the attack. You quickly get up and see a giant humanoid being, with limbs that seem to be fused together from many different beings. You prepare for battle!",
                             "The giant mutant falls down, never to get up again.", consumableDrops, equipableDrops, 37, 100);
        case 15:
            enemyStats = new EnemyStats(225, 42, 47, 33, 32);
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            consumableDrops.push_back(consumableItemList->get_consumable_item(62));
            equipableDrops.push_back(equipableItemList->get_equipable_item(253));
            equipableDrops.push_back(equipableItemList->get_equipable_item(253));
            return new Enemy(enemyStats, "Mad scientist", "\"So you're the one who has been killing my creations. Beautiful, weren't they? Until you killed them, that is. It's alright, I can start over again. And I shall begin with you!\" Once the scientist finished his sentence, he started to convulse aggressively. With each twist, his body mutated and grew in size.",
                             "\"I was.. beautiful. You could have been too..\" The scientist finally succumbs to his wounds, the way forward now open.", consumableDrops, equipableDrops, 53, 1500);
    }
}

EnemyList::~EnemyList()
{
}
