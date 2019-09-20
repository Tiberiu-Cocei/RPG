#include "EquipableItemList.h"

EquipableItemList::EquipableItemList() {}

EquipableItem* EquipableItemList::get_equipable_item(int index) {
    switch(index) {
        //1-50: helmets
        case 1 :
            return new EquipableItem(0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
                               "Leather helmet", "You have found a crudely made leather helmet.", "Equipped the leather helmet.", index);
        case 2 :
            return new EquipableItem(0, 0, 0, 0, 0, 2, 0, 2, 1, 1,
                               "Iron helmet", "You have found a damaged iron helmet.", "Equipped the iron helmet.", index);
        case 3 :
            return new EquipableItem(0, 1, 0, 0, 0, 3, 0, 3, 2, 1,
                               "Mithril helmet", "You have found an unmaintained mithril helmet.", "Equipped the mithril helmet.", index);
        case 4 :
            return new EquipableItem(0, 2, 0, 0, 0, 5, 0, 5, 2, 1,
                               "Wildsteel helmet", "You have found an wildsteel helmet. It seems to be imbued with magic.", "Equipped the wildsteel helmet.", index);

        //Secret room helmet
        case 11 :
            return new EquipableItem(0, 0, 5, 4, 5, 0, 3, 5, 0, 1,
                               "Void-leather helmet", "A peculiar helmet made out of what looks like leather shrouded by darkness.", "Equipped the Void-leather helmet.", index);

        //51-100: body armor
        case 51 :
            return new EquipableItem(0, 0, 0, 0, 0, 2, 0, 1, 2, 2,
                               "Leather body armor", "You have found a crudely made leather body armor.", "Equipped the leather body armor.", index);
        case 52 :
            return new EquipableItem(0, 1, 0, 0, 0, 4, 0, 3, 3, 2,
                               "Iron body armor", "You have found a damaged iron body armor.", "Equipped the iron body armor.", index);
        case 53 :
            return new EquipableItem(0, 2, 0, 0, 0, 6, 0, 5, 3, 2,
                               "Mithril body armor", "You have found an unmaintained mithril body armor.", "Equipped the mithril body armor.", index);
        case 54 :
            return new EquipableItem(0, 3, 0, 0, 0, 8, 0, 7, 3, 2,
                               "Wildsteel body armor", "You have found an wildsteel body armor. It seems to be imbued with magic.", "Equipped the wildsteel body armor.", index);

        //Secret room body armor
        case 61 :
            return new EquipableItem(0, 0, 10, 6, 8, 0, 4, 8, 0, 2,
                               "Void-leather body armor", "You have found a peculiar body armor. \nThe material feels very light, flexible and odd to the touch, unlike anything you have ever felt before.", "Equipped the Void-leather body armor.", index);

        //101-150: leg armor
        case 101 :
            return new EquipableItem(0, 0, 0, 0, 0, 1, 0, 1, 1, 3,
                               "Leather leg armor", "You have found a crudely made leather leg armor.", "Equipped the leather leg armor.", index);
        case 102 :
            return new EquipableItem(0, 0, 0, 0, 0, 3, 0, 3, 2, 3,
                               "Iron leg armor", "You have found a damaged iron leg armor.", "Equipped the iron leg armor.", index);
        case 103 :
            return new EquipableItem(0, 1, 0, 0, 0, 5, 0, 5, 2, 3,
                               "Mithril leg armor", "You have found an unmaintained mithril leg armor.", "Equipped the mithril leg armor.", index);
        case 104 :
            return new EquipableItem(0, 2, 0, 0, 0, 7, 0, 7, 2, 3,
                               "Wildsteel leg armor", "You have found an wildsteel leg armor. It seems to be imbued with magic.", "Equipped the wildsteel leg armor.", index);

        //151-200: gloves
        case 151 :
            return new EquipableItem(0, 0, 0, 1, 0, 1, 0, 0, 1, 4,
                               "Leather gloves", "You have found a pair of crudely made leather gloves.", "Equipped the leather gloves.", index);
        case 152 :
            return new EquipableItem(0, 0, 0, 2, 0, 2, 1, 0, 1, 4,
                               "Iron gloves", "You have found a pair of damaged iron gloves.", "Equipped the iron gloves.", index);
        case 153 :
            return new EquipableItem(0, 0, 0, 3, 0, 3, 2, 0, 2, 4,
                               "Mithril gloves", "You have found a pair of unmaintained mithril gloves.", "Equipped the mithril gloves.", index);
        case 154 :
            return new EquipableItem(0, 1, 0, 5, 0, 4, 4, 0, 2, 4,
                               "Wildsteel gloves", "You have found a pair of wildsteel gloves. They seem to be imbued with magic.", "Equipped the wildsteel gloves.", index);

        //201-250: boots
        case 201 :
            return new EquipableItem(0, 0, 0, 0, 0, 0, 0, 1, 1, 5,
                               "Leather boots", "You have found a pair of crudely made leather boots.", "Equipped the leather boots.", index);
        case 202 :
            return new EquipableItem(0, 0, 0, 0, 0, 1, 0, 3, 2, 5,
                               "Iron boots", "You have found a pair of damaged iron boots.", "Equipped the iron boots.", index);
        case 203 :
            return new EquipableItem(0, 0, 0, 0, 0, 2, 0, 5, 2, 5,
                               "Mithril boots", "You have found a pair of unmaintained mithril boots.", "Equipped the mithril boots.", index);
        case 204 :
            return new EquipableItem(0, 1, 0, 0, 0, 4, 0, 7, 2, 5,
                               "Wildsteel boots", "You have found a pair of wildsteel boots. They seem to be imbued with magic.", "Equipped the wildsteel boots.", index);

        //251-300: weapons
        case 251 :
            return new EquipableItem(1, 0, 0, 2, 4, 0, 1, 0, 2, 6,
                               "Copper sword", "You have found a copper sword. It does not look like it's in good condition.", "Equipped the copper sword.", index);
        case 252 :
            return new EquipableItem(3, 0, 0, 5, 7, 0, 3, 0, 3, 6,
                               "Iron sword", "You have found an iron sword. It looks sharp enough to do the deed.", "Equipped the iron sword.", index);
        case 253 :
            return new EquipableItem(5, 0, 0, 9, 10, 0, 5, 0, 3, 6,
                               "Mithril sword", "You have found a mithril sword. It looks unmaintained.", "Equipped the mithril sword.", index);
        case 254 :
            return new EquipableItem(7, 0, 0, 11, 14, 0, 8, 0, 3, 6,
                               "Wildsteel sword", "You have found an wildsteel sword. It seems to be imbued with magic.", "Equipped the wildsteel sword.", index);

        //Treasure room weapons
        case 261 :
            return new EquipableItem(2, 0, 0, 2, 0, 0, 10, 10, 1, 6,
                               "Golden dagger", "You have found a shiny golden dagger. It looks very sharp.", "Equipped the golden dagger.", index);
        case 262 :
            return new EquipableItem(6, 0, 0, -5, 16, 0, -3, -5, 7, 6,
                               "Giant hammer", "You have found an enormous hammer. Anything hit by it will definitely feel it.", "Equipped the giant hammer.", index);
        case 263 :
            return new EquipableItem(6, 0, 0, 8, 10, 0, 13, 5, 2, 6,
                               "Blessed sword", "You have found a sword with a shining blade. It seems to have been blessed.", "Equipped the blessed sword.", index);

        //301-350: shields
        case 301 :
            return new EquipableItem(0, 1, 0, 0, 0, 2, 0, 1, 2, 7,
                               "Copper shield", "You have found a copper shield. It does not look like it's in good condition.", "Equipped the copper shield.", index);
        case 302 :
            return new EquipableItem(0, 2, 0, 0, 0, 5, 0, 2, 3, 7,
                               "Iron shield", "You have found an iron shield. A bit rusty but overall in decent condition.", "Equipped the iron shield.", index);
        case 303 :
            return new EquipableItem(0, 3, 0, 0, 0, 6, 0, 3, 3, 7,
                               "Mithril shield", "You have found a mithril shield. Seems to be in good condition.", "Equipped the mithril shield.", index);
        case 304 :
            return new EquipableItem(0, 5, 0, 0, 0, 8, 0, 5, 3, 7,
                               "Wildsteel shield", "You have found an wildsteel shield. Seems to be imbued with magic.", "Equipped the wildsteel shield.", index);

        //Secret room shield
        case 311 :
            return new EquipableItem(5, 0, 10, 6, 7, 0, 5, 10, 0, 7,
                               "Void-steel defender", "You have found a parrying dagger made out of void-steel. It very light and durable.", "Equipped the void-steel defender", index);

        default :
            return new EquipableItem(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "ERROR_ITEM", "ERROR_ITEM", "ERROR_ITEM", index);
    }
}

EquipableItemList::~EquipableItemList() {}
