#include "Bracelet.h"

Bracelet::Bracelet() {
    this->runeWielded = NULL;
}

void Bracelet::add_rune(Rune* rune) {
    this->runes.push_back(rune);
}

void Bracelet::equip_rune(int index) {
    if(this->runes.size() == 0) {
        std::cout<<"You do not have any runes. Perhaps there are places of power where you could find them.\n";
    }
    else if(index <= 0 || index > this->runes.size()) {
        std::cout<<"Invalid index.\n";
    }
    else {
        this->runeWielded = this->runes.at(index - 1);
        std::cout<<"You have equipped the " + this->runeWielded->get_name() + ".\n";
    }
}

bool Bracelet::use_ability(int index, PlayerStats*& playerStats, Enemy*& enemy) {
    if(this->runeWielded == NULL) {
        std::cout<<"Your bracelet does not have any rune in it.\n";
        return false;
    }
    else if(index <= 0 || index > this->runeWielded->get_number_of_abilities()) {
        std::cout<<"Invalid ability index.\n";
        return false;
    }
    else {
        return this->runeWielded->get_ability_at(index - 1)->use_ability(playerStats, enemy);
    }
}

void Bracelet::get_overview() {
    if(this->runes.size() == 0) {
        std::cout<<"You do not have any runes. Perhaps there are places of power where you could find them.\n";
    }
    else {
        std::cout<<"\n";
        int index = 0;
        for(auto rune : this->runes) {
            std::cout<<++index<<" = ";
            rune->get_overview();
            std::cout<<"\n";
        }
    }
}

Rune* Bracelet::get_wielded_rune() {
    return this->runeWielded;
}

void Bracelet::get_save_data(std::string& saveData) {
    saveData += "7\n";
    if(runes.size() == 0) {
        saveData += "04";
    }
    else {
        for(auto rune : runes) {
            saveData += std::to_string(rune->get_id());
            if(rune == runeWielded) {
                saveData += " 1 ";
            }
            else {
                saveData += " 0 ";
            }
        }
    }
}

void Bracelet::load_runes(std::vector<Rune*> runes, int index) {
    this->runes = runes;
    this->runeWielded = runes.at(index);
}

Bracelet::~Bracelet() {}
