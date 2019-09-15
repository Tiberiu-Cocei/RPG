#include "Rune.h"

Rune::Rune(std::string name, std::string description, std::vector<Ability*> abilities)
          : name(name), description(description), abilities(abilities) {}

Ability* Rune::get_ability_at(int index) {
    return this->abilities.at(index);
}

void Rune::get_overview() {
    int index = 0;
    std::cout << this->name << ": " << this->description << "\n";
    for(auto ability : abilities) {
        std::cout << ++index << " - " << ability->get_name() << ": " << ability->get_description() << " Use cost: " << ability->get_cost() << " charges.\n";
    }
}

int Rune::get_number_of_abilities() {
    return this->abilities.size();
}

Rune::~Rune() {}
