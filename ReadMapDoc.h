#pragma once
#include <string>
#include <fstream>
#include <sstream>
class ReadMapDoc
{
	
	
	

	
public:
	
	

	ReadMapDoc();

	//adding Items
	std::string ReadItemsDoc = "ReadItemsDoc.txt";
	std::ifstream ReadItemsIfstream;
	//adding comsumables
	std::string ReadComsumablesDoc = "ReadComsumablesDoc.txt";
	std::ifstream ComsumablesIfstream;
	
	//adding containers
	std::string ReadContainersDoc = "ReadContainersDoc.txt";
	std::ifstream ContainersIfstream;
	
	//adding locations
	std::string ReadLocationsDoc = "ReadLocationsDoc.txt";
	std::ifstream LocationsIfstream;

	std::string ReadCharacterDoc = "ReadCharacterDoc.txt";
	std::ifstream CharacterIfstream;
	

	std::string ReadMaprDoc = "ReadMapDoc.txt";
	std::ifstream MapIfstream;


	void ReadItems();
	void ReadComsumables();
	void ReadContainers();
	void ReadMap();


};

