#include "MateriaSource.hpp"

//-----------Constructors & Destructors----------

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_learnedMateria[i] = NULL;
    this->_indexLearned = 0;
}

MateriaSource::MateriaSource(const MateriaSource &existing)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_learnedMateria[i] = NULL;
        if (existing._learnedMateria[i] != NULL)
            this->_learnedMateria[i] = existing._learnedMateria[i];
        else
            this->_learnedMateria[i] = NULL;
    }
    this->_indexLearned = 0;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete(this->_learnedMateria[i]);
}

//----------------- Operators--------------------

MateriaSource& MateriaSource::operator = (MateriaSource const &existing)
{
    std::cout << "MateriaSource copy constructor assignment called" << std::endl;
    if (this != &existing)
    {
        for (int i = 0; i < 4; i++)
        {
            delete(this->_learnedMateria[i]);
            this->_learnedMateria[i] = NULL;
            this->_learnedMateria[i] = existing.getLearnedMateria(i);
        }
        this->_indexLearned = existing.getIndex();
    }
    return (*this);
}

//-------------Get Public Functions------------------

int MateriaSource::getIndex(void)const
{
    return (this->_indexLearned);
}

AMateria* MateriaSource::getLearnedMateria(int location)const
{
    return (this->_learnedMateria[location]);
}

//-------------Other Public Functions------------------

void MateriaSource::learnMateria(AMateria* m)
{
    if (m && this->_indexLearned < 4)
    {
        this->_learnedMateria[_indexLearned] = m;
        this->_indexLearned++;
    }
    else if (this->_indexLearned == 4)
    {
        std::cout << "Can't learn new materia. Memory full." << std::endl;
        delete(m);
    }
}

AMateria* MateriaSource::createMateria(std::string const &learned)
{
    if (this->_indexLearned > 0)
    {
        for (int i = 0; i < this->_indexLearned; i++)
        {
            if (this->getLearnedMateria(i)->getType().compare(learned) == 0)
                return (this->getLearnedMateria(i)->clone());
        }
        std::cout << "MateriaSource createMateria: Invalid materia type. Try again!" << std::endl;
    }
    else
        std::cout << "MateriaSource createMateria: No learned materias. Come back later!" << std::endl;
    return (0);
}