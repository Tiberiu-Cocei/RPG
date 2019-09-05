#ifndef ENEMYLIST_H
#define ENEMYLIST_H
#include "Enemy.h"
#include <vector>
#include <iostream>
#include <string.h>
#include "EnemyStats.h"
#include "EquipableItemList.h"
#include "ConsumableItemList.h"

class EnemyList
{
    public:
        EnemyList();
        ~EnemyList();
        Enemy* get_enemy(int);
    private:
        ConsumableItemList* consumableItemList;
        EquipableItemList* equipableItemList;
};

#endif
