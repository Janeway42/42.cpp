#include "PresidentialPardonForm.hpp"

//-----------Constructors & Destructors-----------

PresidentialPardonForm::PresidentialPardonForm(void): Form("Presidential Form", 25, 5)
{
    std::cout << "PresidentialPardonform default constructor called" << std::endl;
    _target = "no name";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential Form", 25, 5)
{
    std::cout << "PresidentialPardonform with target constructor called" << std::endl;
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &existing):
		Form(existing.getName(), existing.getSignGrade(), existing.getExecuteGrade())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	_target = existing._target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

//----------Overload operators-------------------

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &existing)
{
	std::cout << "PresidentialPardonForm copy assign operator called" << std::endl;
	if (this != &existing)
	{
		_target = existing._target;
		this->copySigned(existing.getSigned());
	}
	return (*this);
} 

//-------------Public functions-----------------

void PresidentialPardonForm::runForm(int grade)const
{
	if (grade > 5)
        throw ExecToolLowException();
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}