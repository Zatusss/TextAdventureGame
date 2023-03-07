


/*Vectors are same as dynamic arrays with the 
ability to resize itself automatically when an 
element is inserted or deleted*/
#include <vector>

/*collection of functions especially designed to 
be used on ranges of elements.*/
#include <algorithm>

/*header defines four variable types, 
several macros, and various functions for 
performing general functions. EXAMPLE size_t*/
#include <stdlib.h>

/*Input/output stream class to operate on files.
data file tansk*/
#include <fstream>

/*Strings are objects that represent 
sequences of characters.(Before ther was C-strings so 
simply implemented as a char array  )*/
#include <string>

/*Header that defines the standard 
input/output stream objects: 
std::cout std::endl*/
#include <iostream>

#include <filesystem>



/*header files for my classes*/
#include "Player.h"
#include "Item.h"
#include "Container.h"
#include "Comsumables.h"
#include "Location.h"
#include "Source.h"


Player::Player(Location *location){

//Load,Save,etc
	this->filename = "GameSaves.txt";

//Current Locatio
		this->currentLocationptr = location;
		this->currentLocationIndex = location->GetLocationIndex();
	
//Character Stats
		this->health=20;
		this->stamina=20;
		this->hydration = 20;
		this->hunger = 20;
		this->sanity =20;
		this->steps = 1;
	
//Keyboard Input
		this->playerCommandInput = "";
		this->playerInputIntMainMenu = 0;
	
//Gameplay Options bools
		this->bquit = false;
		this->bIsPlaying = false;
		this->bTravelingbool = false;
		this->bIsInteractingWithEniviroment = false;
		this->bFirstMenuScreen = true;
		this->bUsingHelp = false;

//Add starting Items
		Item screwDriver("screwdriver", "SimpleTool");
		Item maches("maches", "something to keep you warm");
		Item knife("knife", "sharp as always");
		Item EmptyBootle("EmptyBootle", "EmptyBootle");
			//Add too inventory
				this->inventory.push_back(&screwDriver);
				this->inventory.push_back(&maches);
				this->inventory.push_back(&knife);
				this->inventory.push_back(&EmptyBootle);

//Add starting Comsumable Items
		Comsumables Apple("Apple", "Apple",5,2,3,3,0);
		Comsumables CanedBeef("CanedBeef", "CanedBeef", 5, 2, 3, 3, 0);
		Comsumables Mayo("Mayo", "Mayo", 5, 2, 3, 3, 0);
		Comsumables Book("Book", "Book", 0, 0, 0, 0, 5);
			//Add too inventory
				this->comsumables.push_back(&Apple);
				this->comsumables.push_back(&CanedBeef);
				this->comsumables.push_back(&Mayo);
				this->comsumables.push_back(&Book);

	//Print MainMenu screen
		FirstMenuScreen(nullptr);
}

/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
			  /*MENU*/

//Main Menu
void Player::FirstMenuScreen(bool* bWindowToClose){
	bFirstMenuScreen = true;//set to true when entering interaction,false when leaving
	
		while (bFirstMenuScreen) {
			//when user eters wrong input flow is being send here
			ClearScreen();//remove old text from console
			PrintFirstMenuOptions();//print main menu UI

				AskForPlayerInputINT("[]PLEASE ENTER OPTION DIGIT[]",true);//Print costum message to the screen + ask for INT keyboard input
					if (this->playerInputIntMainMenu > 0 && // if selected number is smalle then 0 or bigger then amout of options run goto to run this function again
						this->playerInputIntMainMenu < 6){

							switch (this->playerInputIntMainMenu){//

								case 1:
									NewGame(&bFirstMenuScreen);//creates new character
									break;
								case 2:
									LoadCharacter();//load character from text file
									break;
								case 3:
									Help(&bFirstMenuScreen);//simple explenation how to playe a game 
									break;
								case 4:
									DeveloperInformation();//My ID+Name
									break;
								case 5:
									Quit(&bFirstMenuScreen);//Quits Game console shuts down
									break;
							}
					}

					else{
						//sends flow to the begining of the while loop
						FirstMenuScreen(nullptr);
					}	
		}
}  
	void Player::PrintFirstMenuOptions(){
			std::cout << "[XXXX]MAINN MENU[XXXX]" << endl;

					std::cout << "[1]NEW GAME[1]" << endl;
					std::cout << "[2]LOAD GAME[2]" << endl;
					std::cout << "[3]HELP[3]" << endl;
					std::cout << "[4]ABOUT DEVELOPER[4]" << endl;
					std::cout << "[5]QUIT[5]" << endl;
}
	
//Gameplay Menu
void Player::GameMenu()
	{
		
			this->bIsPlaying = true;//turn this true when entering off when exiting actiong window
			while (this->bIsPlaying) {
				ClearScreen();
				PrintGameMenuOptions();
				AskForPlayerInputINT("[]Enter your choice[]", true);
				switch (this->playerInputIntMainMenu) {
				case 1:
					Travel();
					break;
				case 2:
					PrintCurrentLocation();
					break;
				case 3:
					InteractWithEniviroment();
					break;
				case 4:
					CharacterWindow();
					break;
				case 5:
					NewGame(&bIsPlaying);
					break;
				case 6:
					LoadCharacter();
					break;
				case 7:
					SaveCharacter();
					break;
				case 8:
					Help(&bIsPlaying);
					break;
				case 9:
					Quit(&bIsPlaying);
					break;
				}
			}
		
	}
	void Player::PrintGameMenuOptions(){
	  std::cout << "[]GAME MENU[]" << endl;

			std::cout << "  [1][TRAVEL][1]" << endl;
			std::cout << "  [2][LOCATION][2]" << endl;
			std::cout << "  [3][INTERACT][3]" << endl;
			std::cout << "  [4][CHARACTER][4]" << endl;

	  std::cout << "[]PLAYER MENU[]" << endl;

			std::cout << "  [5][NEW CHARACTER][5]" << endl;
			std::cout << "  [6][LOAD CHARACTER][6]" << endl;
			std::cout << "  [7][SAVE CHARACTER][7]" << endl;
			std::cout << "  [8][Help][8]" << endl;
			std::cout << "  [9][QUIT][9]" << endl;
	}

