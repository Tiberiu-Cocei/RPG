#include "Game.h"

Game::Game() {
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
    game_introduction();
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
            gameOver = level->move_in_direction(currentCoordinates, 'N', equipment, playerStats, playerPerks, inventory);
            break;
          case 3 :
          case 13 :
            gameOver = level->move_in_direction(currentCoordinates, 'E', equipment, playerStats, playerPerks, inventory);
            break;
          case 4 :
          case 14 :
            gameOver = level->move_in_direction(currentCoordinates, 'W', equipment, playerStats, playerPerks, inventory);
            break;
          case 5 :
          case 15 :
            gameOver = level->move_in_direction(currentCoordinates, 'S', equipment, playerStats, playerPerks, inventory);
            break;
          case 6 :
            playerStats->get_stats();
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
                inventory->use_item(itemIndexInt, equipment, playerStats);
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
                level->begin_level();
                currentCoordinates = level->get_initial_coordinates();
            }
            else {
                std::cout<<"Congratulations! You have cleared all the current content of the game!\n";
                gameOver = true;
            }
        }
      }
    }
}

void Game::game_introduction() {
    std::string viewIntro;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    std::cout<<"Do you wish to view the story introduction? (Yes/No)\n";
    std::getline(std::cin, viewIntro);
    if(viewIntro == "Yes" || viewIntro == "yes") {
        std::cout<<"\nToday is the last day of the month. As is tradition, one of the young adults from the village will be sent to the Path of Trial.\n";
        Sleep(6000);
        std::cout<<"You do not know much, as everyone who went through it refuses to talk about it. All you know is that they act different after the ordeal.\n";
        Sleep(6000);
        std::cout<<"Many leave the village, never to return. The elders say that they matured, but it did little to help make your bad feeling go away.\n";
        Sleep(6000);
        std::cout<<"You get dressed and go to the gathering. Like always, a mysterious man wearing a cloak that covers him entirely is waiting in the middle of the village.\n";
        Sleep(6000);
        std::cout<<"Once the village has gathered, the elders signal everyone to become quiet. They call the youth to come closer to the center. This includes you.\n";
        Sleep(6000);
        std::cout<<"Hesitantly, you get closer. There's around twenty people this time. You try and calm yourself with the fact that it's unlikely that you will be picked.\n";
        Sleep(6000);
        std::cout<<"The chances are one in twenty or so, after all. The cloaked man looks around, carefully analyzing each and every single one of you.\n";
        Sleep(6000);
        std::cout<<"After a long pause, he points towards someone. Towards you. You are not that shocked. You knew this could happen, sooner or later.\n";
        Sleep(6000);
        std::cout<<"Nobody died during the trial, though some have come out more deranged than others. This does put your mind at ease, at least for the moment.\n";
        Sleep(6000);
        std::cout<<"You step forward, ready to be instructed by the cloaked man.\n";
        Sleep(2500);
        std::cout<<"\"Your trial will be as follows: follow the path, that which starts from the cave and ends in the volcanic ruins.\"\n";
        Sleep(5000);
        std::cout<<"\"You will be challenged by many foes on your way. They all will possess combat supplies which will aid you. Defeat them, and they will be yours to claim.\"\n";
        Sleep(6000);
        std::cout<<"\"There are many places of power that can be found. Some will contain valuable items that you may use.\"\n";
        Sleep(5000);
        std::cout<<"\"Others will help you in ways that are not of physical nature, such as the Fountain of Knowledge. With its blessing, you will be able to become stronger.\"\n";
        Sleep(6000);
        std::cout<<"\"To finish the trial, you must defeat a powerful foe. One appointed specifically by the King. If you are deemed worthy, you may even join his ranks.\"\n";
        Sleep(6000);
        std::cout<<"\"Now accept this gift from us: a set of leather armor, a copper shield and sword. You will find better equipment from your foes. This is but a start.\"\n";
        Sleep(6000);
        std::cout<<"\"Equip it and meet us near the entrance of the cave at dusk.\"\n";
        Sleep(3000);
        std::cout<<"His soothing voice helped calm you further, and with the goal in mind, you feel hopeful. Still, the bad feeling remains.\n";
        Sleep(4500);
        std::cout<<"Hours later, the time has come. Fully prepared, you go and meet the elders. They show you the entrance of the cave.\n";
        Sleep(4500);
        std::cout<<"You look at it. This is the cave that only opens up during this time of month, and closes itself as the sun sets.\n\n";
        Sleep(4500);
    }
}

Game::~Game() {}
