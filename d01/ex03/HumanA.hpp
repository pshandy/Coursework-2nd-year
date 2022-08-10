/*
 * HumanA.hpp
 *
 *  Created on: May 28, 2022
 *      Author: pshandy
 */

#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include "Weapon.hpp"
#include <iostream>

class HumanA
{

private:
	std::string name;
	Weapon &weapon;

public:

	HumanA(std::string name, Weapon& weapon);

	void		attack();

	std::string getName();
	void		setName(std::string name);

};


#endif
