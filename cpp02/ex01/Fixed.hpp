#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:

	int _value;
	static const int _bits = 8;

public:

	Fixed(void);
	Fixed(const int element);
	Fixed(const float element);
	Fixed(const Fixed &existing);
	~Fixed(void);

	Fixed& operator = (Fixed const &existing);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

};

std::ostream & operator << (std::ostream &out, const Fixed &existing);


#endif
