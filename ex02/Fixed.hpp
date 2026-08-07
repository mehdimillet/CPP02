#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>


class	Fixed
{
	private:
		int					_fixed_point;
		static const int	_bits = 8;

	public:
		//constructor
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &copy);

		//copy assignement
		Fixed &operator=(const Fixed &other);

		//set and return raw values
        void    setRawBits(int const raw);
        int getRawBits(void) const;
	
		//destructor
		~Fixed();

		//conversion function
		float toFloat()	const;
		int	toInt()	const;

		//comparison operators
		bool operator>(const Fixed &other)	const;
		bool operator<(const Fixed &other)	const;
		bool operator>=(const Fixed &other)	const;
		bool operator<=(const Fixed &other)	const;
		bool operator==(const Fixed &other)	const;
		bool operator!=(const Fixed &other)	const;

		//arithmetic operators
		Fixed operator+(const Fixed &other)	const;
		Fixed operator-(const Fixed &other)	const;
		Fixed operator*(const Fixed &other)	const;
		Fixed operator/(const Fixed &other)	const;

		//pre-increment
		//no params and return a reference
		Fixed &operator++();
		Fixed &operator--();

		//post-increment
		//the (int) is just for tell is a pre-increment but we didn't used it,
		//and we return a copie 
		Fixed operator++(int);
		Fixed operator--(int);

		//static function
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

//overload of the insertion

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif