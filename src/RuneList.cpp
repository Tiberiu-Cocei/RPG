#include "RuneList.h"

RuneList::RuneList(){
    abilityList = AbilityList();
}

Rune* RuneList::get_rune(int index) {
    std::vector<Ability*> abilities;
    switch(index) {
        case 1 :
            abilities.push_back(abilityList.get_ability(1));
            abilities.push_back(abilityList.get_ability(2));
            abilities.push_back(abilityList.get_ability(3));
            return new Rune("Rune of earth", "A rune with brown markings that seem to be glowing faintly. It draws its power from the wielder's toughness.", abilities);

        case 2 :
            abilities.push_back(abilityList.get_ability(11));
            abilities.push_back(abilityList.get_ability(12));
            abilities.push_back(abilityList.get_ability(13));
            return new Rune("Rune of water", "A rune with blue markings from where water occasionally drips. It draws its power from the wielder's aggression.", abilities);

        case 3 :
            abilities.push_back(abilityList.get_ability(21));
            abilities.push_back(abilityList.get_ability(22));
            abilities.push_back(abilityList.get_ability(23));
            return new Rune("Rune of air", "A rune with white markings from where faint gusts of wind can be felt. It draws its power from the wielder's evasion.", abilities);

        case 4 :
            abilities.push_back(abilityList.get_ability(31));
            abilities.push_back(abilityList.get_ability(32));
            abilities.push_back(abilityList.get_ability(33));
            return new Rune("Rune of fire", "A rune with red markings that seem to produce heat. It draws its power from the wielder's strength.", abilities);

        default :
            abilities.push_back(abilityList.get_ability(0));
            abilities.push_back(abilityList.get_ability(0));
            abilities.push_back(abilityList.get_ability(0));
            return new Rune("ERROR_RUNE", "ERROR_RUNE", abilities);
    }
}

RuneList::~RuneList() {}
