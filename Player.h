#pragma once
#include "Item.h"
#include "Location.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


class Comsumables;

class Player
{
private:
	
	
	
	//PLAYER INPUT
			std::string playerCommandInput;
			int playerInputIntMainMenu;

	//STATISTICS
			string name;
			int health;
			int stamina;
			int hydration;
			int hunger;
			int sanity;
			int steps;//ASSIGMENT

	//INVENTORY
				std::vector<Item*> inventory;//ASSIGMENT//Player items inventory
				std::vector<Comsumables*> comsumables;//player food inventory

	//LOCATION VAR
				int currentLocationIndex;
				Location* currentLocationptr;//ASSIGMENT

	//WINDOWS BOOLS
				bool bIsPlaying;
				bool bTravelingbool;
				bool bIsInteractingWithEniviroment;
				bool bquit;
				bool bFirstMenuScreen;
				bool bUsingHelp;
				bool bUsingCharacterWindow;
	
	
	//LOAD,SAVE,NEW GAME
				Player *currentCharacter;
				std::vector<Player*> characters;
				int activeCharacter;
				
				




	
	
public:

	std::string filename;
	std::string MyFile;



	//Constructor/Destructor
	Player(Location *location);

	//GETTERS
	
			//location
				int GetCurrentLocationIndex() { return this->currentLocationIndex; }
				Location* GetLocation() { return this->currentLocationptr; }
			//stats
				string GetName() { return this->name; }
				int GetSteps() { return this->steps; }
				int GetHealth() { return this->health; }
				int GetStamina() { return this->stamina; }
				int GetHydration() { return this->hydration; }
				int GetSanity() { return this->sanity; }
				int GetHunger() { return this->hunger; }
			//inventory
				vector<Item*> GetInventory() { return this->inventory; }
				vector<Comsumables*> GetComsumables() { return this->comsumables; }

	//SETTERS
			//stats
				int AddHealth(int h) { this->health += h; return this->health; }
				int AddStamina(int s) { this->stamina += s; return this->stamina; }
				int AddHydration(int hydrat) { this->hydration += hydrat; return this->stamina; }
				int AddSanity(int s) { this->sanity += s; return this->stamina; }
				int AddHunger(int h) { this->hunger += h; return this->stamina; }
			//location
				void SetLocation(Location* ptr) { this->currentLocationptr = ptr; }
		



	
//Player Commands
		void MenuComand(bool* bWindowToClose);

		bool TakeItemCommand(Container* containerNr,std::vector<Item*>* temp, bool inventoryItem);//ASSIGMENT
		bool DropItemCommand();//ASSIGMENT
		
		bool TakeAllItemsCommand(Item* i, std::vector<Item*>* thisContainerItems,bool takeContainerItem);



//PlayerUI
// 
	//usefull simple print function
		void PrintLowerLine(int loopSize);
		void PrinAreYouShure(std::string sCostumMessage, bool bUseCostumMessage);
		
	//screen clearning/maintenence
		void AnyKeyToContinueAndClearScreen() { system("pause");system("CLS");};
		void ClearScreen() {system("CLS");};
		void WaitForAnyInput() {system("pause");};

	//Menu's
		void GameMenu();
		void FirstMenuScreen(bool* bWindowToClose);
		void PrintFirstMenuOptions();
				void PrintGameMenuOptions();

	//Player Input
		int AskForPlayerInputINT(std::string message, bool useCustomMessage);
		std::string AskForPlayerInputSTRING(std::string message, bool useCustomMessage);


//GAMEPLAY ACTIONS 

	// Travel to location
	void Travel();

					void PrintStatsAndRandomEventsInformation();
					void PrintPunishmentForTravel();
					void PrintAllConnectedRoadsForTravel();
					void PrintCurrentLocationNameAndDescription(bool bnewLocation);
					void TravelInChoosenDirection();
					void TravelsCommandsComand();
					void StatsCommand();
					void LocationsCommand();
				//random events during travel
					int AssignRandomSteps();
					int AssingRandomThirst();
					int AssingRandomHunger();


	//Print current location info
	void PrintCurrentLocation() {
			ClearScreen();
				this->currentLocationptr->
					PrintLocation(this->currentLocationptr);
			}


//Interact with eniviroment
	void InteractWithEniviroment();

	void LookCommand();

	void PrintInteractWithEniviromentWindow();

					void PrintAllIntreastPoints();
					void PrintContainerInformation();
					void PrintAllLooseItems();
			
					void WhatToInteractWith();
					void InteractWithPointsOfIntreast();
					void InteractWithLoosItems();
			
					void OpenContainer();
					void OpenContainerUsingKey();

					void InteractWithEniviromentCommandsComand();


//print character window to use inventory
	void CharacterWindow();

	void CommandsComandCharacterWindow();
	
	void FoodCommandCharacterWindow();

	void PleaseEnterRightInput();
	void WhatToDoWithChoosenInventoryCharacterWindow();
	void UseChoosenItemCharacterWindow(std::vector<Item*>& Inventory);
	
	void ExamineCommandCharacterWindow(std::vector<Item*>& Inventory);
	void BackCommandCharacterWindow();
	void PrintStatsAndInventoryForCharacterWindow();
	void EatCommandCharacterWindow();
	void ItemsCommandCharacterWindow();
	void WhatToDoWithComsumableItemCharacterWindow();
	//ASSIGMENT
					
					void PrintAllInventoryItems();
					void PrinAllComsumableTiems();

//Basic help all comands objectives etc
	void Help(bool* bWindowToClose);

	void PrintHelpWindowOptions();

					void PrintLore();
					void PrintGameObjective();
					void GameObstacles();

					void TravelHelp();
						void PrintTravelCommands();

					void InteractEniviromentHelp();
						void PrintInteractWithEniviromentCommands();
					
					void CharacterWindowHelp();
						void PrintCharacterWindowCommands();


	void NewGame(bool* bWindowToClose);

	void SaveCharacter();
	void WriteSaveFile();
					std::string SendCharacterInfoToString()const;
	void LoadCharacter();

	void ReadSaveFileAndStartGame();

	void PrintAllTXTFiles();
			
	void Quit(bool* bWindowToClose);

	void GoBackToRightMenu();
	
	void DeveloperInformation();
	
	void PrintCurrentStatsMax();
};	


