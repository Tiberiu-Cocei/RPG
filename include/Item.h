#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "PlayerStats.h"

class Item
{
    public:
        Item(std::string, std::string, std::string);
        virtual ~Item();
        void set_name(std::string);
        std::string get_name();
        void set_findDescription(std::string);
        std::string get_findDescription();
        void set_useDescription(std::string);
        std::string get_useDescription();
        virtual void use_item(PlayerStats playerStats) = 0;

    protected:
        std::string name;
        std::string findDescription;
        std::string useDescription;
};

#endif