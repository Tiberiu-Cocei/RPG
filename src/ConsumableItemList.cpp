#include "ConsumableItemList.h"

ConsumableItemList::ConsumableItemList()
{
}

ConsumableItem* ConsumableItemList::get_consumable_item(short int index) {
    switch(index) {
        //1-50: healing potions
        case 1 :
            return new ConsumableItem(20, 0, 0, 0, 0, 0, 0, 1,
                               "Healing Potion I", "You have found a poorly made healing potion.",
                               "You drink the healing potion. It has a terrible taste and its texture almost makes you vomit.");

        //51-100: combat buffs
        case 51 :
            return new ConsumableItem(0, 0, 3, 5, 3, 0, 3, 1,
                               "Combat Potion I", "You have found a poorly made combat potion.",
                               "You drink the combat potion. You feel your senses sharpen slightly.");

        default :
            return new ConsumableItem(0, 0, 0, 0, 0, 0, 0, 0, "ERROR_ITEM", "ERROR_ITEM", "ERROR_ITEM");
    }
}

ConsumableItemList::~ConsumableItemList()
{
}
