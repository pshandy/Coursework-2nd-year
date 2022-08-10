/*
 * Fixed.cpp
 *
 *  Created on: Jun 15, 2022
 *      Author: pshandy
 */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called!" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called!" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	std::cout << "Assignation operator called." << std::endl;
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
