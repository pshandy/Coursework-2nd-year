/*
 * Harl.cpp
 *
 *  Created on: Jun 15, 2022
 *      Author: pshandy
 */

#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Created" << std::endl;
	levels[0].name = "DEBUG";
	levels[0].function = &Harl::debug;
	levels[1].name = "INFO";
	levels[1].function = &Harl::info;
	levels[2].name = "WARNING";
	levels[2].function = &Harl::warning;
	levels[3].name = "ERROR";
	levels[3].function = &Harl::error;
}

Harl::~Harl() {
	std::cout << "Destroyed" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
	 "I just love it!.\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! "
	 "If you did I would not have to ask for it!.\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
	"I've been coming here for years and you just started working here last month..\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now..\n";
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
		if (level == levels[i].name)
		{
			(this->*levels[i].function)();
			return ;
		}
	std::cout << "nothing to complain about.\n";
}
