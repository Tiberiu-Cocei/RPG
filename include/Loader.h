#ifndef LOADER_H
#define LOADER_H
#include <dirent.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include "LevelList.h"
#include "Equipment.h"
#include "Inventory.h"
#include "PerkList.h"
#include "Bracelet.h"
#include "EquipableItemList.h"
#include "ConsumableItemList.h"

class Loader
{
    public:
        Loader();
        ~Loader();
        void show_save_files();
        bool check_file_name(std::string);
        bool load_game(int&, int&, Level*&, PlayerStats*&, Equipment*&, Inventory*&, std::vector<Perk*>&, Bracelet&, std::string file);
};

#endif
