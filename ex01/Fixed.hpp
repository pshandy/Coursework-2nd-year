/*
 * Fixed.hpp
 *
 *  Created on: Jun 15, 2022
 *      Author: pshandy
 */

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>

class Fixed {
private:
	int	value;
	static const int bits = 8;
public:

	Fixed();
	Fixed(const Fixed &fixed);
	virtual ~Fixed();
	Fixed &operator = (const Fixed &fixed);

	Fixed(const int nbr);
	Fixed(const float nbr);

	float toFloat(void) const;
	int toInt(void) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);


};


#endif
