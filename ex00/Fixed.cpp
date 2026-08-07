#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	this->_fixed_point = copy._fixed_point;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(const Fixed &other)
{
	if (this != &other) 
		this->_fixed_point = other._fixed_point;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point = raw;
	std::cout << "SetRawBits member function called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point);
}