//PRINT BASIC UI
void Player::PrintLowerLine(int loopSize) {


		std::string v1 = "..............................................";
		std::string v2 = "[][][][][][][][][][][][][][][][][][][][][][][]";
		std::string v3 = "----------------------------------------------";
		std::string v4 = "[]------------------------------------------[]";
		std::string v5 = "[]-----------------[][][][]-----------------[]";
		std::string v6 = "<><><><><><><><><><><><><><><><><><><><><><><>";
		std::string v7 = "()()()()()()()()()()()()()()()()()()()()()()()";

		for (int i = 0;i < loopSize;i++)
		{
			cout << v6 << v6 << v6 << endl;
		}


	}
void Player::PrinAreYouShure(std::string sCostumMessage, bool bUseCostumMessage)
{
	ClearScreen();
	std::string temp;


	if (bUseCostumMessage)
	{
		temp = sCostumMessage;
		std::cout << temp << std::endl;
		AskForPlayerInputINT("[1]Yes[1] [2]No[2]?", true);

		

	}
	else if (!bUseCostumMessage)
	{
		std::cout << "[ARE YOU SURE?]" << std::endl;
		AskForPlayerInputINT("[1]Yes[1] [2]No[2]?", true);
	}

}

//ASK FOR INPUT
int Player::AskForPlayerInputINT(std::string message, bool useCustomMessage)
{
	playerInputIntMainMenu = -1;


	if (useCustomMessage) {

		cout << message << endl;
	}
	else if (!useCustomMessage)
	{
		std::string message = "[ENTER NUMBER]";
		cout << message << endl;
	}
	
	while (!(cin>> playerInputIntMainMenu))
	{
		cout << "WRONG INPUT YOU NEED NUMBER" << endl;
		cin.clear();
		cin.ignore(22,'\n');
		AnyKeyToContinueAndClearScreen();
		break;

	}
	
	return this->playerInputIntMainMenu;
		
	
}
std::string Player::AskForPlayerInputSTRING(std::string message, bool useCustomMessage)
{
	this->playerCommandInput = "";
	
	if (useCustomMessage) {

		cout << message << endl;

			
			std::cin >> this->playerCommandInput;

			return this->playerCommandInput;
	}
	else
		std::string message = "[ENTER COMANND]";
		cout << message << endl;

			
			std::cin >> this->playerCommandInput;

			return this->playerCommandInput;
}

//COMMANDS
void Player::MenuComand(bool* bWindowToClose)
{

	if (this->playerCommandInput == "menu") {

		if (this->bIsPlaying)
		{
			GameMenu();
		}
		else if (this->bFirstMenuScreen)
		{
			FirstMenuScreen(nullptr);
		}
	}
}


/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
			
			/*TRAVEL + Random Events*/

void Player::Travel() {
	this->bTravelingbool = true;
		while (bTravelingbool) {
			
			PrintAllConnectedRoadsForTravel();//prints possible directions
				AskForPlayerInputSTRING("[ENTER TRAVEL COMMAND]", true);//ask for input
					//all possible commands
					TravelInChoosenDirection();
					TravelsCommandsComand();
					StatsCommand();
					LocationsCommand();
					MenuComand(&bTravelingbool);

					if (this->playerCommandInput != "stats", "menu", "location", "north", "south", "east", "west") {
						std::cout << "ENTER CORRECT COMMAND" << std::endl;
						WaitForAnyInput();
						Travel();
					}
		}
}
//Prints lost recources during travel+current character Statistics
	void Player::PrintStatsAndRandomEventsInformation() 
		{
			
				ClearScreen();
				PrintLowerLine(2);
				std::cout << endl;

				PrintPunishmentForTravel();
				PrintCurrentStatsMax();

				std::cout << endl;
				PrintLowerLine(2); 
				std::cout << endl;
		}
	//Either print current location or it changes message to arrived! when player moves location
	void Player::PrintCurrentLocationNameAndDescription(bool bnewLocation) {

		if (!bnewLocation) {
			PrintLowerLine(2);
			std::cout << endl;
			std::cout << "[X][CURRENT LOCATION INFO][X]" << endl;
			std::cout << "   [][NAME]" << "  " << GetLocation()->GetName() << endl;
			std::cout << "   [][DESCRIPTION]" << "  " << GetLocation()->GetDescription() << endl << endl;
		}
		else if (bnewLocation) {
			PrintLowerLine(2);
			std::cout << endl;
			std::cout << "[Z][ARRIVED!!!][Z]" << endl;
			std::cout << "   [][NAME]" << "  " << GetLocation()->GetName() << endl;
			std::cout << "   [][DESCRIPTION]" << "  " << GetLocation()->GetDescription() << endl << endl;
		}
	}
	//prints key information during travel,name,description,items,points of intreast an most important available rout player can take
	void Player::PrintAllConnectedRoadsForTravel()
	{
		ClearScreen();
		std::cout << std::endl;
		std::cout << "[XXXX][TRAVEL WINDOW][XXXX]" << std::endl << std::endl;
		GetLocation()->PrintAllConnectedRoads();
	}
	

//List of allowed Travel Commands
void Player::TravelInChoosenDirection() {

			if (this->playerCommandInput == "north") {
				if (GetLocation()->GetNorthptr() != nullptr) {
					SetLocation(GetLocation()->GetNorthptr());
					PrintStatsAndRandomEventsInformation();
					WaitForAnyInput();
				}
				else if (GetLocation()->GetNorthptr() == nullptr) {
					std::cout << "[ROAD BLOCKED!!!]" << endl;
				}
			}
			else if (this->playerCommandInput == "south") {
				if (GetLocation()->GetSouthptr() != nullptr) {
					SetLocation(GetLocation()->GetSouthptr());
					PrintStatsAndRandomEventsInformation();

					WaitForAnyInput();
				}
				else if (GetLocation()->GetSouthptr() == nullptr) {
					std::cout << "[ROAD BLOCKED!!!]" << endl;
				}
			}
			else if (this->playerCommandInput == "west") {
				if (GetLocation()->GetWestptr() != nullptr) {
					SetLocation(GetLocation()->GetWestptr());
					PrintStatsAndRandomEventsInformation();

					WaitForAnyInput();

				}
				else if (GetLocation()->GetWestptr() == nullptr) {
					std::cout << "[ROAD BLOCKED!!!]" << endl;
				}
			}
			else if (this->playerCommandInput == "east") {
				if (GetLocation()->GetEastptr() != nullptr) {
					SetLocation(GetLocation()->GetEastptr());
					PrintStatsAndRandomEventsInformation();

					WaitForAnyInput();

				}
				else if (GetLocation()->GetEastptr() == nullptr) {
					std::cout << "[ROAD BLOCKED!!!]" << endl;
				}
			}
		}
