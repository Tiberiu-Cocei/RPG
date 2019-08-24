#include "EquipableItemList.h"

EquipableItemList::EquipableItemList()
{
}

EquipableItem* EquipableItemList::get_equipable_item(short int index) {
    switch(index) {
        //1-50: helmets
        case 1 :
            return new EquipableItem(0, 0, 0, 0, 0, 0, 2, 1, 1, 1,
                               "Leather helmet", "You have found a crudely made leather helmet.", "Equipped the leather helmet.");
        case 2 :
            return new EquipableItem(0, 0, 0, 0, 0, 2, 2, 2, 1, 1,
                               "Iron helmet", "You have found a damaged iron helmet.", "Equipped the iron helmet.");

        //51-100: body armor
        case 51 :
            return new EquipableItem(0, 0, 0, 0, 0, 2, 0, 1, 2, 2,
                               "Leather body armor", "You have found a crudely made leather body armor.", "Equipped the leather body armor.");

        //101-150: leg armor
        case 101 :
            return new EquipableItem(0, 0, 0, 0, 0, 1, 0, 1, 1, 3,
                               "Leather leg armor", "You have found a crudely made leather leg armor.", "Equipped the leather leg armor.");

        //151-200: gloves
        case 151 :
            return new EquipableItem(0, 0, 0, 1, 0, 1, 0, 0, 1, 4,
                               "Leather gloves", "You have found a pair of crudely made leather gloves.", "Equipped the leather gloves.");

        //201-250: boots
        case 201 :
            return new EquipableItem(0, 0, 0, 0, 0, 0, 0, 1, 1, 5,
                               "Leather boots", "You have found a pair of crudely made leather boots.", "Equipped the leather boots.");

        //251-300: weapons
        case 251 :
            return new EquipableItem(1, 0, 0, 2, 2, 0, 0, 0, 3, 6,
                               "Copper sword", "You have found a copper sword. It does not look like it's in good condition.", "Equipped the copper sword.");

        //301-350: shields
        case 301 :
            return new EquipableItem(0, 1, 0, 0, 0, 2, 0, 1, 2, 7,
                               "Copper shield", "You have found a copper shield. It does not look like it's in good condition.", "Equipped the copper shield.");

        default :
            return new EquipableItem(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "ERROR_ITEM", "ERROR_ITEM", "ERROR_ITEM");
    }
}

EquipableItemList::~EquipableItemList()
{
}
