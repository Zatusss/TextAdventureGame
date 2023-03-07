#pragma once
#include <string>
class Item
{
protected:
//Info var
		std::string name;//ASSIGMENT
		std::string description;//ASSIGMENT
public:
//Getters
		std::string GetName() { return this->name; }//ASSIGMENT
		std::string GetDescription() { return this->description; }//ASSIGMENT
//Setters
		std::string SetName(std::string set) {this->name = set ;return this->name; }//ASSIGMENT
		std::string SetDescription(std::string set) {this->description = set ;return this->description; }//ASSIGMENT

//constructor
		Item(std::string name, std::string description);//ASSIGMENT
};

