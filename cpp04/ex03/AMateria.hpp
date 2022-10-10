#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
protected:
	std::string type;

public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &existing);
	~AMateria(void);

	AMateria& operator = (AMateria const &existing);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif