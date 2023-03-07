#pragma once
#include "Item.h"
#include <vector>
#include <string>
#include<algorithm>
#include<iostream>

//Container represents items,locations,points of intrest 
//Container can be open or closed
// If closed player needs to find required item
//player can serch container for loot and add it to inventory
//player can leave items inside container
class Container :public Item
{
private:

	std::vector<Item*>* contents;//ASSIGMENT//Items stored inisde container
	Item* neededKeyItem;//ASSIGMENT//What is needed to open
	bool opendOrClosed = true;//ASSIGMENT//Locaked or closed?
	bool* OpenClosedRef = &opendOrClosed;
public:
//CONSTRUCTOR
		//Inisializer l;ist is required to inisialize parent class variables
		//You can have another definition of constructor in .cpp file
		Container(std::string name, std::string description, 
			std::vector<Item*>* contentsOfContainer,
			Item* neededKeyItem, bool opendOrClosed)
					:Item(name, description), contents(contentsOfContainer), 
					neededKeyItem(neededKeyItem),
					opendOrClosed(opendOrClosed) {};
	
//GETTERS
		std::vector<Item*>* GetContents() { return this->contents; }//Return all items in container
		bool*   CheckIfContainerIsOpen() { return this->OpenClosedRef; }//Return State of container
		Item* GetKeyItem () { return neededKeyItem; }//Return item required by container to open 

		void SetConteinerLock(bool  temp)
		{

			this->OpenClosedRef = &temp;
		}
		void SetContents(std::vector<Item*>* contentsNew) { this->contents = contentsNew; }
		void SetKey(Item*  neededKeyItemNew) { this->neededKeyItem = neededKeyItemNew; }
		void RemoveItem(Item * Itemp, Container * Ctemp, int * playerInputIntMainMenu)
		{
			
			
			if (*playerInputIntMainMenu > 0 && *playerInputIntMainMenu < this->contents->size()-1)
			{
				std::cout << this->contents->size() << std::endl;

				std::swap(this->contents->at(*playerInputIntMainMenu) , this->contents->back());
				//std::cout << comsumables.at(playerInputIntMainMenu) << std::endl;
				this->contents->pop_back();
				std::cout << this->contents->size() << std::endl;
				std::cout << "deleted choosen" << std::endl;
				if (this->contents->size() == 1)
				{
					this->contents->clear();
				}
			}
			else if (*playerInputIntMainMenu + 1 == this->contents->size())
			{
				std::cout << "deleted last" << std::endl;
				this->contents->pop_back();
				std::cout << this->contents->size() << std::endl;
				//this->contents.erase(this->contents.end());
			}
			
			
			
			
			
		}
		void RemoveAllItems()
		{
			this->contents->clear();
		}
	};

	