void Player::TravelsCommandsComand()
		{
			//Go back to main menu
			if (this->playerCommandInput == "command") {

				PrintTravelCommands();
				std::cout << "Press any button to continue";
				WaitForAnyInput();
			}
		}
void Player::StatsCommand()
		{
			if (this->playerCommandInput == "stats") {

				PrintStatsAndRandomEventsInformation();
				std::cout << "Press any button to continue";
				WaitForAnyInput();
			}
		}
void Player::LocationsCommand()
		{
			if (this->playerCommandInput == "location") {

				this->currentLocationptr->PrintLocation(this->currentLocationptr);
				std::cout << "Press any button to continue" << std::endl;
				WaitForAnyInput();
			}
		}

//Print info about random events that happedn during traveld/or lost resources etc
void Player::PrintPunishmentForTravel(){
				int tempSteps = AssignRandomSteps();
				int tempThirs = AssingRandomThirst();
				int tempHunger = AssingRandomHunger();

					std::cout << "[X][PRICE PAYED FOR SURVIVAL][X]" << endl << endl;
						std::cout << "   [X][HUNGER]" << tempHunger << endl;
						std::cout << "   [X][THIRST]" << tempThirs << endl;
						std::cout << "   [X][STEPS]" << tempSteps << endl;
		}
		int Player::AssignRandomSteps() {
					int randVal = rand() % 10 + 5;
					this->steps += randVal;
					return randVal;
				}
		int Player::AssingRandomThirst() {
					int randVal = rand() % -5 + -1;
					this->hydration -= randVal;
					return randVal;
				}
		int Player::AssingRandomHunger() {
					int randVal = rand() % -5 + -1;
					this->hunger -= randVal;
					return -randVal;
				}
	//Other possibile events  to implement
	/*  void Player::RandomFight(){}random attack on character looses health
		void Player::SupernaturalEncounter(){}random fobia etc on character looses sanity
		void Player::RunningAwayFromPredator{}u had to run loost stamina    */
		
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

			/*INTERACT WITH ENIVIROMENT*/		

