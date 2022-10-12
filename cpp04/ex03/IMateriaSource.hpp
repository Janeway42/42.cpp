#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
    private:

    public:
        IMateriaSource(void);
        virtual ~IMateriaSource(void);

        virtual int getIndex(void)const;
        virtual AMateria* getLearnedMateria(int location)const;

        virtual void learnMateria(AMateria*) = 0;
};

#endif