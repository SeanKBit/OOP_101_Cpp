// SolarSystemObj.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Demonstrate some key "object-oriented" / Cpp concepts, such as: static variables, vectors, pointers and reference variables, encapsulation/abstraction through classes, function overloading

#include "Planet.h"
#include <iostream>

static std::vector<Planet> vectorPlanets;

void createVectorPlanets(Planet);
void listAllUserPlanets(std::vector<Planet>);

int main()
{
    std::string exitStr;
    std::cout << "Enter \"end\" to exit program..." << std::endl;

    while (true)
    { 
        static std::string inputName;
        std::cout << "Enter name of planet in our solar system: ";
        std::cin >> inputName;

        if (inputName != "end")
        {
            static int listCounterStatic = 1; // intialized only once as static, so OK to put here
            int listCounterFail = 1; // demonstrate non-static variable
            Planet userPlanet(inputName);
            createVectorPlanets(userPlanet);
            std::cout << "Planet : " << userPlanet.getName() << std::endl;
     
            std::cout << "Planet (in lowercase): " << userPlanet.getName(userPlanet.getName()) << std::endl; // Calling overloaded function of getName(string), both return strings
           
            std::cout << "Habitable Zone : " << userPlanet.isHabitable() << std::endl;
            std::cout << "Distance from sun (AU) : " << userPlanet.getDistance() << std::endl;

            double size = userPlanet.getSize();
            double *sizeKm = &size; // Example of pointer to size address
            std::cout << "Diameter of planet (Miles) : " << *sizeKm << std::endl; // Using pointer to dereference address and access value
            
            size = size * 1.60934; // Converting original value at referenced address
            std::cout << "Diamter of planet (Kilometers) : " << *sizeKm << std::endl; // Now sizeKm will output the new value stored in size address
            std::cout << std::endl;

            std::cout << "\nStatic listCounter: " << listCounterStatic << "\n" << std::endl; // static variable continues to "update" due to only first initialization
            listCounterStatic++;
            std::cout << "\nNon-static listCounter: " << listCounterFail << "\n" << std::endl; // non-static gets "reset" because it is initialized each loop
            listCounterFail++;
        }
        else
        {
            break;
        }
    }

    listAllUserPlanets(vectorPlanets);
    
}

// pushes Planet object to back of vector of Planet types, dynamic in size
void createVectorPlanets(Planet pName)
{
    vectorPlanets.push_back(pName);
}

// iterates through Planet vector using simple for loop to output attributes of each element
void listAllUserPlanets(std::vector<Planet> vPlanets)
{
    std::cout << "\n\nHere is a list of all the planets you enterd: " << std::endl;
    for (int i = 0; i < vPlanets.size(); ++i)
    {
        std::cout << "\nName: " << vPlanets[i].getName() <<"\nHabitable Zone: " << vPlanets[i].isHabitable() << "\nDistance: " << vPlanets[i].getDistance() << "\nSize: " << vPlanets[i].getSize() << "\n";
    }
}





















#include "Planet.h"
#include <string>
#include <algorithm>
#include <iostream>


Planet::Planet() // Default constructor
{
	setName("none"); // set for safety to some value.
}

Planet::Planet(std::string name) // Parameterized constuctor definition
{
	setName(name);
}

Planet::~Planet() {}; // Destructor (default)


