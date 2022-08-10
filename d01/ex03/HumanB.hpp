/*
 * HumanB.hpp
 *
 *  Created on: May 28, 2022
 *      Author: pshandy
 */

#ifndef HUMANB_HPP_
#define HUMANB_HPP_

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{

private:
	std::string name;
	Weapon 		*weapon;

public:

	HumanB	(std::string name);

	void		setWeapon(Weapon& weapon);
	void		attack();

	std::string getName();
	void		setName(std::string name);

};


#endif /* 01_EX03_HUMANB_HPP_ */
