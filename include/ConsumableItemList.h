#ifndef CONSUMABLEITEMLIST_H
#define CONSUMABLEITEMLIST_H
#include "ConsumableItem.h"

class ConsumableItemList
{
    public:
        ConsumableItemList();
        ~ConsumableItemList();
        ConsumableItem* get_consumable_item(int);
};

#endif
