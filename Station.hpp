/*
 * Station.hpp
 *
 *  Created on: May 24, 2022
 *      Author: pshandy
 */

#ifndef STATION_HPP_
#define STATION_HPP_

#include "Program.hpp"
#include "Pump.hpp"

class Station
{

private:

	Pump	*head;
	Pump	*tail;

	int		number;
	Station	*next;
	Station	*prev;

public:

	Station();
	Station(int number);
	virtual ~Station();

	bool	isPumpQueueEmpty();
	bool	isPumpPresent(int number);
	bool	addPump(int number, std::string);
	bool	delPump();
	void	show();

	int		getNumber();
	void	setNumber(int number);

	void	showPump(int number);

	Station	*getNext();
	void	setNext(Station *next);

	Station	*getPrev();
	void	setPrev(Station *prev);

	void	writeToFile(std::ofstream& outfile, int number);

};

#endif /* STATION_HPP_ */
