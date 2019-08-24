#ifndef EQUIPABLEITEMLIST_H
#define EQUIPABLEITEMLIST_H
#include "EquipableItem.h"

class EquipableItemList
{
    public:
        EquipableItemList();
        ~EquipableItemList();
        EquipableItem* get_equipable_item(short int index);
};

#endif
