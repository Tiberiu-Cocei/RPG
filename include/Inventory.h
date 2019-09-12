#ifndef INVENTORY_H
#define INVENTORY_H
#include "EquipableItem.h"
#include "ConsumableItem.h"
#include "Equipment.h"
#include <vector>

class Inventory
{
    public:
        Inventory();
        ~Inventory();
        void show_inventory();
        void use_item(int, Equipment*&);
        void drop_item(int);
        void pickup_item(ConsumableItem*);
        void pickup_item(EquipableItem*);
        void gain_max_weight(int);

    private:
        std::vector<ConsumableItem*> consumableItems;
        std::vector<EquipableItem*> equipableItems;
        int currentWeight;
        int maxWeight;
        void treat_max_weight_case(int);
};

#endif
