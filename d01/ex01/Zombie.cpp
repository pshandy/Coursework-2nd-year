/*
 * Zombie.cpp
 *
 *  Created on: May 27, 2022
 *      Author: pshandy
 */

#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << ": is dead...er." << std::endl;
}

void Zombie::announce( void )
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void 		Zombie::setName(std::string name)
{
	this->name = name;
}

std::string Zombie::getName()
{
	return (name);
}
