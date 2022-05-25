/*
 * Company.cpp
 *
 *  Created on: May 24, 2022
 *      Author: pshandy
 */

#include "Company.hpp"

Company::Company()
{

	head = new Station();
	head->setNext(head);
	head->setPrev(head);

	name = "";

}

Company::Company(std::string name)
{

	head = new Station();
	head->setNext(head);
	head->setPrev(head);

	this->name = name;
}

Company::~Company()
{
	Station *tmp;
	Station *next;

	next = head->getNext();
	while (next != head)
	{
		tmp = next;
		next = next->getNext();
		delete (tmp);
	}
	delete (head);
}


bool	Company::isLinkedListEmpty()
{
	if (head->getNext() == head && head->getPrev() == head)
		return (true);
	return (false);
}

bool	Company::isStationPresent(int number)
{
	Station *tmp = head->getNext();
	while (tmp != head)
	{
		if (tmp->getNumber() == number)
			return (true);
		tmp = tmp->getNext();
	}
	return (false);
}

bool	Company::isPumpInStationPresent(int stationNumber, int number)
{
	Station *tmp = head->getNext();
	while (tmp != head)
	{
		if (tmp->getNumber() == stationNumber)
			if (tmp->isPumpPresent(number))
				return (true);
		tmp = tmp->getNext();
	}
	return (false);
}

bool	Company::addStation(int number)
{

	Station *tmp = head->getNext();
	Station *newStation = new Station(number);

	while (tmp != head)
	{

		if (tmp->getNumber() == number)
		{
			delete (newStation);
			return (false);
		}

		if (tmp->getNumber() > number)
		{
			newStation->setNext(tmp);
			newStation->setPrev(tmp->getPrev());
			tmp->getPrev()->setNext(newStation);
			tmp->setPrev(newStation);
			return (true);
		}
		tmp = tmp->getNext();

	}

	newStation->setNext(head);
	newStation->setPrev(head->getPrev());
	head->getPrev()->setNext(newStation);
	head->setPrev(newStation);
	return (true);
}

bool	Company::delStation(int number)
{
	if (isStationPresent(number))
	{
		Station *tmp = head->getNext();
		while (tmp != head)
		{
			if (tmp->getNumber() == number)
			{
				tmp->getPrev()->setNext(tmp->getNext());
				tmp->getNext()->setPrev(tmp->getPrev());
				delete (tmp);
				return (true);
			}
			tmp = tmp->getNext();
		}
	}
	return (false);
}

bool	Company::addPump(int stationNumber, int pumpNumber, std::string brand)
{
	if (isStationPresent(stationNumber))
	{
		Station *tmp = head->getNext();
		while (tmp != head)
		{
			if (tmp->getNumber() == stationNumber)
				return (tmp->addPump(pumpNumber, brand));
			tmp = tmp->getNext();
		}
	}
	return (false);
}

bool	Company::delPump(int stationNumber)
{
	if (isStationPresent(stationNumber))
	{
		Station *tmp = head->getNext();
		while (tmp != head)
		{
			if (tmp->getNumber() == stationNumber)
			{
				if (!tmp->delPump())
					return (false);
				return (true);
			}
			tmp = tmp->getNext();
		}
	}
	return (false);
}

void Company::show()
{
	if (!isLinkedListEmpty()) {
		Station* tmp = head->getNext();
		while (tmp != head)
		{
			std::cout << "----------------------------------------------------\n";
			std::cout << "|" << std::setw(8) << tmp->getNumber() << std::setw(8) << "|";
			tmp->show();
			std::cout << "\n";
			tmp = tmp->getNext();
		}
	}
}

void Company::_show()
{
	if (!isLinkedListEmpty()) {
		Station* tmp = head->getPrev();
		while (tmp != head)
		{
			std::cout << "----------------------------------------------------\n";
			std::cout << "|" << std::setw(8) << tmp->getNumber() << std::setw(8) << "|";
			tmp->show();
			std::cout << "\n";
			tmp = tmp->getPrev();
		}
	}
}

bool	Company::_isStationPresent(int number)
{
	Station *tmp = head->getPrev();
	while (tmp != head)
	{
		if (tmp->getNumber() == number)
			return (true);
		tmp = tmp->getPrev();
	}
	return (false);
}

bool	Company::_isPumpInStationPresent(int stationNumber, int number)
{
	Station *tmp = head->getPrev();
	while (tmp != head)
	{
		if (tmp->getNumber() == stationNumber)
			if (tmp->isPumpPresent(number))
				return (true);
		tmp = tmp->getPrev();
	}
	return (false);
}

bool	Company::_addStation(int number)
{

	Station *tmp = head->getPrev();
	Station *newStation = new Station(number);

	while (tmp != head)
	{
		if (tmp->getNumber() == number)
		{
			delete (newStation);
			return (false);
		}
		if (tmp->getNumber() < number)
		{
			newStation->setPrev(tmp);
			newStation->setNext(tmp->getNext());
			tmp->getNext()->setPrev(newStation);
			tmp->setNext(newStation);
			return (true);
		}
		tmp = tmp->getPrev();

	}
	newStation->setNext(head->getNext());
	newStation->setPrev(head);
	head->getNext()->setPrev(newStation);
	head->setNext(newStation);
	return (true);
}

bool	Company::_delStation(int number)
{
	if (isStationPresent(number))
	{
		Station *tmp = head->getPrev();
		while (tmp != head)
		{
			if (tmp->getNumber() == number)
			{
				tmp->getPrev()->setNext(tmp->getNext());
				tmp->getNext()->setPrev(tmp->getPrev());
				delete (tmp);
				return (true);
			}
			tmp = tmp->getPrev();
		}
	}
	return (false);
}

bool	Company::_addPump(int stationNumber, int pumpNumber, std::string brand)
{
	if (_isStationPresent(stationNumber))
	{
		Station *tmp = head->getPrev();
		while (tmp != head)
		{
			if (tmp->getNumber() == stationNumber)
				return (tmp->addPump(pumpNumber, brand));
			tmp = tmp->getPrev();
		}
	}
	return (false);
}

bool	Company::_delPump(int stationNumber)
{
	if (_isStationPresent(stationNumber))
	{
		Station *tmp = head->getPrev();
		while (tmp != head)
		{
			if (tmp->getNumber() == stationNumber)
			{
				if (!tmp->delPump())
					return (false);
				return (true);
			}
			tmp = tmp->getPrev();
		}
	}
	return (false);
}

std::string	Company::getName()
{
	return (name);
}

void		Company::setName(std::string name)
{
	this->name = name;
}
