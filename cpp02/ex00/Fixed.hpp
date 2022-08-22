#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:

	int _value;
	static const int _bits = 8;

public:

	Fixed(void);
	Fixed(const Fixed &existing);
	~Fixed(void);
	Fixed& operator = (Fixed const &existing);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

};


#endif