#include "Item.h"
#include <string.h>
#include <iostream>

Item::Item(std::string name, std::string findDescription, std::string useDescription, short int maxStack)
{
    this->name.clear();
    this->name += name;
    this->findDescription.clear();
    this->findDescription += findDescription;
    this->useDescription.clear();
    this->useDescription += useDescription;
    this->maxStack = maxStack;
}

void Item::set_name(std::string name) {
    this->name.clear();
    this->name += name;
}

std::string Item::get_name() {
    return this->name;
}

void Item::set_findDescription(std::string findDescription) {
    this->findDescription.clear();
    this->findDescription += findDescription;
}

std::string Item::get_findDescription() {
    return this->findDescription;
}

void Item::set_useDescription(std::string useDescription) {
    this->useDescription.clear();
    this->useDescription += useDescription;
}

std::string Item::get_useDescription() {
    return this->useDescription;
}

void Item::set_maxStack(short int maxStack) {
    this->maxStack = maxStack;
}

short int Item::get_maxStack() {
    return this->maxStack;
}

Item::~Item()
{
}
