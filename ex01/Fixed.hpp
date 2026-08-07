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
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		float toFloat() const;
		int	toInt() const;
        void    setRawBits(int const raw);
        int getRawBits(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif