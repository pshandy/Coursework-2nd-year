/*
 * Station.cpp
 *
 *  Created on: May 24, 2022
 *      Author: pshandy
 */

#include "Station.hpp"

Station::Station()
{
	this->head = new Pump();
	this->tail = head;

	this->number = 0;
	this->next = NULL;
	this->prev = NULL;
}

Station::Station(int number)
{
	this->head = new Pump();
	this->tail = head;

	this->number = number;
	this->next = NULL;
	this->prev = NULL;
}

bool	Station::isPumpQueueEmpty()
{
	if (head->getNext() == NULL)
		return (true);
	return (false);
}

bool	Station::isPumpPresent(int number)
{
	Pump *tmp = head->getNext();
	while (tmp != NULL)
	{
		if (tmp->getNumber() == number)
			return (true);
		tmp = tmp->getNext();
	}
	return (false);
}

bool	Station::addPump(int number, std::string brand)
{
	if (!isPumpPresent(number))
	{
		Pump *newPump = new Pump(number, brand);
		tail->setNext(newPump);
		tail = newPump;
		return (true);
	}
	return (false);
}

bool	Station::delPump()
{
	Pump *tmp = head;
	if (!isPumpQueueEmpty())
	{
		if (head->getNext() != NULL)
			head = head->getNext();
		else
			tail = head;
		delete (tmp);
		return (true);
	}
	return (false);
}

void Station::show()
{
	Pump* tmp = head->getNext();
	while (tmp != NULL)
	{

		if (tmp != head->getNext())
			std::cout << "|" << std::setw(16) << "|";

		std::cout << std::setw(13) << tmp->getNumber()
			<< std::setw(8) << " " << std::setw(10) << tmp->getBrand();

		if (tmp->getNext() != NULL)
			std::cout << "\n";

		tmp = tmp->getNext();
	}
}

void	Station::writeToFile(std::ofstream& outfile, int number)
{
	Pump* tmp = head->getNext();
	if (tmp == NULL)
		outfile << number << ";" << std::endl;
	while (tmp != NULL)
	{
		outfile << number << ";"
				<< tmp->getNumber() << ";"
				<< tmp->getBrand() << ";"
				<< std::endl;
		tmp = tmp->getNext();
	}
}

Station::~Station()
{
	Pump *next;
	Pump *current;

	current = head;
	while (current)
	{
		if (current->getNext())
	 		next = current->getNext();
	 	else
	 		next = NULL;
	 	delete (current);
	 	current = next;
	}
}

int			Station::getNumber()
{
	return (number);
}

void		Station::setNumber(int number)
{
	this->number = number;
}

Station*	Station::getNext()
{
	return (next);
}

void		Station::setNext(Station *next)
{
	this->next = next;
}

Station*	Station::getPrev()
{
	return (prev);
}

void		Station::setPrev(Station *prev)
{
	this->prev = prev;
}
