#pragma once
#include "Item.h"
#include "Player.h"
#include <iostream>

class Player;


//Comsumables can increase your current statistics
class Comsumables :
    public Item
{
private:

	int addHealth =0;
	int addStamina=0;
	int addHydration=0;
	int addHunger=0;
	int addSanity=0;

public:

	Comsumables(std::string name, std::string description,int addHealth,
	int addStamina,int addHydration,int addHunger,int addSanity)
		:Item(name, description) {
		this->addHealth = addHealth;
		this->addStamina = addStamina;
		this->addHydration = addHydration;
		this->addSanity = addSanity;
	
	};


	//Getters
	int GetHealth() { return this->addHealth ; };
	int GetStamina() { return this->addStamina ; };
	int GetHydration() { return this->addHydration; };
	int GetHunger() { return this->addHunger ; };
	int GetSanity() { return this->addSanity ; };

	//Setters
	void SetHealth(int set) { this->addHealth = set; };
	void SetStamina(int set) { this->addStamina = set; };
	void SetHydration(int set) { this->addHydration = set; };	
	void SetHunger(int set) { this->addHunger = set; };
	void SetSanity(int set) { this->addSanity = set; };
	//Eat food functions
			void PrintComsumableAttributes(Player * currentplayer) {
	
				std::cout << "[" << currentplayer->GetHealth() << "]" 
					<< "[HEALTH][+]" << this->addHealth << std::endl;

				std::cout<< "[" << currentplayer->GetStamina() << "]" 
					<< "[STAMINA][+]" << this->addStamina << std::endl;

				std::cout<< "[" << currentplayer->GetHydration() << "]" 
					<< "[HYDRATION][+]" << this->addHydration << std::endl;

				std::cout<< "[" << currentplayer->GetHunger() << "]" 
					<< "[HUNGER][+]" << this->addHunger << std::endl;

				std::cout<< "[" << currentplayer->GetSanity() << "]" 
					<< "[SANITY][+]" << this->addSanity << std::endl;
			}
			void UpdateCharacterStatistics(Player* currentplayer)
			{
				currentplayer->AddHealth(this->addHealth);
				currentplayer->AddStamina(this->addStamina);
				currentplayer->AddHydration(this->addHydration);
				currentplayer->AddHunger(this->addHunger);
				currentplayer->AddSanity(this->addSanity);

			}
};

