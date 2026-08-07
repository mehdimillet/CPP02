#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const y;

		public:
		Point();
		Point(const float val1, const float val2);
		Point(const Point &copy);
		Point	&operator=(const Point &other);
		~Point();
		
		// getters
		Fixed getX()	const;
		Fixed getY()	const;
	};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif