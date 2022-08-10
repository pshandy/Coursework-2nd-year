/*
 * Weapon.cpp
 *
 *  Created on: May 28, 2022
 *      Author: pshandy
 */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType()
{
	return (type);
}
