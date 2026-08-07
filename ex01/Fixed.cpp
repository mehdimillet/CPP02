#include "Fixed.hpp"

Fixed::Fixed()
{
    _fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    _fixed_point = value << _bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    _fixed_point = roundf(value * 256);
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    this->_fixed_point = copy._fixed_point;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_fixed_point = other._fixed_point;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void)    const
{
    float   new_value;

    new_value = _fixed_point / 256.0f;
    return (new_value);
}

int Fixed::toInt(void)  const
{
    int new_value;

    new_value = _fixed_point >> _bits;
    return (new_value);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
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