//Explore current location
void Player::InteractWithEniviroment(){
	
	ClearScreen();//clear old text
	PrintInteractWithEniviromentWindow();//prints UI to the screen
	this->bIsInteractingWithEniviroment = true;//set bool of this window to true

		while (bIsInteractingWithEniviroment){

			AskForPlayerInputSTRING("PLEASE ENTER COMMAND", true);
				
				InteractWithEniviromentCommandsComand();
				LookCommand();
				DropItemCommand();
				MenuComand(&bIsInteractingWithEniviroment);

				if (this->playerCommandInput != "look", "menu", "drop", "command") {
					std::cout << "ENTER CORRECT COMMAND" << std::endl;
					WaitForAnyInput();
					InteractWithEniviroment();
				}
		}
}
	
	void Player::PrintInteractWithEniviromentWindow()
{
	cout << endl << "[XXX][INTERACT WITH ENIVIROMENT]" << "]" << endl << endl;
	cout << "  [NAME][" << this->GetLocation()->GetName() << "]" << endl;
	cout << "  [DESCRIPTION][" << this->GetLocation()->GetDescription() << "]" << endl << endl;
	PrintAllIntreastPoints();
	PrintAllLooseItems();
}
	bool Player::DropItemCommand()
	{
		if (this->playerCommandInput == "drop")
		{

			AskForPlayerInputINT("CHOOSE [1]INVENTORY [2]COMSUMABLE", true);

			if (this->playerInputIntMainMenu == 1) {
				this->PrintAllInventoryItems();
				AskForPlayerInputINT("CHOOSE INVENTORY ITEM TO DROP", true);
				if (this->playerInputIntMainMenu >= 0 &&
					this->playerInputIntMainMenu <= this->GetInventory().size()-1) {

					this->currentLocationptr->drop_item(this->inventory.at(this->playerInputIntMainMenu));

					this->inventory.at(this->playerInputIntMainMenu) = this->inventory.back();
					//std::cout << comsumables.at(playerInputIntMainMenu) << std::endl;
					this->inventory.pop_back();
					

				}
			}

			else if (this->playerInputIntMainMenu == 2) {
				this->PrinAllComsumableTiems();
				AskForPlayerInputINT("CHOOSE COMSUMABLE ITEM TO DROP", true);

				if (this->playerInputIntMainMenu > -1 &&
					this->playerInputIntMainMenu < this->GetComsumables().size()) {


					this->comsumables.at(playerInputIntMainMenu) = this->comsumables.back();
					//std::cout << comsumables.at(playerInputIntMainMenu) << std::endl;
					this->comsumables.pop_back();
					
				}
			}
		}
		return true;
		
	}
	void Player::InteractWithEniviromentCommandsComand()
	{
		//Go back to main menu
		if (this->playerCommandInput == "command") {

			PrintInteractWithEniviromentCommands();
			AnyKeyToContinueAndClearScreen();
			InteractWithEniviroment();

		}
	}
	void Player::LookCommand()
	{
		if (this->playerCommandInput == "look") {

			WhatToInteractWith();//choose between interacting with food or items in your inventory
			InteractWithPointsOfIntreast();//interact with containers or locations inside locations
			InteractWithLoosItems();//interact with random loot that is spread around the area
		}
	}

		void Player::WhatToInteractWith()
		{
			std::cout << "[1]Points of Intreast" << endl
				<< "[2]Loos Items" << endl;
			AskForPlayerInputINT("----[WHAT INTREASTS YOU?]----", true);
			ClearScreen();
		}
			void Player::InteractWithPointsOfIntreast() {
				if (this->playerInputIntMainMenu == 1) {

					//print every container inside locations
					PrintAllIntreastPoints();
					AskForPlayerInputINT("[][CHOOSE POINT OF INTREAST?][]", true);

					if (this->playerInputIntMainMenu >= 0 && this->playerInputIntMainMenu <= this->GetLocation()->GetContainer()[this->playerInputIntMainMenu].size()-1) {
						PrintContainerInformation();
						OpenContainer();
						OpenContainerUsingKey();
					}

					else

						cout << "Please choose right item to look at" << endl;

				}
			}
				void Player::PrintAllIntreastPoints() {
				//Print all containers that are currently found in level

				cout << "[X][POINTS OF INTREAST][X]" << endl;
				std::vector<Container*>* Containers = this->GetLocation()->GetContainer();
				for (int i = 0; i < Containers->size(); i++)
				{
					cout << "   [" << i << "]" << Containers->at(i)->GetName() << endl;

				}
				cout << endl;


			}
				void Player::PrintContainerInformation()
				{
					cout << "[X][CONTAINER INFO][X]" << endl;

					cout << "[X][NAME]" << endl;
					cout << this->GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->GetName() << endl;
					cout << "[X][DESCRIPTION]" << endl;
					cout << this->GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->GetDescription() << endl;
					cout << "[X][KEY ITEM]" << endl;
					cout << this->GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->GetKeyItem()->GetName() << endl;
					cout << "[X][OPEN/CLOSED]" << endl;

					if (*GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->CheckIfContainerIsOpen()) {
						cout << "OPEND" << endl;
					}
					else if (!*GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->CheckIfContainerIsOpen())
					{
						cout << "CLOSED" << endl;
					}
				}
				void Player::OpenContainer() {


					

						Container* temp = GetLocation()->GetContainer()->at(this->playerInputIntMainMenu);
						std::cout << "YOU MANAGED TO OPEN THIS CONTAINER!!" << std::endl << std::endl;


						if (*GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->CheckIfContainerIsOpen()) {
							std::vector<Container*>* Containers = this->GetLocation()->GetContainer();
							std::vector<Item*>* thisContainerItems = Containers->at(this->playerInputIntMainMenu)->GetContents();

							cout << "[][CONTENT][]" << endl;
							for (int i = 0;i < this->GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->GetContents()->size();i++)
							{
								if (i > 0)
								{
									auto it = find(thisContainerItems->begin(), thisContainerItems->end(), thisContainerItems->at(i));

									int index = it - thisContainerItems->begin();

									cout << "[" << index << "]" << thisContainerItems->at(i)->GetName() << endl;
								}
								
							}


							AskForPlayerInputSTRING("WHAT YOU WANT TO DO WITH IT", true);
							TakeItemCommand(temp,thisContainerItems, true);
							TakeAllItemsCommand(nullptr, thisContainerItems, true);
						}
					
				}
				void Player::OpenContainerUsingKey() {

					Container* temp = this->GetLocation()->GetContainer()->at(this->playerInputIntMainMenu);
					if (!*GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->
						CheckIfContainerIsOpen()) {//if container is not open
						cout << "This is closed please look for:" << endl;
						cout << this->GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->GetKeyItem()->GetName() << endl;
						std::string containerKeyTemp = this->GetLocation()->GetContainer()->at(this->playerInputIntMainMenu)->GetKeyItem()->GetName();
						cout << "Do you have this item in your inventory?" << endl;
						cout << "TRY TO OPEN" << endl;
						AskForPlayerInputINT("[1]Yes[1] [2]No[2]?", true);

						if (this->playerInputIntMainMenu == 1) {

							cout << "[INVENTORY ITEMS]" << endl;
							std::vector<Item*> Inventory = GetInventory();

							for (int i = 0; i < Inventory.size(); i++) {
								cout << "[" << i << "]" << Inventory[i]->GetName() << endl;
							}

							AskForPlayerInputINT("[CHOOSE KEY ITEM]", true);
							std::string choosenItemTemp = GetInventory()[playerInputIntMainMenu]->GetName();
							if (choosenItemTemp == containerKeyTemp) {
								temp->SetConteinerLock(true);
								this->inventory.erase(inventory.begin() + this->playerInputIntMainMenu);
								cout << "[CONTAINER OPEN]" << endl;
								std::cout << "YOU MANAGED TO OPEN THIS CONTAINER!!" << std::endl << std::endl;

								AskForPlayerInputINT("Press 1 to continue", true);
								OpenContainer();

							}
							else {
								cout << "[Wrong Item]" << endl;
								cout << "choosen inventory key [" + choosenItemTemp << endl;
								cout << "need to open [" + containerKeyTemp << endl;
							}


						}
					}
				}

			void Player::InteractWithLoosItems()
			{
				if (this->playerInputIntMainMenu == 2) {

					//print every container inside locations
					PrintAllLooseItems();


					AskForPlayerInputINT("[CHOOSE LOOSE ITEMS?]", true);

					if (this->playerInputIntMainMenu > -1 && this->playerInputIntMainMenu < this->GetLocation()->GetItemsinsideLocation()->size()) {

						std::vector<Item*>* Items = this->GetLocation()->GetItemsinsideLocation();



						AskForPlayerInputSTRING("WHAT YOU WANT TO DO WITH IT", true);
						TakeItemCommand(0, Items, false);
						TakeAllItemsCommand(nullptr, Items, false);
					}

					else

						cout << "Please choose right item to look at" << endl;

				}
			}
				void Player::PrintAllLooseItems()
			{



				std::cout << "[X][LOOSE LOOT][X]" << endl;
				std::vector<Item*>* Items = this->GetLocation()->GetItemsinsideLocation();
				for (int i = 0; i < Items->size(); i++) {
					if (i > 0) {
						std::cout << "  [" << i << "]" << Items->at(i)->GetName() << endl;
					}
				}
				std::cout << endl;

			}

			

