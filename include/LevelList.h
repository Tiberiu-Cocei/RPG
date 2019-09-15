#ifndef LEVELLIST_H
#define LEVELLIST_H
#include "Level.h"
#include "ConsumableItemList.h"
#include "EquipableItemList.h"
#include "EnemyList.h"
#include "PerkList.h"
#include "RuneList.h"


class LevelList
{
    public:
        LevelList();
        ~LevelList();
        Level* get_level(int);

    private:
        EquipableItemList* equipableList;
        ConsumableItemList* consumableList;
        EnemyList* enemyList;
        PerkList* perkList;
        RuneList runeList;
};

#endif