// Uses string to initilize instance of enum class
void Planet::setName(std::string name) 
{
	std::transform(name.begin(), name.end(), name.begin(), ::toupper);

	if (name == "MERCURY")
	{
		PlanetName Mercury = PlanetName::MERCURY;
		assignPlanet(Mercury);
	}
	else if (name == "VENUS")
	{
		PlanetName Venus = PlanetName::VENUS;
		assignPlanet(Venus);
	}
	else if (name == "EARTH")
	{
		PlanetName Earth = PlanetName::EARTH;
		assignPlanet(Earth);
	}
	else if (name == "MARS")
	{
		PlanetName Mars = PlanetName::MARS;
		assignPlanet(Mars);
	}
	else if (name == "JUPITER")
	{
		PlanetName Jupiter = PlanetName::JUPITER;
		assignPlanet(Jupiter);
	}
	else if (name == "SATURN")
	{
		PlanetName Saturn = PlanetName::SATURN;
		assignPlanet(Saturn);
	}
	else if (name == "URANUS")
	{
		PlanetName Uranus = PlanetName::URANUS;
		assignPlanet(Uranus);
	}
	else if (name == "NEPTUNE")
	{
		PlanetName Neptune = PlanetName::NEPTUNE;
		assignPlanet(Neptune);
	}
	else if (name == "PLUTO")
	{
		PlanetName Pluto = PlanetName::PLUTO;
		assignPlanet(Pluto);
	}
	else
	{
		std::cout << "You did not enter a correct planet!" << std::endl;
		std::cout << "Back home for you! To... EARTH" << std::endl;
		PlanetName Earth = PlanetName::EARTH; // default to this
		assignPlanet(Earth);
	}

}

// Assigns set attributes to enumerator 
void Planet::assignPlanet(PlanetName planetname)
{
	switch (planetname)
	{
	case PlanetName::MERCURY:
		m_sizeMiles = 3031.00;
		m_distanceAU = 0.39;
		m_habitableStr = "no";
		m_name = "MERCURY";
		break;

	case PlanetName::VENUS:
		m_sizeMiles = 7521.00;
		m_distanceAU = 0.723;
		m_habitableStr = "yes";
		m_name = "VENUS";
		break;

	case PlanetName::EARTH:
		m_sizeMiles = 7926.00;
		m_distanceAU = 1.00;
		m_habitableStr = "yes";
		m_name = "EARTH";
		break;

	case PlanetName::MARS:
		m_sizeMiles = 4222.00;
		m_distanceAU = 1.524;
		m_habitableStr = "yes";
		m_name = "MARS";
		break;

	case PlanetName::JUPITER:
		m_sizeMiles = 88729.00;
		m_distanceAU = 5.203;
		m_habitableStr = "no";
		m_name = "JUPITER";
		break;

	case PlanetName::SATURN:
		m_sizeMiles = 74600.00;
		m_distanceAU = 9.539;
		m_habitableStr = "no";
		m_name = "SATURN";
		break;

	case PlanetName::URANUS:
		m_sizeMiles = 32600.00;
		m_distanceAU = 19.18;
		m_habitableStr = "no";
		m_name = "URANUS";
		break;

	case PlanetName::NEPTUNE:
		m_sizeMiles = 30200.00;
		m_distanceAU = 30.06;
		m_habitableStr = "no";
		m_name = "NEPTUNE";
		break;

	case PlanetName::PLUTO:
		m_sizeMiles = 1413.00;
		m_distanceAU = 39.53;
		m_habitableStr = "no";
		m_name = "PLUTO";
		break;

	default:
		std::cout << "This shouldn't happen...";

	}
}

double Planet::getSize() 
{ 
	return m_sizeMiles; 
}

double Planet::getDistance() 
{ 
	return m_distanceAU; 
}

std::string Planet::isHabitable() 
{ 
	return m_habitableStr; 
}

std::string Planet::getName()
{
	return m_name;
}

// Example of overloaded version of previous function
std::string Planet::getName(std::string strName)
{
	std::transform(strName.begin(), strName.end(), strName.begin(), ::tolower);
	return strName;
}





















// Planet.h used to demonstrate header files, constructors, destructor, enum class, setters and getters

#pragma once
#include <string>
#include <vector>

class Planet
{

private:
	double m_sizeMiles;
	double m_distanceAU;
	std::string m_habitableStr;
	std::string m_name;
	
	enum class PlanetName { MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO }; // a simple enum, as opposed to enum class, would have worked fine for this case


public:
	Planet(); // Default constructor

	Planet(std::string); // Parameterized constructor declaration

	~Planet(); // Destructor

	void setName(std::string); // setter
	void assignPlanet(PlanetName);

	std::string getName(); // getter
	std::string getName(std::string); // OVERLOADED function
	std::string isHabitable();
	double getSize(); 
	double getDistance(); 
	
};