bool Player::TakeItemCommand(Container * containerNr, std::vector<Item*> * thisContainerItems,bool takeContainerItem){
	
	Container* temp = containerNr;
	if (this->playerCommandInput == "take")
	{
		AskForPlayerInputINT("CHOOSE YOUR ITEM", true);

		Item * itemTemp = thisContainerItems->at(this->playerInputIntMainMenu);
									
		cout << "[THIS ITEM IS NOW IN YOUR INVENTORY]" << endl;
		cout << "[NAME]" << endl;
		cout << itemTemp->GetName() << endl;
		cout << "[DESCRIPTION]" << endl;
		cout << itemTemp->GetDescription() << endl;

				
		if (takeContainerItem)
		{
			inventory.push_back(itemTemp);
			//MAIN PROBLEM
			this->GetLocation()->TakeContainerItem(itemTemp, temp, &this->playerInputIntMainMenu);
										
		}
		else if (!takeContainerItem)
		{
			inventory.push_back(itemTemp);

			this->currentLocationptr->TakeLooseItem(this->playerInputIntMainMenu);
		}
		AskForPlayerInputSTRING("TYPE IN MENU", true);
		MenuComand(&bIsInteractingWithEniviroment);
		LookCommand();
	}
	return true;

}
bool Player::TakeAllItemsCommand(Item* i, std::vector<Item*> * thisContainerItems,bool takeContainerItem)
{
	if (this->playerCommandInput == "takeall")
	{
		if (takeContainerItem)
		{
			for (int i = 0;i < this->GetLocation()->GetContainer()->size();i++)
			{
				this->inventory.push_back(thisContainerItems->at(i));
			}

			cout << " in now empty" << endl;
			this->currentLocationptr->TakeAllContainerItems(this->currentLocationptr->GetContainer()->at(this->playerInputIntMainMenu));
										
		}
		else if (!takeContainerItem)
		{
			for (int i = 0;i < this->GetLocation()->GetContainer()->size();i++)
			{
				this->inventory.push_back(thisContainerItems->at(i));
			}

			this->currentLocationptr->TakeAllLoosItems();
		}


	}
	return false;

}

/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
			
			/*HELP/GUIDE*/									

