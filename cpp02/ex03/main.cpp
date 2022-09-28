#include <iostream>
#include <string.h>
#include "Fixed.hpp"

int main (void)
{
	Fixed a;
	std::cout << std::endl;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << std::endl;


	Fixed c(24);
	Fixed d(13);
	std::cout << std::endl;

    std::cout << "----------A Tests:-----------\n" << std::endl;
	std::cout << a << std::endl;
    std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;

    std::cout << a << " pre-increment " << ++a << std::endl;
    std::cout << a++ << " post-increment " << a << std::endl;
	std::cout << std::endl;
    std::cout << a << " pre-increment " << --a << std::endl;
    std::cout << a-- << " post-increment " << a << std::endl;

    std::cout << "----------B Tests:-----------\n" << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

    std::cout << "----------Comparation Operators:-------\n" << std::endl;
    std::cout << (b >= a) << std::endl;
	std::cout << std::endl;
    std::cout << (b == d) << std::endl;
    std::cout << std::endl;

    std::cout << "---------Min/max Tests:-------\n" << std::endl;
    
	std::cout << "min: \n" << Fixed::min(c, d) << std::endl;
	std::cout << std::endl;

	std::cout << "max: \n" << Fixed::max(a, c) << std::endl;
	std::cout << std::endl;

    std::cout << "max: \n" << Fixed::max(a, b) << std::endl;
	std::cout << "----------End tests------------\n" << std::endl;

	return (0);
}
