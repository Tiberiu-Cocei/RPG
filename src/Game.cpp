#include "Game.h"

Game::Game()
{
    //generating random seed
    srand (time(NULL));

    //changing console size
    HWND console = GetConsoleWindow();
    MoveWindow(console, 155, 35, 1300, 800, TRUE);

    commandMapping.insert(std::make_pair("help", 1));
    commandMapping.insert(std::make_pair("move north", 2));
    commandMapping.insert(std::make_pair("move east", 3));
    commandMapping.insert(std::make_pair("move west", 4));
    commandMapping.insert(std::make_pair("move south", 5));
    commandMapping.insert(std::make_pair("my stats", 6));
    commandMapping.insert(std::make_pair("equipment", 7));
    commandMapping.insert(std::make_pair("inventory", 8));
    commandMapping.insert(std::make_pair("use item", 9));
    commandMapping.insert(std::make_pair("drop item", 10));
    commandMapping.insert(std::make_pair("map", 11));
    commandMapping.insert(std::make_pair("go north", 12));
    commandMapping.insert(std::make_pair("go east", 13));
    commandMapping.insert(std::make_pair("go west", 14));
    commandMapping.insert(std::make_pair("go south", 15));
    commandMapping.insert(std::make_pair("perks", 16));
    commandMapping.insert(std::make_pair("attune perk", 17));
    commandMapping.insert(std::make_pair("exit", 100));

    playerStats = new PlayerStats(100, 25, 25, 25, 25, 25);
    equipment = new Equipment(playerStats);
    equipableItemList = new EquipableItemList();
    consumableItemList = new ConsumableItemList();
    inventory = new Inventory();
    levelList = new LevelList();

    gameOver = false;
    currentLevel = 1;
    currentCoordinates = 0;
    commandValue = 0;
    itemIndexInt = 0;

    play();
}

void Game::play() {
    level = levelList->get_level(currentLevel);
    level->begin_level();
    currentCoordinates = level->get_initial_coordinates();
    std::cout<<"Write 'help' to view all the commands.\n";
    while (strcmp(commandKey.c_str(), "exit") && !gameOver)
    {
      std::cout << "\n---------------------------------------------------------\n\n";
      std::cout << level->get_possible_directions(currentCoordinates)<<"\n";
      std::cout << "Enter command: ";
      getline (std::cin, commandKey);
      std::transform(commandKey.begin(), commandKey.end(), commandKey.begin(),
        [](unsigned char c){ return std::tolower(c); });
      commandMappingIterator = commandMapping.find(commandKey);
      if(commandMappingIterator != commandMapping.end()) {
          commandValue = commandMappingIterator->second;
      }
      else {
          commandValue = 0;
      }
      switch(commandValue) {
          case 1 :
            std::cout<<"The possible commands are: 'exit', 'go/move north/south/west/east', 'my stats', 'equipment', 'perks', 'attune perk', 'inventory', \n'use item', 'drop item', 'map'.\n";
            break;
          case 2 :
          case 12 :
            gameOver = level->move_in_direction(currentCoordinates, 'N', equipment, playerPerks, inventory);
            break;
          case 3 :
          case 13 :
            gameOver = level->move_in_direction(currentCoordinates, 'E', equipment, playerPerks, inventory);
            break;
          case 4 :
          case 14 :
            gameOver = level->move_in_direction(currentCoordinates, 'W', equipment, playerPerks, inventory);
            break;
          case 5 :
          case 15 :
            gameOver = level->move_in_direction(currentCoordinates, 'S', equipment, playerPerks, inventory);
            break;
          case 6 :
            equipment->get_player_stats()->get_stats();
            break;
          case 7 :
            equipment->get_equipment();
            break;
          case 8 :
            inventory->show_inventory();
            break;
          case 9 :
            inventory->show_inventory();
            std::cout<<"Enter the number of the item you wish to use: ";
            try {
                getline (std::cin, itemIndex);
                itemIndexInt = stoi(itemIndex);
                inventory->use_item(itemIndexInt, equipment);
            } catch(const std::invalid_argument& error) {
                std::cerr << "Not a number.\n";
            }
            break;
          case 10 :
            inventory->show_inventory();
            std::cout<<"Enter the number of the item you wish to drop: ";
            try {
                getline (std::cin, itemIndex);
                itemIndexInt = stoi(itemIndex);
                inventory->drop_item(itemIndexInt);
            } catch(const std::invalid_argument& error) {
                std::cerr << "Not a number.\n";
            }
            break;
          case 11 :
            level->show_user_map();
            break;
          case 16:
          {
            int perkIndex = 1;
            if(playerPerks.size() == 0) {
                std::cout<<"You do not know any perks at the moment. The elders did mention something about a fountain of knowledge..\n";
            }
            else {
                for(auto playerPerk : playerPerks) {
                    std::cout<< perkIndex++ << ": ";
                    playerPerk->display_perk(level->get_text_color_number());
                }
            }
            break;
          }
          case 17:
            std::cout<<"Enter the number of the perk you wish to attune: ";
            try {
                std::string perkIndex;
                getline (std::cin, perkIndex);
                int perkIndexInt = stoi(perkIndex);
                if(perkIndexInt > 0 && perkIndexInt <= playerPerks.size()) {
                    playerPerks.at(perkIndexInt - 1)->attune_perk(playerStats, inventory);
                }
                else {
                    std::cout<<"Invalid perk index.\n";
                }
            } catch(const std::invalid_argument& error) {
                std::cerr << "Not a number.\n";
            }
            break;
          case 100 :
            std::cout<<"Exiting the game.\n";
            break;
          default :
            std::cout<<"Unknown command. Write \"help\" to view all the commands.\n";
      }
      if(currentCoordinates == level->get_boss_coordinates() && true == level->is_boss_beaten()) {
        std::cout<<"\nDo you wish to go to the next level?\n";
        std::string nextLevel;
        getline(std::cin, nextLevel);
        if(nextLevel == "Yes" || nextLevel == "yes") {
            level->end_level();
            delete level;
            currentLevel++;
            if(currentLevel <= numberOfLevels) {
                level = levelList->get_level(currentLevel);
            }
            else {
                std::cout<<"Congratulations! You have cleared all the current content of the game!\n";
                gameOver = true;
            }
        }
      }
    }
}

Game::~Game()
{
}
