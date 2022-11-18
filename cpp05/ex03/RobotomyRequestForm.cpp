#include "RobotomyRequestForm.hpp"

//-----------Constructors & Destructors-----------

RobotomyRequestForm::RobotomyRequestForm(void): Form("Robbotomy Form", 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
    _target = "no name";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robbotomy Form", 72, 45)
{
    std::cout << "RobotomyRequestForm target constructor called" << std::endl;
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &existing): 
		Form(existing.getName(), existing.getSignGrade(), existing.getExecuteGrade())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	_target = existing._target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

//----------Overload operators-------------------

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &existing)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &existing)
	{
		_target = existing._target;
		this->copySigned(existing.getSigned());
	}
	return (*this);
}

//-------------Public functions-----------------

void RobotomyRequestForm::runForm(void)const
{
    std::cout << "making drilling noises" << std::endl;

    srand(time(0));
    int x = rand();

    if (x % 2 == 0)
        std::cout << this->_target << " has been robotomised succesfully!" << std::endl;
    else
        std::cout << this->_target << " robotomy has failed!" << std::endl;
}