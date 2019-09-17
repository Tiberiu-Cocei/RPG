#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H

#include <Item.h>
#include "PlayerStats.h"
#include <string>

class ConsumableItem : public Item
{
    public:
        ConsumableItem(int, int, int, int, int, int, int, int, std::string, std::string, std::string, int);
        ~ConsumableItem();
        void find_item();
        void use_item(PlayerStats*&);
        int get_healing();
        void concat_stats(std::string&);

    private:
        int healing;
};

#endif
