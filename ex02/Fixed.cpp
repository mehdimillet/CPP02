#include "Fixed.hpp"

//constructor

Fixed::Fixed()
{
	_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	_fixed_point =  value << _bits;
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


//copy assignement

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixed_point = other._fixed_point;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}


///set and return raw values

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


// conversion function

float	Fixed::toFloat()	const
{
	float   new_value;

	new_value = _fixed_point / 256.0f;
	return (new_value);
}

int	Fixed::toInt()	const
{
	int new_value;

	new_value = _fixed_point >> _bits;
	return (new_value);
}


// comparaison operators

bool	Fixed::operator<(const Fixed &other)	const
{
	if (this->_fixed_point < other._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &other)	const
{
	if (this->_fixed_point > other._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &other)	const
{
	if (this-> _fixed_point <= other._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &other)	const
{
	if (this->_fixed_point >= other._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &other)	const
{
	if (this->_fixed_point == other._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &other)	const
{
	if (this->_fixed_point != other._fixed_point)
		return (true);
	return (false);
}


// arithmetic operators

Fixed	Fixed::operator+(const Fixed &other)	const
{
	Fixed	new_value;

	new_value.setRawBits(this->_fixed_point + other._fixed_point);
	return (new_value);
}

Fixed	Fixed::operator-(const Fixed &other)	const
{
	Fixed	new_value;

	new_value.setRawBits(this->_fixed_point - other._fixed_point);
	return (new_value);
}

Fixed	Fixed::operator*(const Fixed &other)	const
{
	Fixed	new_value;

	new_value.setRawBits((this->_fixed_point * other._fixed_point) >> _bits);
	return (new_value);
}

Fixed	Fixed::operator/(const Fixed &other)	const
{
	Fixed	new_value;

	new_value.setRawBits((this->_fixed_point / other._fixed_point) << _bits);
	return (new_value);
}


//pre-increment

Fixed	&Fixed::operator++()
{
	++this->_fixed_point;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	--this->_fixed_point;
	return (*this);
}


//post-increment

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++this->_fixed_point;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--this->_fixed_point;
	return (temp);
}


//static function

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
 	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a,  const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}


//overload of the insertion

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}


//destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}