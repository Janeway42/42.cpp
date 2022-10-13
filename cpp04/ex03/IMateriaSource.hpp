#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
    private:

    public:
        virtual ~IMateriaSource(){}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;

        virtual int getIndex(void)const = 0;  /// ??
        virtual AMateria* getLearnedMateria(int location)const = 0;

};

#endif