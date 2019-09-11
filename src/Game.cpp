#include "Game.h"

Game::Game()
{
    //generating random seed
    srand (time(NULL));

    //changing console size
    HWND console = GetConsoleWindow();
    MoveWindow(console, 255, 90, 1100, 700, TRUE);

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
            std::cout<<"The possible commands are: 'exit', 'move north/south/west/east', 'my stats', 'equipment', 'inventory', 'use item', 'drop item'.\n";
            break;
          case 2 :
            gameOver = level->move_in_direction(currentCoordinates, 'N', equipment, inventory);
            break;
          case 3 :
            gameOver = level->move_in_direction(currentCoordinates, 'E', equipment, inventory);
            break;
          case 4 :
            gameOver = level->move_in_direction(currentCoordinates, 'W', equipment, inventory);
            break;
          case 5 :
            gameOver = level->move_in_direction(currentCoordinates, 'S', equipment, inventory);
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
          case 100 :
            std::cout<<"Exiting the game.\n";
            break;
          default :
            std::cout<<"Unknown command. Write \"help\" to view all the commands.\n";
      }
      if(commandValue > 1 && commandValue < 6) {
        std::cout << "Your current coordinates are : " << currentCoordinates/15 + 1 << " " << currentCoordinates%15 + 1 << std::endl;
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
