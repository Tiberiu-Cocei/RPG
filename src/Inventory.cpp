#include "Inventory.h"
#include <iostream>
#include <string.h>

Inventory::Inventory() {
    this->currentWeight = 14;
    this->maxWeight = 20;
    consumableItems.push_back(new ConsumableItem(20, 0, 0, 0, 0, 0, 0, 1,
                               "Healing Potion I", "You have found a poorly made healing potion.",
                               "You drink the healing potion. It has a terrible taste and its texture almost makes you vomit."));
    consumableItems.push_back(new ConsumableItem(20, 0, 0, 0, 0, 0, 0, 1,
                               "Healing Potion I", "You have found a poorly made healing potion.",
                               "You drink the healing potion. It has a terrible taste and its texture almost makes you vomit."));
    consumableItems.push_back(new ConsumableItem(20, 0, 0, 0, 0, 0, 0, 1,
                               "Healing Potion I", "You have found a poorly made healing potion.",
                               "You drink the healing potion. It has a terrible taste and its texture almost makes you vomit."));
}

void Inventory::show_inventory() {
    int index = 1;
    std::cout<<"Current weight is " + std::to_string(currentWeight) + " out of " + std::to_string(maxWeight) + " kilograms.\n";
    for (auto &consumableItem : consumableItems)
    {
        std::cout<<std::to_string(index) + " - " + consumableItem->get_name() + "\n";
        index++;
    }
    for (auto &equipableItem : equipableItems)
    {
        std::cout<<std::to_string(index) + " - " + equipableItem->get_name() + "\n";
        index++;
    }
}

void Inventory::use_item(int index, Equipment*& equipment, PlayerStats*& playerStats) {
    int startingEquipableIndex = consumableItems.size() + 1;
    if(index > 0 && index < startingEquipableIndex) {
        ConsumableItem* item = consumableItems.at(index - 1);
        item->use_item(playerStats);
        consumableItems.erase(consumableItems.begin() + index - 1);
        currentWeight -= item->get_weight();
    }
    else if(index > 0 && index < startingEquipableIndex + equipableItems.size()) {
        EquipableItem* newItem = equipableItems.at(index - startingEquipableIndex);
        EquipableItem* oldItem = equipment->equip_item(newItem, playerStats);
        equipableItems.erase(equipableItems.begin() + index - startingEquipableIndex);
        equipableItems.push_back(oldItem);
    }
    else {
        std::cout<<"Invalid inventory index.\n";
    }
}

void Inventory::drop_item(int index) {
    int startingEquipableIndex = consumableItems.size() + 1;
    if(index > 0 && index < startingEquipableIndex) {
        ConsumableItem* item = consumableItems.at(index - 1);
        consumableItems.erase(consumableItems.begin() + index - 1);
        currentWeight -= item->get_weight();
        std::cout<<"Dropped the " + item->get_name() + ".\n";
    }
    else if(index > 0 && index < startingEquipableIndex + equipableItems.size()) {
        EquipableItem* item = equipableItems.at(index - startingEquipableIndex);
        equipableItems.erase(equipableItems.begin() + index - startingEquipableIndex);
        currentWeight -= item->get_weight();
        std::cout<<"Dropped the " + item->get_name() + ".\n";
    }
    else {
        std::cout<<"Invalid inventory index.\n";
    }
}

void Inventory::pickup_item(ConsumableItem* consumableItem) {
    if(currentWeight + consumableItem->get_weight() > maxWeight) {
        treat_max_weight_case(consumableItem->get_weight());
    }
    if(currentWeight + consumableItem->get_weight() <= maxWeight) {
        consumableItems.push_back(consumableItem);
        currentWeight += consumableItem->get_weight();
        std::cout<<"Picked up the " + consumableItem->get_name() + ".\n";
    }
}

void Inventory::pickup_item(EquipableItem* equipableItem) {
    if(currentWeight + equipableItem->get_weight() > maxWeight) {
        treat_max_weight_case(equipableItem->get_weight());
    }
    if(currentWeight + equipableItem->get_weight() <= maxWeight) {
        equipableItems.push_back(equipableItem);
        currentWeight += equipableItem->get_weight();
        std::cout<<"Picked up the " + equipableItem->get_name() + ".\n";
    }
}

void Inventory::treat_max_weight_case(int itemWeight) {
    std::cout<<"You carry too much already to pickup the item. Do you wish to drop item(s) to free inventory space? (Yes/no) ";
    std::string command;
    getline(std::cin,command);
    if(command.compare("Yes") == 0 || command.compare("yes") == 0) {
        std::string itemIndex;
        int itemIndexInt;
        while(currentWeight + itemWeight > maxWeight) {
            show_inventory();
            std::cout<<"\nEnter the number of the item you wish to drop. Type 'cancel' if you wish to stop. ";
            try {
                getline (std::cin, itemIndex);
                if(itemIndex.compare("Cancel") == 0 || itemIndex.compare("cancel") == 0) break;
                itemIndexInt = stoi(itemIndex);
                drop_item(itemIndexInt);
            } catch(const std::invalid_argument& error) {
                std::cerr << "Not a number.\n";
            }
        }
    }
}

void Inventory::gain_max_weight(int maxWeight) {
    this->maxWeight += maxWeight;
}

Inventory::~Inventory() {}