//print help window with lore objective and all comands
void Player::Help(bool* bWindowToClose){
	this->bUsingHelp = true;
		while (bUsingHelp){	
		ClearScreen();

			bool temp = false;
			bWindowToClose = &temp;
			this->bUsingHelp = true;

				PrintHelpWindowOptions();
				AskForPlayerInputINT("SELECT YOUR CHOICE", true);
				if (this->playerInputIntMainMenu > 0 && // if selected number is smalle then 0 or bigger then amout of options run goto to run this function again
					this->playerInputIntMainMenu < 6) {
					switch (this->playerInputIntMainMenu) {

					case 1:
						PrintLore();
						break;
					case 2:
						PrintGameObjective();
						break;
					case 3:
						GameObstacles();
						break;
					case 4:
						TravelHelp();
						InteractEniviromentHelp();
						CharacterWindowHelp();
						break;
					case 5:
						bUsingHelp = false;
						break;

					}
				}
				else
				{
					Help(nullptr);
				}
		}
}
		void Player::PrintHelpWindowOptions()
{
	cout << "[XXX][HELP WINDOW][XXX]" << endl;
	cout << "   [1]LORE[1] " << endl <<
			"   [2]OBJECTIVES[2] " << endl <<
			"   [3]OBSTACLES[3] " << endl <<
			"   [4]GAMEPLAY AND COMMANDS HELP[4]" << endl <<
			"   [5]BACK[5]" << endl;
}
//Print Basic Instroctions
		void Player::PrintLore() {
			ClearScreen();
			//use this to read lore for txt file
					//std::string lore;
					//std::cout << lore << std::endl << endl;
			PrintLowerLine(2);
					std::cout<<std::endl << "[][GAME LORE][]" << std::endl<< std::endl;
					cout << "	[X]Unknow virus attacke earth" << endl;
					cout << "	[X]Everyone died with in 2 months from first infected" << endl;
					cout << "	[X]You are a lone traveler trying to surivve in this harsh reality" << endl;
					cout << "	[X]There is a rumor about a  camp of last survivors" << endl;
					cout << "	[X]Find survivors camp and survive" << endl<< endl;
			PrintLowerLine(1);
					AnyKeyToContinueAndClearScreen();

		}
		void Player::PrintGameObjective(){
			ClearScreen();
					//use this to read objective for txt file
					//std::string objective;
					// << objective << endl << endl;
			PrintLowerLine(1);
			std::cout << std::endl << "[][GAME OBJECTIVE][]" << endl<<endl;
					cout << "	[X]Explore dangerous locations" << endl;
					cout << "	[X]Collect food and items from  containers to survive" << endl;
					cout << "	[X]Travel between locations risking death" << endl;
					cout << "	[X]Escape the map" << endl;
					cout << "	[X]Survive" << endl<< endl;
				PrintLowerLine(1);
				AnyKeyToContinueAndClearScreen();
		}
		void Player::GameObstacles() {
			ClearScreen();
					std::string obstacles ;
					cout << obstacles;
					PrintLowerLine(1);
			std::cout << "[XXXX][GAME OBSTACLES][XXXX]" << std::endl<< std::endl;

						std::cout << "  [!][HYDRATION AND HUNGER][!]" << std::endl<<std::endl;
								cout << "	  [X]You have to travel but remember traveling decreases thirst and hunger" << endl;
								cout << "	  [X]When thirst or hunger reaches 0 every travel with take random amount of health away from you" << endl;
								cout << "	  [X]Look for comsumables items that will feed you" << endl;
								cout <<"	  [X]When health reaches 0 you die" << endl<< endl;

						std::cout << "  [!][SANITY,PARANORMAL AND RANDOM EVENTS][!]" << std::endl<< std::endl;
								cout << "	  [X]During travel you will encounter random events that will negatively affect you character" << endl;
								cout << "	  [X]Player can also encounter Paranormal events that will decrease player sanity when sanity reaches 0 you die" << endl;
								cout << "	  [X]Look for comsumables items that will give you psychological resitance " << endl<< endl;
					
						std::cout << "  [!][LOCKED CONTAINERS][]" << std::endl<< std::endl;
								cout << "	  [X]Not every container or path will be open " << endl;
								cout << "	  [X]If you encounter a locked container try to look for the key close by or meybe even in your inventory " << endl<< endl;
							PrintLowerLine(2);
							AnyKeyToContinueAndClearScreen();
					
				}
	//Print gameplay windows commands + how to navigate it
		void Player::TravelHelp()
		{
			ClearScreen();
			PrintLowerLine(1);
			std::cout << std::endl;
			std::cout << "[][WHAT TO DO DURING TRAVEL ACTIVITY?][]" << std::endl << std::endl;
			std::cout << " [][HOW TO TRAVEL?][]" << std::endl;
			std::cout << "	[x]When you enter traveling window you move around the map using world direction north,east,west,south" << std::endl;
			std::cout << "	[x]Keep an eye on character statistics it is being affected everytime you travel not mensioni9ng random events" << std::endl;
			std::cout << "	[x]If you cant move to a location that means that road is blocked or you need a key" << std::endl;
			std::cout << "	[x]You can also go back to the game menu by using menu command" << std::endl;
			PrintTravelCommands();
			PrintLowerLine(1);
			AnyKeyToContinueAndClearScreen();
			/*WHEN YOU DECIED TO TRAVE BETWEEN LOCATIONS REMEMBER THESE COMANDS */
		}
			void Player::PrintTravelCommands() {
			vector<string> listOfTravellComands{ "north","south","west","east","menu","command","stats","location" };
			vector<string> listOfTravellComandsDescriptions
			{ "moves player north","moves player south","moves player west","moves player east","go back to game menu","print list of possible commands","print character stats current/max","print all relevent location information"};

			cout << endl << "			[]TRAVEL COMMANDS[]" << endl;
			for (int i = 0; i < listOfTravellComands.size(); i++) {
				cout << "			[" << listOfTravellComands[i] << "] " <<
					listOfTravellComandsDescriptions[i] << " " << endl;
			}
			std::cout << std::endl;
		}
		void Player::InteractEniviromentHelp()
				{
			ClearScreen();
					PrintLowerLine(1);
					
					std::cout << std::endl <<"[][INTERACT WITH ENIVIROMENT][]" << std::endl<< std::endl;
					std::cout << " [HOW TO INTERACT WITH ENIVIROMENT?]" << std::endl;
					std::cout << "	[X]Firstly decied what you want to look at because map is filled with loose item and points of intreast" << std::endl;
					std::cout << "	[X]Using number input choose what intreasts you" << std::endl;
					std::cout << "	[X]If you pressed loose items you can pick them up like from any other open container" << std::endl;
					std::cout << "	[X]To pick up loose item or to loot open container use command [take] or [takeall]" << std::endl;
					std::cout << "	[X]If you pressed points of intreast some of them will be locked so try to look for key item in other locations and in you inventory" << std::endl;
					std::cout << "	[X]When you find required item try to openit again using item inside you inventory and " << std::endl;
					PrintInteractWithEniviromentCommands();
					PrintLowerLine(1);
					std::cout << std::endl;
					AnyKeyToContinueAndClearScreen();
				}
			void Player::PrintInteractWithEniviromentCommands(){
			vector<string> listOfTravellComands{ 
				"look"
				,"take"
				,"takeall"
				,"drop"
				,"back"
				,"menu" };
			vector<string> listOfTravellComandsDescription{ 
				"first command to write when you want to interact with sorroundings"
				,"takes selected items and adds it to inventory",
				"adds all found items to inventory",
				"drops item at location"
				,"go back "
				,"go back to game menu" };
			cout << endl << "	[]INTERACT COMMANDS[]" << endl;
			for (int i = 0; i < listOfTravellComands.size(); i++)
			{
				cout << "  [" << listOfTravellComands[i] << "] " <<
					listOfTravellComandsDescription[i] << " " << endl;

			}
			}
		void Player::CharacterWindowHelp(){
			
					PrintLowerLine(1);
					std::cout << "[WHAT TO DO INSIDE CHARACTER WINDOW?]" << std::endl;
					std::cout << "WHEN YOU DECIEDED TO USE [CHARACTER WINDOW] REMEMBER THESE COMANDS" << std::endl;
					
					PrintCharacterWindowCommands();
					PrintLowerLine(1);
					std::cout << std::endl;
					AnyKeyToContinueAndClearScreen();
		}
			void Player::PrintCharacterWindowCommands(){

				vector<string> listOfTravellComands{ "items","food","eat","drop","back","menu" };
				vector<string> listOfTravellComandsDescriptio{ "look at items you have collected","look at food you have found","eat choosen meal","drop inventory items on the ground","go back few steps","go back to game menu" };
				cout << "			[]TRAVEL COMMANDS[]" << endl;
				for (int i = 0; i < listOfTravellComands.size(); i++)
				{
					cout << "			[" << listOfTravellComands[i] << "] " <<
						listOfTravellComandsDescriptio[i] << " " << endl;

				}
			}


/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

		/*CHARACTER WINDOW*/

