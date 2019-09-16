#include "ConsumableItemList.h"

ConsumableItemList::ConsumableItemList() {}

ConsumableItem* ConsumableItemList::get_consumable_item(int index) {
    switch(index) {
        //1-50: healing potions
        case 1 :
            return new ConsumableItem(20, 0, 0, 0, 0, 0, 0, 1,
                               "Healing Potion I", "You have found a poorly made healing potion.",
                               "You drink the healing potion. It has a terrible taste and its texture almost makes you vomit.");
        case 2 :
            return new ConsumableItem(35, 0, 0, 0, 0, 0, 0, 1,
                               "Healing Potion II", "You have found a recreation of a healing potion.",
                               "You drink the healing potion. It has a bland taste and watery texture.");

        //51-100: combat buffs
        case 51 :
            return new ConsumableItem(0, 0, 3, 5, 3, 2, 3, 1,
                               "Combat Potion I", "You have found a poorly made combat potion.",
                               "You drink the combat potion. You feel your senses sharpen slightly.");
        case 52 :
            return new ConsumableItem(0, 5, 7, 9, 6, 4, 5, 1,
                               "Combat Potion II", "You have found a recreation of a combat potion.",
                               "You drink the combat potion. You feel stronger and faster.");

        case 61 :
            return new ConsumableItem(15, 0, 2, 4, 0, 1, 0, 1,
                               "Striker Potion I", "You have found a poorly made striker potion.",
                               "You drink the striker potion. You feel a bit stronger.");
        case 62 :
            return new ConsumableItem(25, 0, 6, 7, 0, 3, 0, 1,
                               "Striker Potion II", "You have found a recreation of a striker potion.",
                               "You drink the striker potion. You feel stronger.");

        case 71 :
            return new ConsumableItem(20, 5, 0, 0, 3, 0, 3, 1,
                               "Defender Potion I", "You have found a poorly made defender potion.",
                               "You drink the defender potion. You feel a bit more resilient.");
        case 72 :
            return new ConsumableItem(35, 15, 0, 0, 6, 0, 5, 1,
                               "Defender Potion II", "You have found a recreation of a defender potion.",
                               "You drink the defender potion. You become more evasive and you feel your skin become thicker.");

        //100-200: filler drops
        case 100 :
            return new ConsumableItem(9, 0, 0, 0, 0, 0, 0, 1,
                               "Apple", "You have found an apple.",
                               "You eat the apple. It does not taste as bad as you thought it would.");
        case 101 :
            return new ConsumableItem(12, 0, 0, 0, 0, 0, 0, 1,
                               "Piece of ham", "You have found a piece of ham.",
                               "You eat the ham. Besides being slightly undercooked, it made for a decent meal.");
        case 102 :
            return new ConsumableItem(7, 0, 0, 0, 0, 0, 0, 1,
                               "Banana", "You have found a banana.",
                               "You eat the banana.");
        case 103 :
            return new ConsumableItem(10, 0, 0, 0, 0, 0, 0, 1,
                               "Bread", "You have found a piece of bread.",
                               "You eat the bread. You're thankful that it did not have any mold.");
        case 104 :
            return new ConsumableItem(15, 0, 0, 0, 0, 0, 0, 1,
                               "Cheese Roll", "You have found a cheese roll.",
                               "You eat the entire roll. It is perplexing how you manage to do so in such a short amount of time.");

        default :
            return new ConsumableItem(0, 0, 0, 0, 0, 0, 0, 0, "ERROR_ITEM", "ERROR_ITEM", "ERROR_ITEM");
    }
}

ConsumableItemList::~ConsumableItemList() {}
