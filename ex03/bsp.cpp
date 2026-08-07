# include "Point.hpp"
# include "Fixed.hpp"

Fixed	absolute(Fixed nb)
{
	if (nb < Fixed(0))
		return (Fixed(0) - nb);
	return (nb);
}

Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed area;

	area = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_ABC;
	Fixed	area_PAB;
	Fixed	area_PBC;
	Fixed	area_PAC;
	Fixed	zero(0);

	//for calculate the area of triangle(big and litle)
	area_ABC = area(a, b, c);
	area_PAB = area(point, a, b);
	area_PBC = area(point, b, c);
	area_PAC = area(point, a, c);
	
	// if one area was < 0
	area_ABC = absolute(area_ABC);
	area_PAB = absolute(area_PAB);
	area_PBC = absolute(area_PBC);
	area_PAC = absolute(area_PAC);
	
	// if point is on one top of the triangle
	if (area_PAB == zero || area_PBC == zero || area_PAC == zero)
		return (false);

	// if area is in the area og the triangle
	if (area_ABC == area_PAB + area_PAC + area_PBC)
		return (true);
	return (false);
}