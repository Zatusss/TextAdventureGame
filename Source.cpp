#include "Player.h"
#include "Location.h"
#include "Container.h"


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

/*

int main()
{
	//THIS MUST GO US FSTREAM INSTEAD
	
	//Create new vector to store items to collect
	//Create Items to store
	//push items in to the vector

	vector<Item*> crossRoadItems;
		Item Rubish("Rubish", "Rubish");
		Item EmptyBootle("EmptyBootle", "EmptyBootle");
		Item Pin("Pin", "Can be used to open locks");
			crossRoadItems.push_back(&Rubish);
			crossRoadItems.push_back(&EmptyBootle);
			crossRoadItems.push_back(&Pin);

	//Create vector for all containers u want player to possibly serch
	//Create you containers
	//add them to vector of containers

	vector<Container*>crossRoadContainers;
		bool bTentLock = false;
		Container Tent{ "Tent", "Old Camping Tent", &crossRoadItems, &EmptyBootle, bTentLock };
		bool bBackPackLock = true;
		Container BackPack{ "BackPack", "Old school backpack ", &crossRoadItems, &Pin, bBackPackLock };
			crossRoadContainers.push_back(&Tent);
			crossRoadContainers.push_back(&BackPack);

	//Create Locations 
	//give it name/description
	Location CrossCroad(
		1,
		"CrossCroad",
		"Where to go?",
		&crossRoadItems,
		&crossRoadContainers,
		nullptr, nullptr, nullptr, nullptr);


	//Evry locations is the same so for just focuse on the tpop


	Location Farm(
		2,
		"Farm",
		"Aboded farm that was left right before the apocalypse"
		"Try to search so rounding area for any usefully items when your ready start going towards the town ",
		&crossRoadItems,
		&crossRoadContainers,
		
		nullptr, nullptr, nullptr, nullptr);

	Location Field(
		4,
		"Field",
		"Calm and peacefull place",
		&crossRoadItems,
		&crossRoadContainers,
		
		nullptr, nullptr, nullptr, nullptr);

	Item keyToTheFarm("keyToTheFarm", "keyToTheFarm");
	Location EmptyCampSide(
		5,
		"Empty Camp Side",
		"Empty Camp Side",
		&crossRoadItems,
		&crossRoadContainers,
		
		nullptr, nullptr, nullptr, nullptr);

	Location PathToTheCity(
		3,
		"Path to the city",
		"Adventure begin",
		&crossRoadItems,
		&crossRoadContainers,
		nullptr, nullptr, nullptr, nullptr);


	//crosscroad connections
	CrossCroad.SetWestptr(&Farm);
	Farm.SetEastptr(&CrossCroad);

	CrossCroad.SetEastptr(&Field);
	Field.SetWestptr(&CrossCroad);

	CrossCroad.SetNorthptr(&PathToTheCity);
	PathToTheCity.SetSouthptr(&CrossCroad);

	CrossCroad.SetSouthptr(&EmptyCampSide);

	EmptyCampSide.SetNorthptr(&CrossCroad);
	
	

	Player player(&CrossCroad);
	player.GameMenu();
	return 0;
	
	
	
	
	
	

	
}

*/