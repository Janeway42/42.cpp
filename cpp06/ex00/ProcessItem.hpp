#ifndef PROCESSITEM_HPP
#define PROCESSITEM_HPP

# include <iostream>
# include <string>
# include <ctype.h>
# include <cmath>
# include <iomanip>

// #define std::string specialNAN[] = {"nan", "nanf"}
// #define std::string specialINF[] = {"inf, inff, -inf, +inf, -inff, +inff"}

int processInput(std::string str);
int processChar(char c);
int processFloat(std::string str);
int processInt(std::string str);
int processDouble(std::string str);

class ConversionNotPossible: public std::exception
{
public:

	const char *what() const throw()
	{
		return ("Conversion not possible");
	}
};

#endif