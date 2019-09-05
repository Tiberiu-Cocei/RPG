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
            enemyStats = new EnemyStats(30, 10, 23, 7, 12);
            consumableDrops.push_back(consumableItemList->get_consumable_item(100));
            consumableDrops.push_back(consumableItemList->get_consumable_item(102));
            consumableDrops.push_back(consumableItemList->get_consumable_item(1));
            consumableDrops.push_back(consumableItemList->get_consumable_item(71));
            equipableDrops.push_back(equipableItemList->get_equipable_item(2));
            equipableDrops.push_back(equipableItemList->get_equipable_item(152));
            return new Enemy(enemyStats, "Goblin", "You notice something green hide between the rocks. You realize that it's a goblin and prepare for battle!",
                             "The goblin falls down, dying before hitting the ground.", consumableDrops, equipableDrops, 13, 10);
    }
}

EnemyList::~EnemyList()
{
}
