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

//---------------Comparation Operators--------------------

	bool operator < (const Fixed &existing) const;
	bool operator > (const Fixed &existing) const;
	bool operator <= (const Fixed &existing) const;
	bool operator >= (const Fixed &existing) const;
	bool operator == (const Fixed &existing) const;
	bool operator != (const Fixed &existing) const;

//---------------Artimetic Operators----------------------

	Fixed operator + (const Fixed &existing) const;
	Fixed operator - (const Fixed &existing) const;
	Fixed operator * (const Fixed &existing) const;
	Fixed operator / (const Fixed &existing) const;

//-----------Increment/Decrement Operators-------------

	Fixed& operator ++(void);	//pre-increment
	Fixed operator ++(int); 	//post-increment
	Fixed& operator --(void);	//pre-increment
	Fixed operator --(int);		//post-increment

//----------------Public Functions---------------------

	static Fixed &min(Fixed &one, Fixed &two);
	static const Fixed &min(const Fixed &one, const Fixed &two);

	static Fixed &max(Fixed &one, Fixed &two);
	static const Fixed &max(const Fixed &one, const Fixed &two);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream & operator << (std::ostream &out, const Fixed &existing);

#endif
