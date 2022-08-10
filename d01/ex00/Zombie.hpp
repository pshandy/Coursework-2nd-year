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

	void announce( void );

};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );


#endif
