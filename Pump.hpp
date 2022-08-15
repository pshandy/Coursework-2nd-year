/*
 * Pump.hpp
 *
 *  Created on: May 24, 2022
 *      Author: pshandy
 */

#ifndef PUMP_HPP_
#define PUMP_HPP_

#include "Program.hpp"

class Pump
{

private:

	int			number;
	std::string	brand;
	Pump		*next;

public:

	Pump();
	Pump(int number, std::string brand);

	std::string	getBrand();
	void		setBrand(std::string brand);

	int			getNumber();
	void		setNumber(int number);

	Pump*		getNext();
	void		setNext(Pump* next);

};

#endif /* PUMP_HPP_ */
