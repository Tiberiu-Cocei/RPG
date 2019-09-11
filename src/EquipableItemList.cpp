#include "EquipableItemList.h"

EquipableItemList::EquipableItemList()
{
}

EquipableItem* EquipableItemList::get_equipable_item(int index) {
    switch(index) {
        //1-50: helmets
        case 1 :
            return new EquipableItem(0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
                               "Leather helmet", "You have found a crudely made leather helmet.", "Equipped the leather helmet.");
        case 2 :
            return new EquipableItem(0, 0, 0, 0, 0, 2, 0, 2, 1, 1,
                               "Iron helmet", "You have found a damaged iron helmet.", "Equipped the iron helmet.");
        case 3 :
            return new EquipableItem(0, 1, 0, 0, 0, 3, 0, 3, 2, 1,
                               "Mithril helmet", "You have found an unmaintained mithril helmet.", "Equipped the mithril helmet.");

        //Secret room helmet
        case 11 :
            return new EquipableItem(0, 0, 5, 3, 3, 0, 2, 5, 0, 1,
                               "Void-leather helmet", "A peculiar helmet made out of what looks like leather shrouded by darkness.", "Equipped the Void-leather helmet.");

        //51-100: body armor
        case 51 :
            return new EquipableItem(0, 0, 0, 0, 0, 2, 0, 1, 2, 2,
                               "Leather body armor", "You have found a crudely made leather body armor.", "Equipped the leather body armor.");
        case 52 :
            return new EquipableItem(0, 1, 0, 0, 0, 4, 0, 3, 3, 2,
                               "Iron body armor", "You have found a damaged iron body armor.", "Equipped the iron body armor.");
        case 53 :
            return new EquipableItem(0, 2, 0, 0, 0, 6, 0, 5, 3, 2,
                               "Mithril body armor", "You have found an unmaintained mithril body armor.", "Equipped the mithril body armor.");

        //Secret room body armor
        case 61 :
            return new EquipableItem(0, 0, 10, 4, 3, 0, 3, 8, 0, 2,
                               "Void-leather body armor", "You have found a peculiar body armor. \nThe material feels very light, flexible and odd to the touch, unlike anything you have ever felt before.", "Equipped the Void-leather body armor.");

        //101-150: leg armor
        case 101 :
            return new EquipableItem(0, 0, 0, 0, 0, 1, 0, 1, 1, 3,
                               "Leather leg armor", "You have found a crudely made leather leg armor.", "Equipped the leather leg armor.");
        case 102 :
            return new EquipableItem(0, 0, 0, 0, 0, 3, 0, 3, 2, 3,
                               "Iron leg armor", "You have found a damaged iron leg armor.", "Equipped the iron leg armor.");
        case 103 :
            return new EquipableItem(0, 1, 0, 0, 0, 5, 0, 5, 2, 3,
                               "Mithril leg armor", "You have found an unmaintained mithril leg armor.", "Equipped the mithril leg armor.");

        //151-200: gloves
        case 151 :
            return new EquipableItem(0, 0, 0, 1, 0, 1, 0, 0, 1, 4,
                               "Leather gloves", "You have found a pair of crudely made leather gloves.", "Equipped the leather gloves.");
        case 152 :
            return new EquipableItem(0, 0, 0, 2, 0, 2, 1, 0, 1, 4,
                               "Iron gloves", "You have found a pair of damaged iron gloves.", "Equipped the iron gloves.");
        case 153 :
            return new EquipableItem(0, 0, 0, 3, 0, 3, 2, 0, 2, 4,
                               "Mithril gloves", "You have found a pair of unmaintained mithril gloves.", "Equipped the mithril gloves.");

        //201-250: boots
        case 201 :
            return new EquipableItem(0, 0, 0, 0, 0, 0, 0, 1, 1, 5,
                               "Leather boots", "You have found a pair of crudely made leather boots.", "Equipped the leather boots.");
        case 202 :
            return new EquipableItem(0, 0, 0, 0, 0, 1, 0, 3, 2, 5,
                               "Iron boots", "You have found a pair of damaged iron boots.", "Equipped the iron boots.");
        case 203 :
            return new EquipableItem(0, 0, 0, 0, 0, 2, 0, 5, 2, 5,
                               "Mithril boots", "You have found a pair unmaintained mithril boots.", "Equipped the mithril boots.");

        //251-300: weapons
        case 251 :
            return new EquipableItem(1, 0, 0, 2, 4, 0, 1, 0, 2, 6,
                               "Copper sword", "You have found a copper sword. It does not look like it's in good condition.", "Equipped the copper sword.");
        case 252 :
            return new EquipableItem(3, 0, 0, 5, 7, 0, 3, 0, 3, 6,
                               "Iron sword", "You have found an iron sword. It looks sharp enough to do the deed.", "Equipped the iron sword.");
        case 253 :
            return new EquipableItem(5, 0, 0, 9, 10, 0, 5, 0, 3, 6,
                               "Mithril sword", "You have found a mithril sword. It looks unmaintained.", "Equipped the mithril sword.");

        //Treasure room weapons
        case 261 :
            return new EquipableItem(2, 0, 0, 2, 0, 0, 10, 10, 1, 6,
                               "Golden dagger", "You have found a shiny golden dagger. It looks very sharp.", "Equipped the golden dagger.");
        case 262 :
            return new EquipableItem(6, 0, 0, 2, 7, 0, 0, 0, 9, 6,
                               "Giant hammer", "You have found an enormous hammer. Anything hit by it will definitely feel it.", "Equipped the giant hammer.");

        //301-350: shields
        case 301 :
            return new EquipableItem(0, 1, 0, 0, 0, 2, 0, 1, 2, 7,
                               "Copper shield", "You have found a copper shield. It does not look like it's in good condition.", "Equipped the copper shield.");
        case 302 :
            return new EquipableItem(0, 2, 0, 0, 0, 5, 0, 2, 3, 7,
                               "Iron shield", "You have found an iron shield. A bit rusty but overall in decent condition.", "Equipped the iron shield.");
        case 303 :
            return new EquipableItem(0, 3, 0, 0, 0, 6, 0, 3, 3, 7,
                               "Mithril shield", "You have found a mithril shield. Seems to be in good condition.", "Equipped the mithril shield.");

        default :
            return new EquipableItem(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "ERROR_ITEM", "ERROR_ITEM", "ERROR_ITEM");
    }
}

EquipableItemList::~EquipableItemList()
{
}
