/*
 * Weapon.hpp
 *
 *  Created on: May 28, 2022
 *      Author: pshandy
 */

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>

class Weapon
{

private:
	std::string type;

public:

	Weapon(std::string);

	void				setType(std::string type);
	const std::string&	getType();

};


#endif
