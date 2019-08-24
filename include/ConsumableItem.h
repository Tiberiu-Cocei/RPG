#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H

#include <Item.h>
#include "PlayerStats.h"
#include <string>

class ConsumableItem : public Item
{
    public:
        ConsumableItem(short int, short int, short int, short int, short int, short int, short int, short int, std::string, std::string, std::string);
        ~ConsumableItem();
        void find_item();
        void use_item(PlayerStats*& playerStats);

    private:
        short int healing;
};

#endif
