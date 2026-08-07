#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(const float val1, const float val2) : x(val1), y (val2)
{

}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{

}

Point	&Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{

}

Fixed	Point::getX()	const
{
	return (x);
}

Fixed	Point::getY()	const
{
	return (y);
}
