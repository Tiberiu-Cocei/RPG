#include "PerkList.h"

PerkList::PerkList() {}

Perk* PerkList::get_perk(int index) {
    switch(index) {
        //1-10: Perks for the first level
        case 1 :
            return new Perk("Vitality I", "+10 max hp, 50 XP", 50, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1);
        case 2 :
            return new Perk("Attack I", "+5 attack, 50 XP", 50, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, -1);
        case 3 :
            return new Perk("Strength I", "+5 strength, 50 XP", 50, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, -1);
        case 4 :
            return new Perk("Defense I", "+5 defense, 50 XP", 50, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, -1);
        case 5 :
            return new Perk("Luck I", "+5 luck, 50 XP", 50, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, -1);
        case 6 :
            return new Perk("Evasion I", "+5 evasion, 50 XP", 50, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, -1);
        case 7 :
            return new Perk("Strong Back I", "+10 max weight, 75 XP", 75, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, -1);
        case 8 :
            return new Perk("Runner", "Doubles your chances of escaping. 100 XP", 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, -1);

        //11-20: Perks for the second level
        case 11 :
            return new Perk("Vitality II", "+15 max hp, 200 XP", 200, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1);
        case 12 :
            return new Perk("Sharpened Blade I", "+3 damage bonus, 300 XP", 300, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1);
        case 13 :
            return new Perk("Thick Skin I", "+3 damage reduction, 300 XP", 300, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1);
        case 14 :
            return new Perk("Strong Back II", "+15 max weight, 450 XP", 450, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, -1);
        case 15 :
            return new Perk("Combat Blessing I", "+3 attack, +3 strength, +3 defense, +3 luck, +3 evasion, 600 XP", 600, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, -1);
        case 16 :
            return new Perk("Nourishment", "+10 health recovered from all healing items, 750 XP", 750, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, -1);
        case 17 :
            return new Perk("Life steal I", "+15 health recovered after defeating an enemy, 1000 XP", 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, -1);
        case 18 :
            return new Perk("Executioner", "Deal bonus damage against foe with low health, 1250 XP", 1250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        default :
            return new Perk("ERROR_PERK", "ERROR_PERK", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1);
    }
}

PerkList::~PerkList() {}
