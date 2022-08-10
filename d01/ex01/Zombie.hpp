/*
 * Zombie.hpp
 *
 *  Created on: May 27, 2022
 *      Author: pshandy
 */

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <iostream>

class Zombie
{

private:
	std::string name;

public:

	Zombie();
	Zombie(std::string name);
	virtual ~Zombie();

	void 		setName(std::string name);
	std::string getName();

	void 		announce( void );

};

Zombie* zombieHorde( int N, std::string name );

#endif
