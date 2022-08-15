/*
 * Company.hpp
 *
 *  Created on: May 24, 2022
 *      Author: pshandy
 */

#ifndef COMPANY_HPP_
#define COMPANY_HPP_

#include "Program.hpp"
#include "Station.hpp"

class Company
{

private:

	std::string name;
	Station		*head;

public:

	Company();
	Company(std::string name);
	virtual ~Company();

	bool	isLinkedListEmpty();

	bool	isStationPresent(int number);
	bool	_isStationPresent(int number);

	bool	isPumpInStationPresent(int stationNumber, int number);
	bool	_isPumpInStationPresent(int stationNumber, int number);

	bool	addStation(int number);
	bool	_addStation(int number);

	bool	delStation(int number);
	bool	_delStation(int number);

	bool	addPump(int stationNumber, int pumpNumber, std::string brand);
	bool	_addPump(int stationNumber, int pumpNumber, std::string brand);

	bool	delPump(int stationNumber);
	bool	_delPump(int stationNumber);

	void	showStation(int stationNumber);
	void	showPump(int stationNumber, int pumpNumber);

	void	show();
	void	_show();

	void	writeToFile(std::ofstream& outfile);

	std::string	getName();
	void		setName(std::string name);

};

#endif /* COMPANY_HPP_ */
