#include "RuneList.h"

RuneList::RuneList(){
    abilityList = AbilityList();
}

Rune* RuneList::get_rune(int index) {
    std::vector<Ability*> abilities;
    switch(index) {
        //case 1-10: player runes
        case 1 :
            abilities.push_back(abilityList.get_ability(1));
            abilities.push_back(abilityList.get_ability(2));
            abilities.push_back(abilityList.get_ability(3));
            return new Rune("Rune of earth", "A rune with brown markings that seem to be glowing faintly. It draws its power from the wielder's toughness.", abilities, index);

        case 2 :
            abilities.push_back(abilityList.get_ability(11));
            abilities.push_back(abilityList.get_ability(12));
            abilities.push_back(abilityList.get_ability(13));
            return new Rune("Rune of water", "A rune with blue markings from where water occasionally drips. It draws its power from the wielder's aggression.", abilities, index);

        case 3 :
            abilities.push_back(abilityList.get_ability(21));
            abilities.push_back(abilityList.get_ability(22));
            abilities.push_back(abilityList.get_ability(23));
            return new Rune("Rune of air", "A rune with white markings from where faint gusts of wind can be felt. It draws its power from the wielder's evasion.", abilities, index);

        case 4 :
            abilities.push_back(abilityList.get_ability(31));
            abilities.push_back(abilityList.get_ability(32));
            abilities.push_back(abilityList.get_ability(33));
            return new Rune("Rune of fire", "A rune with red markings that seem to produce heat. It draws its power from the wielder's strength.", abilities, index);

        //case 11-30: enemy runes
        case 11 :
            abilities.push_back(abilityList.get_ability(101));
            abilities.push_back(abilityList.get_ability(102));
            return new Rune("Rune of flesh", "", abilities, index);

        case 12 :
            abilities.push_back(abilityList.get_ability(111));
            abilities.push_back(abilityList.get_ability(112));
            return new Rune("Rune of alchemy", "", abilities, index);

        case 13 :
            abilities.push_back(abilityList.get_ability(121));
            abilities.push_back(abilityList.get_ability(122));
            return new Rune("Rune of the wild", "", abilities, index);

        case 14 :
            abilities.push_back(abilityList.get_ability(131));
            abilities.push_back(abilityList.get_ability(132));
            return new Rune("Inferior rune of fire", "", abilities, index);

        case 15 :
            abilities.push_back(abilityList.get_ability(141));
            abilities.push_back(abilityList.get_ability(142));
            return new Rune("Rune of the King", "", abilities, index);

        default :
            abilities.push_back(abilityList.get_ability(0));
            abilities.push_back(abilityList.get_ability(0));
            abilities.push_back(abilityList.get_ability(0));
            return new Rune("ERROR_RUNE", "ERROR_RUNE", abilities, index);
    }
}

RuneList::~RuneList() {}
