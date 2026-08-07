#include "Point.hpp"
#include "Fixed.hpp"

int	main(int ac, char **av)
{
	
	if (ac != 9)
	{
		std::cout << "Invalid number of argument" << std::endl;
		return (1);
	}
	
	Point	a(atof(av[1]), atof(av[2]));
	Point	b(atof(av[3]), atof(av[4]));
	Point	c(atof(av[5]), atof(av[6]));
	Point	p(atof(av[7]), atof(av[8]));

	if (bsp(a, b, c, p))
	{
		std::cout << "The point is inside the triangle" << std::endl;
		return (0);
	}

	std::cout << "The point is outside the triangle" << std::endl;
	return (0);
}