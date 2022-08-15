/*
 * Pump.cpp
 *
 *  Created on: May 24, 2022
 *      Author: pshandy
 */

#include "Pump.hpp"

Pump::Pump()
{
	this->number = 0;
	this->brand  = "";
	this->next	 = NULL;
}

Pump::Pump(int number, std::string brand)
{
	this->number = number;
	this->brand  = brand;
	this->next	 = NULL;
}

std::string	Pump::getBrand()
{
	return (brand);
}

void		Pump::setBrand(std::string brand)
{
	this->brand = brand;
}

int			Pump::getNumber()
{
	return (number);
}

void		Pump::setNumber(int number)
{
	this->number = number;
}

Pump*		Pump::getNext()
{
	return (next);
}

void		Pump::setNext(Pump* next)
{
	this->next = next;
}
