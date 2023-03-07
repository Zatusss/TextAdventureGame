#include "ReadMapDoc.h"

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


#include "Item.h"
#include "Comsumables.h"
#include "Location.h"
#include "Container.h"




ReadMapDoc::ReadMapDoc()
{
   
}
//test
void ReadMapDoc::ReadItems()
{
    std::vector<Item*> AllItems;
   //needed for storing all created items

   
    std::string myLine;//u pas data here
    ReadItemsIfstream.open(ReadItemsDoc, std::ifstream::in);  // File Open in the Read Mode

    if (ReadItemsIfstream.is_open()) {

        // Keep reading the file
        while (getline(ReadItemsIfstream, myLine))
        {   
            if (myLine == "X") {
                std::string name;
                std::string description;

                ReadItemsIfstream >>  name; //assign new item name
                ReadItemsIfstream >> description;//assign new item description

                Item* i = new Item("","");//create new item in heap
                i->SetName(name); //assign new item name
                i->SetDescription(description);//assign new item description
                AllItems.push_back(i);//add new item to vector of items
            }
        }

        ReadItemsIfstream.close();//when done reading throu items close

        //for printing different vector element
        int y = 0;
        //for every item inside vector
        for (Item* i : AllItems)
        {
            //print name and description

            std::cout << AllItems.at(y)->GetName() << std::endl;
            std::cout << AllItems.at(y)->GetDescription() << std::endl << std::endl;;
            y++;
        }
        std::cout << std::endl << "Amout of inventory items[]  " << AllItems.size() << std::endl << std::endl;//print overall size of vetor
    }
    else
    {
        std::cout << "Unable to open the file!";
    }
	
}
void ReadMapDoc::ReadComsumables()
{
   
    std::vector< Comsumables*> AllComsumables;
    std::string myLine;//u pas data here

    ComsumablesIfstream.open(ReadComsumablesDoc,std::ifstream::in);

    if (ComsumablesIfstream.is_open())
    {
        // Keep reading the file
        while (getline(ComsumablesIfstream, myLine))
        {
            if (myLine == "X") {

                Comsumables* i = new Comsumables("", "", 0, 0, 0, 0, 0);//create new item in heap

                std::string name;
                std::string description;

                std::string health;
                std::string stamina;
                std::string hydration;
                std::string hunger;
                std::string sanity;

                ComsumablesIfstream >> name; //assign new item name
                ComsumablesIfstream >> description;//assign new item description

                ComsumablesIfstream >> health;//assign new item description
                ComsumablesIfstream >> stamina;//assign new item description
                ComsumablesIfstream >> hydration;//assign new item description
                ComsumablesIfstream >> hunger;//assign new item description
                ComsumablesIfstream >> sanity;//assign new item description

                
              
                i->SetName(name); //assign new item name
                i->SetDescription(description);//assign new item description

                i->SetHealth(std::stoi(health,nullptr,10));//assign new item description
                i->SetStamina(std::stoi(stamina,nullptr, 10));//assign new item description
                i->SetHydration(std::stoi(hydration,nullptr, 10));//assign new item description
                i->SetHunger(std::stoi(hunger,nullptr, 10));//assign new item description
                i->SetSanity(std::stoi(sanity,nullptr, 10));//assign new item description


                
               AllComsumables.push_back(i);//add new item to vector of items
            }
        }
        ReadItemsIfstream.close();//when done reading throu items close

        

        //for printing different vector element
        int y = 0;
        //for every item inside vector
        for (Comsumables * i : AllComsumables)
        {
            //print name and description

            std::cout << AllComsumables.at(y)->GetName() << std::endl;
            std::cout << AllComsumables.at(y)->GetDescription() << std::endl << std::endl;;

            std::cout <<"Health[ " << AllComsumables.at(y)->GetHealth() << std::endl;
            std::cout << "Stamina[  " << AllComsumables.at(y)->GetStamina() << std::endl;
            std::cout << "Hydration[  " << AllComsumables.at(y)->GetHydration() << std::endl;
            std::cout << "Hunger[  " << AllComsumables.at(y)->GetHunger() << std::endl;
            std::cout << "Sanity[  " << AllComsumables.at(y)->GetSanity() << std::endl<< std::endl<< std::endl;

            y++;
        }
       std::cout << std::endl << "Amout of comsumable items[]  " << AllComsumables.size() << std::endl;//print overall size of vetor



    }
    else
    {
        std::cout << "NOT OPEN" << std::endl;
    }

}
void ReadMapDoc::ReadContainers()
{
}



