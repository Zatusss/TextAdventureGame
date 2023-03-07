#pragma once

#include "Container.h"
#include "Item.h"
#include <string>
#include <vector>

using namespace std;
class Location
{
private:
	//basic variables
	int locationindex;//ASSIGMENT
	string locationName;//ASSIGMENT
	string description;//ASSIGMENTv
	

	//variables for opening closing location using item
	

	//Points of intrest / loos items
	vector<Item*>* contentsOfThisLocation;//ASSIGMENT
	vector<Container*>* Containers;//ASSIGMENT
	
	
	//Connected Locations
	Location* northptr;//ASSIGMENT
	Location* southptr;//ASSIGMENT
	Location* westptr;//ASSIGMENT
	Location* eastptr;//ASSIGMENT

	
	
	

public:

	std::string GameData = "GameData";//ASSIGMENT

	//constructor
	Location(int locationindex, string locationName, string description,
			vector<Item*>* contentsOfThisLocation, vector<Container*>* Containers,Location* northptr, Location* southptr,
			Location* westptr, Location* eastptr);
	

	//GETTERS
		//info
			string GetName() { return this->locationName; };
			string GetDescription() { return this->description; };
		//items
			vector<Item*>* GetItemsinsideLocation() { return this->contentsOfThisLocation; };
			vector<Container*>*GetContainer() { return this->Containers; };
		//connected roads
			Location* GetNorthptr() { return this->northptr;}
			Location *GetSouthptr() { return this->southptr;}
			Location *GetWestptr() { return this->westptr;}
			Location *GetEastptr() { return this->eastptr;}
			int GetLocationIndex() { return this->locationindex;}
	
	
	//SETTERS
			void SetNorthptr(Location* location) {this->northptr = location; }
			void SetSouthptr(Location* location) { this->southptr = location; }
			void SetWestptr(Location* location) { this->westptr = location; }
			void SetEastptr(Location* location) { this->eastptr = location; }


//Print all info about current location
void PrintLocation(Location* location);//ASSIGMENT
//-------------------------------------------------------------
			void PrintThisLocationLooseLoot();
			void PrintThisLocationPointsOfIntreast();
			void PrintAllConnectedRoads();//ASSIGMENT

std::string InforationToString();
//Location interact with item functions
			bool TakeLooseItem(int playerInputIntMainMenu);//ASSIGMENT
			bool TakeAllLoosItems();
			bool TakeContainerItem(Item* Itemp,Container* Ctemp,int * playerInputIntMainMenu);//ASSIGMENT
			bool TakeAllContainerItems(Container* Ctemp);
			void drop_item(Item* i);//ASSIGMENT
			Item* getKey(string& direction);//ASSIGMENT
	
	
void ReadData(string filename);
};


