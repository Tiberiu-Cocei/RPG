#ifndef INVENTORY_H
#define INVENTORY_H
#include "EquipableItem.h"
#include "ConsumableItem.h"
#include "Equipment.h"
#include "PlayerStats.h"
#include <vector>
#include <unordered_map>

class Inventory
{
    public:
        Inventory();
        ~Inventory();
        void show_inventory();
        void use_item(int, Equipment*&, PlayerStats*&);
        void drop_item(int);
        void pickup_item(ConsumableItem*);
        void pickup_item(EquipableItem*);
        void gain_max_weight(int);
        void get_save_data(std::string&);
        void load_weight(int, int);
        void load_consumable_items(std::vector<ConsumableItem*>);
        void load_equipable_items(std::vector<EquipableItem*>);

    private:
        std::vector<ConsumableItem*> consumableItems;
        std::vector<EquipableItem*> equipableItems;
        int currentWeight;
        int maxWeight;
        void treat_max_weight_case(int);
};

#endif