//different approach
void ReadMapDoc::ReadMap()
{
    std::vector<vector<Item*>*> thisMapLoosItems;
    std::vector<Item*>LooseItems;

    std::vector<vector<Item*>*> PointsOfIntreastItems;
    std::vector<Item* > PointOfitreastItems1;

    std::vector<vector<Container*>*> ThisMapPointsOfIntreast;
    std::vector<Container *> PointsOfIntreast;

    std::vector<Location * > Locations;
    int locationnr = 0;
    //needed for storing all created items


    std::string myLine;//u pas data here
    MapIfstream.open(ReadMaprDoc, std::ifstream::in);  // File Open in the Read Mode

    if (MapIfstream.is_open()) {

        // Keep reading the file
        while (getline(MapIfstream, myLine))
        {
            
            //creating loos items
            if (myLine == "U")
            {
                std::vector<Item*>* temp = new std::vector<Item*>;
                *temp = LooseItems;
                thisMapLoosItems.push_back(temp);
                LooseItems.clear();

            }
            if (myLine == "I") {               
                std::string name;
                std::string description;
                    MapIfstream >> name; //assign new item name
                    MapIfstream >> description;//assign new item description

                Item* i = new Item("", "");//create new item in heap
                    i->SetName(name); //assign new item name
                    i->SetDescription(description);//assign new item description
                    LooseItems.push_back(i);//add new item to vector of items
            }


            //items for container
            if (myLine == "E")
            {
                std::vector<Item*>* Itemp = new std::vector<Item*>;
                *Itemp = PointOfitreastItems1;
                PointsOfIntreastItems.push_back(Itemp);
                PointOfitreastItems1.clear();
            }
            if (myLine == "R")
            {
                std::string name;
                std::string description;
                MapIfstream >> name; //assign new item name
                MapIfstream >> description;//assign new item description

                Item* i = new Item("", "");//create new item in heap
                i->SetName(name); //assign new item name
                i->SetDescription(description);//assign new item description
                PointOfitreastItems1.push_back(i);//add new item to vector of items
            }
            //container
            if (myLine == "C") {

                std::string * name = new  std::string;
                std::string * description = new  std::string;
                std::vector<Item*>* ItemsIndise =  new std::vector<Item *>;
                Item* KeyItem = new Item("","");
                bool * lock = new bool;
                    MapIfstream >> *name; //assign new item name
                    MapIfstream >> *description; //assign new item name
             
                        Container* i = new Container("", "", nullptr, nullptr, false);//create new item in heap
                        i->SetName(*name); //assign new item name
                        i->SetDescription(*description);//assign new item description
                        i->SetContents(PointsOfIntreastItems.at(locationnr));//assign new item description

                        PointsOfIntreast.push_back(i);//add new item to vector of items
            }
            if (myLine == "X")
            {
               

                std::vector<Container *>* Ctemp = new vector<Container *>;
                *Ctemp = PointsOfIntreast;
                ThisMapPointsOfIntreast.push_back(Ctemp);

                
                PointsOfIntreast.clear();
            }
            //creating Location
            if (myLine == "L")
            {
                std::string* name = new  std::string;
                std::string* description = new  std::string;
                int * locationindex = new  int;


                MapIfstream >> *name;
                MapIfstream >> *description;
                MapIfstream >> *locationindex;

                
               
                

                Location* i = new Location(*locationindex,*name, 
                    *description, thisMapLoosItems.at(locationnr),ThisMapPointsOfIntreast.at(locationnr),
                    nullptr,nullptr,nullptr,nullptr);
                
                Locations.push_back(i);
                locationnr++;
            }

            //create location Connaction
        }
        MapIfstream.close();//when done reading throu items close
        
        int n = 0;
       
        for (Location* i : Locations)
        {
            std::cout << std::endl << "[---]Location[---]" << std::endl;
            std::cout << std::endl << Locations.at(n)->GetName() << std::endl;
            std::cout << Locations.at(n)->GetDescription() << std::endl;
            std::cout << Locations.at(n)->GetLocationIndex() << std::endl << std::endl;
            
            
            
            int y = 0;
            std::cout << "[---]Loose Items[---]" << std::endl;
            for (Item* i : *Locations.at(n)->GetItemsinsideLocation())
            {
                //print name and description

                std::cout << "[NAME]" << Locations.at(n)->GetItemsinsideLocation()->at(y)->GetName() << std::endl;
                std::cout << "DESCRIPTION" << Locations.at(n)->GetItemsinsideLocation()->at(y)->GetDescription() << std::endl << std::endl;;


                y++;
            }
            std::cout << "[---]Points Of Intreas[---]" << std::endl;
            int x = 0;
            for (Container* i : *Locations.at(n)->GetContainer())
            {
                //print name and description
                std::cout << "[NAME]" << Locations.at(n)->GetContainer()->at(x)->GetName() << std::endl;
                std::cout << "[DESCRIPTION]" << Locations.at(n)->GetContainer()->at(x)->GetDescription() << std::endl << std::endl;
                

                int z = 0;
                for (Item* i : *Locations.at(n)->GetContainer()->at(x)->GetContents())
                {
                    std::cout << "[NAME]" << Locations.at(n)->GetContainer()->at(x)->GetContents()->at(z)->GetName() << std::endl;
                    z++;
                }


            }

            n++;
        }

    }
    else
    {
        std::cout << "Unable to open the file!";
    }
}





/**/
int main()
{
	ReadMapDoc a;
    a.ReadMap();
	
	return 0;
}



