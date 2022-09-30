#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point(void);
        Point(float const a, float const b);
        Point(const Point &existing);
        ~Point(void);

        Point& operator =(Point const &existing);

        Fixed getX(void)const;
        Fixed getY(void)const;

};

// std::ostream & operator << (std::ostream &out, const Fixed &existing)
// {
// 	out << existing.toFloat();
// 	return(out);
// }

#endif