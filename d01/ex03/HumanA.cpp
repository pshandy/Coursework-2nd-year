/*
 * HumanA.cpp
 *
 *  Created on: May 28, 2022
 *      Author: pshandy
 */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{

}

void	HumanA::attack()
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}


std::string HumanA::getName()
{
	return (name);
}

void		HumanA::setName(std::string name)
{
	this->name = name;
}