void Player::CharacterWindow()
{
	this->bUsingCharacterWindow = true;
	
		while (this->bUsingCharacterWindow) {
		
			PrintStatsAndInventoryForCharacterWindow();

				AskForPlayerInputSTRING("[ENTER CHARACTER WINDOW COMMAND?]", true);
			
					CommandsComandCharacterWindow();
					MenuComand(&bUsingCharacterWindow);
					ItemsCommandCharacterWindow();
					FoodCommandCharacterWindow();

						if (this->playerCommandInput != "command","menu","items","food"){
							std::cout << "ENTER CORRECT COMMAND" << std::endl;
							WaitForAnyInput();
							CharacterWindow();
						}	
		}


}

	//COMMAND print this window commands
	void Player::CommandsComandCharacterWindow()
		{
			if (this->playerCommandInput == "command")
			{
				PrintCharacterWindowCommands();
			}
		}

	//COMMAND interact with inventory items
	void Player::ItemsCommandCharacterWindow()
	{
		if (this->playerCommandInput == "items") {

			ClearScreen();
			std::cout << "[INVENTORY ITEMS]" << std::endl;
			this->PrintAllInventoryItems();

			AskForPlayerInputINT("[CHOOSE ITEM TO USE]", true);

			if (this->playerInputIntMainMenu > -1 && this->playerInputIntMainMenu < this->GetComsumables().size())
			{
				WhatToDoWithChoosenInventoryCharacterWindow();

			}

		}
	}
		void Player::WhatToDoWithChoosenInventoryCharacterWindow(){
			std::vector<Item*> Inventory = GetInventory();
			std::cout << Inventory[this->playerInputIntMainMenu]->GetName();
				if (this->playerInputIntMainMenu > -1 && this->playerInputIntMainMenu < this->GetComsumables().size()) {

					here:

						std::cout << Inventory[this->playerInputIntMainMenu]->GetName();

								AskForPlayerInputSTRING("[WHAT TO DO WITH INVENTORY?]", true);

									UseChoosenItemCharacterWindow(Inventory);
									ExamineCommandCharacterWindow(Inventory);
									MenuComand(&this->bUsingCharacterWindow);

									if (this->playerCommandInput != "examine", "menu", "use")
									{
										goto here;
									}
			
				}
				else {
					std::cout << "[PLEASE ENTER RIGHT INPUT]" << std::endl;

				}
			}
			void Player::ExamineCommandCharacterWindow(std::vector<Item*>& Inventory){

				if (this->playerCommandInput == "examine") {

					std::cout << "EXAMINED ITEMS" <<
						Inventory[this->playerInputIntMainMenu]->GetName() << std::endl <<
						Inventory[this->playerInputIntMainMenu]->GetDescription() << std::endl;
							AskForPlayerInputSTRING("",false);
							MenuComand(&this->bUsingCharacterWindow);
				}
			}
			void Player::UseChoosenItemCharacterWindow(std::vector<Item*>& Inventory)
			{
				if (this->playerCommandInput == "use") {

					std::cout << "YOU JUST USED" << Inventory[this->playerInputIntMainMenu]->GetName() << std::endl;
						AskForPlayerInputSTRING("", false);
						MenuComand(&this->bUsingCharacterWindow);
				}
			}

	//COMMAND interact with food 
	void Player::FoodCommandCharacterWindow()
	{
		if (this->playerCommandInput == "food") {

			here:

				ClearScreen();
				this->PrinAllComsumableTiems();

				AskForPlayerInputINT("[CHOOSE ITEM]", true);
					if (this->playerInputIntMainMenu >= 0 && this->playerInputIntMainMenu <= this->comsumables.size() - 1 ) {

						WhatToDoWithComsumableItemCharacterWindow();
					}
					else
					
						goto here;
					

						
		}
	}
		void Player::WhatToDoWithComsumableItemCharacterWindow()
		{
			if (this->playerInputIntMainMenu > -1 && this->playerInputIntMainMenu < this->GetComsumables().size()) {
					std::vector<Comsumables*> ComsumablesTemp = GetComsumables();
						AskForPlayerInputSTRING("[WHAT TO DO WITH[ " + ComsumablesTemp[this->playerInputIntMainMenu]->GetName() + "] ?]", true);
							EatCommandCharacterWindow();
							MenuComand(&this->bUsingCharacterWindow);
				}

		}
			void Player::EatCommandCharacterWindow(){

				if (this->playerCommandInput == "eat") {

					std::vector<Comsumables*> ComsumablesTemp = GetComsumables();
				
						std::cout << "YOU JUST ATE" << ComsumablesTemp[this->playerInputIntMainMenu]->GetName() << std::endl;
						this->comsumables[this->playerInputIntMainMenu]->PrintComsumableAttributes(this);
						this->comsumables[this->playerInputIntMainMenu]->UpdateCharacterStatistics(this);

							this->comsumables.at(playerInputIntMainMenu) = comsumables.back();
							this->comsumables.pop_back();

								here:

									AskForPlayerInputSTRING("WHAT TO DO NOW?", true);
									ItemsCommandCharacterWindow();
									FoodCommandCharacterWindow();
									MenuComand(&this->bUsingCharacterWindow);

									if (this->playerCommandInput != "items", "food", "menu")
									{
										goto here;
									}
									
											

									
				}
			}
		
	void Player::BackCommandCharacterWindow()
	{
		if (this->playerCommandInput == "back")
		{
			bUsingCharacterWindow = false;
			GameMenu();

		}
	}

void Player::PrintCurrentStatsMax()
		{
			cout << "[X][CHARACTER STATS][X]" << endl << endl;
			cout << "  [NAME]" << "[ " << this->GetName() << " ]" << endl;
			cout << "  [HEALTH]" << "[ " << this->GetHealth() << "/10" << " ]" << endl;
			cout << "  [STAMINA]" << "[ " << this->GetStamina() << "/10" << " ]" << endl;
			cout << "  [HYDRATION]" << "[ " << this->GetHydration() << "/20" << " ]" << endl;
			cout << "  [HUNGER]" << "[ " << this->GetHunger() << "/20" << " ]" << endl;
			cout << "  [SANITY]" << "[ " << this->GetSanity() << "/15" << " ]" << endl;
			cout << "  [STEPS]" << "[ " << this->GetSteps() << " ]" << endl;
		}
void Player::PrintAllInventoryItems(){
					cout << "[X][ITEMS]" << endl;
					std::vector<Item*> Inventory = GetInventory();
				
					for (int i = 0; i < Inventory.size(); i++){
						cout << "[" << i << "]" << Inventory[i]->GetName() << endl;
					}

					cout << endl << endl;
				
				}
void Player::PrinAllComsumableTiems(){
					cout << "[X][COMSUMABLE]" << endl;
					std::vector<Comsumables*> Comsumables = GetComsumables();

					for (int i = 0; i < Comsumables.size(); i++){
						if (i > 0) {
							cout << "["<<i<<"]" << Comsumables[i]->GetName() << endl;
						}

						
					}
				
				
				}
