#include "Rune.h"

Rune::Rune(std::string name, std::string description, std::vector<Ability*> abilities, int id)
          : name(name), description(description), abilities(abilities), id(id) {}

Ability* Rune::get_ability_at(int index) {
    return this->abilities.at(index);
}

void Rune::get_overview(bool shortened) {
    int index = 0;
    if(!shortened) {
        std::cout << this->name << ": " << this->description << "\n";
    }
    for(auto ability : abilities) {
        std::cout << ++index << " - " << ability->get_name() << ": " << ability->get_description() << " Use cost: " << ability->get_cost() << " charges.\n";
    }
}

int Rune::get_number_of_abilities() {
    return this->abilities.size();
}

std::string Rune::get_name() {
    return this->name;
}

std::string Rune::get_description() {
    return this->description;
}

int Rune::get_id() {
    return this->id;
}

Rune::~Rune() {}
