#include <iostream>
#include <string.h>
#include "Fixed.hpp"

int main (void)
{
	Fixed const a(1234);
	Fixed const b(5);

	Fixed c(24);
	Fixed d(13);
	// Fixed const c(42.42f);
	// Fixed const d(b);

	// a = Fixed(1234);
	// a = Fixed(1234);


	std::cout << "my tests:\n" << std::endl;
	std::cout << a << std::endl;
	// std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << std::endl;
	std::cout << Fixed::max(a, c) << std::endl;
	std::cout << "End my tests\n" << std::endl;



	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;
	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}

// Fixed a;
// Fixed const b(Fixed(5.05f) * Fixed(2));

// std::cout << a << std::endl;
// std::cout << ++a <<std::endl;
// std::cout << a <<std::endl;
// std::cout a++ << std::endl;
// std::cout << a << std::endl;

// std::cout << b<< std::endl;

// std::cout << Fixed::max(a, b) << std::endl;