void Player::PrintStatsAndInventoryForCharacterWindow()
		{
			ClearScreen();
			PrintCurrentStatsMax();
			PrintLowerLine(1);
			cout << "[X][INVENTORY][X]" << endl << endl;
			this->PrintAllInventoryItems();
			this->PrinAllComsumableTiems();
			PrintLowerLine(1);
		}

		void Player::PleaseEnterRightInput()
		{
			std::cout << "[PLEASE ENTER RIGHT INPUT]" << std::endl;
			AnyKeyToContinueAndClearScreen();

		}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

		/*LOAD,SAVE,NEW,QUIT*/

void Player::NewGame(bool* bWindowToClose){
PrinAreYouShure("DO YOU WANT TO START NEW GAME", true);

	if (this->playerInputIntMainMenu == 1) {

			bool temp = false;
			bWindowToClose = &temp;
			ClearScreen();
			PrintLowerLine(2);

				this->name = AskForPlayerInputSTRING("[ENTER CHARACTER NAME:]", true);
				this->bIsPlaying = true;
				this->GameMenu();
	}

	else if (this->playerInputIntMainMenu == 2) {

		GoBackToRightMenu();
	}

	else
		NewGame(nullptr);
}

void Player::LoadCharacter()
{
	PrinAreYouShure("DO YOU WANT TO LOAD CHARACTER", true);

	if (this->playerInputIntMainMenu == 1) {

		PrintAllTXTFiles();
		ReadSaveFileAndStartGame();
	}
	else if (this->playerInputIntMainMenu == 2) {

		GoBackToRightMenu();
	}
	else

		LoadCharacter();
}
	void Player::ReadSaveFileAndStartGame(){

		//ask for name of the file
		cout << "ENTER LOAD NAME" << endl;
		cin >> filename;
		filename += ".txt";

		std::ifstream file2;
		std::string line;
		stringstream ss;

		file2.open(filename, std::ifstream::in);

			while (file2 >> line) {
				ss.str(line);

				ss >> this->name;
				ss >> this->health;
				ss >> this->stamina;
				ss >> this->hydration;
				ss >> this->hunger;
				ss >> this->sanity;
				ss >> this->steps;

				ss >> this->bTravelingbool;
				ss >> this->bIsInteractingWithEniviroment;

				ss >> this->bquit;
				ss >> this->bFirstMenuScreen;
				ss >> this->bIsPlaying;
				ss >> this->bUsingCharacterWindow;
				ss >> this->bUsingHelp;
			}

				file2.close();
				this->GameMenu();
	}

void Player::SaveCharacter()
{

	PrinAreYouShure("DO YOU WANT TO SAVE CHARACTER", true);

	if (this->playerInputIntMainMenu == 1) {
		PrintAllTXTFiles();
		WriteSaveFile();
	}
	else if (this->playerInputIntMainMenu == 2) {
		GoBackToRightMenu();
	}
	else
		SaveCharacter();

}
	void Player::WriteSaveFile(){

		//create stream
		cout << "ENTER SAVE NAME" << endl;
		cin >> filename;
		filename += ".txt";

		std::ofstream MyFile;
		MyFile.open(filename, std::ofstream::out | std::ofstream::app);

			if (MyFile.is_open()){
				MyFile << SendCharacterInfoToString();
				std::cout << "Character Saved<<" << endl;
				//u need objects or function to insert in to file
				AnyKeyToContinueAndClearScreen();
				MyFile.close();
			}

			else
				MyFile.close();
				std::cout << "Save unsuccesfull<<" << endl;
				std::cout << "Closed<<" << endl;
				WaitForAnyInput();
				SaveCharacter();
				
	}
		std::string Player::SendCharacterInfoToString()const
{
	return		  //Send basic stats to save file
		name + "\n" +
		std::to_string(this->health) + "\n" +
		std::to_string(this->stamina) + "\n" +
		std::to_string(this->hydration) + "\n" +
		std::to_string(this->hunger) + "\n" +
		std::to_string(this->sanity) + "\n" +
		std::to_string(this->steps) + "\n" + "\n" + "\n" +

		(this->currentLocationptr->InforationToString() + "\n") +

		std::to_string(this->bTravelingbool) + "\n" +
		std::to_string(this->bIsInteractingWithEniviroment) + "\n" +

		std::to_string(this->bquit) + "\n" +
		std::to_string(this->bFirstMenuScreen) + "\n" +
		std::to_string(this->bIsPlaying) + "\n" +
		std::to_string(this->bUsingCharacterWindow) + "\n" +
		std::to_string(this->bUsingHelp) + "\n";
}

void Player::Quit(bool* bWindowToClose)
{
START:
	ClearScreen();
		PrinAreYouShure("[ARE YOU SURE ?]", true);
		//exit software after pressing 1
		if (this->playerInputIntMainMenu == 1) {
			exit(0);
		}
		//go back to previous menu if pressed 2
		else if (this->playerInputIntMainMenu == 2) {
			GoBackToRightMenu();
		}
		//if user gives wrong input (not 1 or 2) go back to beggining
		else if (this->playerInputIntMainMenu < 1 && this->playerInputIntMainMenu > 2) {
			cout << "ENTER RIGHT NUMBER" << endl;
			goto START;
		}

}
	
void Player::PrintAllTXTFiles()
{
	
	std::string path = "C:/Users/Fabian/Desktop/irehgkjtrbigrse/GameProgrammingPatternsAssigmentV23/GameProgrammingPatternsAssigment";


	try {
		for (const auto& file : std::filesystem::directory_iterator::directory_iterator(path))
		{
			

			if (file.path().extension() == ".txt")
			{
				std::cout << file.path().filename() << std::endl;
			}

		}
	}
	catch (const std::filesystem::filesystem_error& ex)
	{
		std::cout << "Exception: " << ex.what() << '\n';
	}
	
}
void Player::GoBackToRightMenu()
{
	if (this->bIsPlaying) {
		GameMenu();
	}
	else if (this->bFirstMenuScreen) {
		FirstMenuScreen(nullptr);
	}
}

	

/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

		//Student Information
void Player::DeveloperInformation()
	{
			PrintLowerLine(1);
				cout << "[TITLE] STALKER" << endl;
				cout << "[DEVELOPER] Fabian Pryba" << endl;
				cout << "[ID] w1836469" << endl;
			PrintLowerLine(1);
			cout << endl << endl;
				AnyKeyToContinueAndClearScreen();
	}
		
	
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/