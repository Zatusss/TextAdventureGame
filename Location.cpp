#include "Player.h"
#include "Location.h"
#include "Container.h"



#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdlib.h>

using namespace std;

Location::Location(int locationindex, string locationName, string description,
	vector<Item*> * contentsOfThisLocation, vector<Container*> * Containers, Location* northptr, Location* southptr,
	Location* westptr, Location* eastptr) 
{

	this->Containers = Containers;
	this->locationName = locationName;
	this->locationindex = locationindex;
	this->description = description;

	this->northptr = northptr;
	this->southptr = southptr;
	this->westptr = westptr;
	this->eastptr = eastptr;

	this->contentsOfThisLocation = contentsOfThisLocation;
}

//Print current location info
 void Location::PrintLocation(Location* location)
{
	
	 cout << "[][CURRENT LOCATION INFO][]" << endl;
	//Print name of current location
	cout << " [NAME]" << endl;
	cout << "   " << location->GetName() << endl;
	//Print description of current location
	cout << " [DESCRIPTION]" << endl;
	cout << "   " << location->GetDescription() << endl;
	//Print points of intrest
	cout<<endl;
	PrintThisLocationPointsOfIntreast();
	PrintThisLocationLooseLoot();
	//pritn all connected roads
	PrintAllConnectedRoads();
	system("pause");
}
 //-------------------------------------------------------------
			 void Location::PrintThisLocationLooseLoot()
			 {
				 vector<Item*>* listOfItemsInThisLocation = GetItemsinsideLocation();
				
				 cout << "[]LOOSE ITEMS[]" << endl;
				 for (int i = 0; i < listOfItemsInThisLocation->size(); i++) {
					 if (i > 0) {
						 cout << "  [" << i << "]" << listOfItemsInThisLocation->at(i)->GetName() << " " << endl;
					 }
					 
				 }
				 cout << endl<<endl;
			 }
			 void  Location::PrintThisLocationPointsOfIntreast(){
			 cout << "[]POINTS OF INTREAST[]" << endl;
				std::vector<Container*>* Containers = this->GetContainer();
					 for (int i = 0; i < Containers->size(); i++){
						 cout << "  [" << i << "]" <<"[NAME]->>" << " " << Containers->at(i)->GetName() << endl;
						 cout << "  [" << i << "]" << "[DESCRIPTION]->>" << " " << Containers->at(i)->GetDescription() <<
						 endl<<endl<<endl; 
					 }
				
			 }
			 void  Location::PrintAllConnectedRoads(){
			  //if choosen direction is not null
			  //print name of the connected location
			  //else print XXXXXXX
				cout << " [][ROADS][]" << endl;
				cout << "  [][NORTH]";
						
				if (this->GetNorthptr() != nullptr) {
				cout << this->GetNorthptr()->GetName() << endl;
				}
							
				else
				{
				cout << "XXXXXXX" << endl;
				} 
				cout << "  [][EAST]";
				if (this->GetEastptr() != nullptr) 

				{
				cout << this->GetEastptr()->GetName() << endl;
				}
				else
				{
				cout << "XXXXXXX" << endl;
				}
				cout << "  [][SOUTH]";


				if (this->GetSouthptr() != nullptr) {
				cout << this->GetSouthptr()->GetName() << endl;
				}
				else
				{
				cout << "XXXXXXX" << endl;
				}

			cout << "  [][WEST]";
			if (this->GetWestptr() != nullptr) {
			cout << this->GetWestptr()->GetName() << endl;
			}
			else {
			cout << "XXXXXXX" << endl;
						}
				}


//For Saving Game
std::string Location::InforationToString()
{
	return
		GetName() + "\n" +
		GetDescription() + "\n" +
		std::to_string(this->GetLocationIndex()) + "\n";
		
}

bool Location::TakeLooseItem(int playerInputIntMainMenu)
{
	std::swap(contentsOfThisLocation->at(playerInputIntMainMenu), contentsOfThisLocation->back());
	//std::cout << comsumables.at(playerInputIntMainMenu) << std::endl;
	this->contentsOfThisLocation->pop_back();



	return false;
}

bool Location::TakeAllLoosItems()
{
	this->contentsOfThisLocation->clear();
	return false;
}

bool Location::TakeContainerItem(Item * Itemp,Container * Ctemp, int * intChoosenItem)
{
	Item* Itempp = Itemp;

	Container * Ctempp = Ctemp;
	
	int * intChoosenItemm = intChoosenItem;

	Ctemp->RemoveItem( Itempp , Ctempp, intChoosenItemm);
	return true;
}

bool Location::TakeAllContainerItems(Container* Ctemp)
{
	Ctemp->RemoveAllItems();
	return false;
}



void Location::drop_item(Item * i)
{

	this->contentsOfThisLocation->push_back(i);
}


//Main Shit be carful

void Location::ReadData(string filename)
{


	//strucutre of Items,Container,Location
	/*

	//Loost items scrusture
	vector<Item*> crossRoadItems;
	Item EmptyBootle("EmptyBootle", "EmptyBootle");
	Item Pin("Pin", "Can be used to open locks");
		crossRoadItems.push_back(&EmptyBootle);
		crossRoadItems.push_back(&Pin);
	

//Containers structure
	vector<Container*>crossRoadContainers;
	Container Tent{ "Tent", "Old Camping Tent", crossRoadItems, &EmptyBootle, true };
	Container BackPack{ "BackPack", "Old school backpack ", crossRoadItems, &Pin, true };
		crossRoadContainers.push_back(&Tent);
		crossRoadContainers.push_back(&BackPack);
			bool bBackPackLock = true;
			bool bTentLock = false;



//Location Data
	Location CrossCroad(
	1,"CrossCroad",
	"Where to go?",
	crossRoadItems,
	crossRoadContainers,
	nullptr, nullptr, nullptr, nullptr);
//connecting paths
			CrossCroad.SetEastptr(nullptr);
			CrossCroad.SetWestptr(nullptr);
			CrossCroad.SetNorthptr(nullptr);
			CrossCroad.SetNorthptr(nullptr);
*/
}

