#ifndef SAVER_H
#define SAVER_H
#include <iostream>
#include <string.h>
#include <vector>
#include <array>
#include "Equipment.h"
#include "Inventory.h"
#include "Level.h"
#include "Perk.h"
#include "Bracelet.h"
#include <fstream>


class Saver
{
    public:
        Saver();
        ~Saver();
        bool save_game(int, int, Level*, PlayerStats*, Equipment*, Inventory*, std::vector<Perk*>, Bracelet, int);
};

#endif
