#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//-----------Constructors & Destructors-----------

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
}

// Intern::Intern(const Intern &existing)
// {
// 	std::cout << "Intern copy constructor called" << std::endl;
// }

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

//----------Overload operators-------------------

// Intern& Intern::operator = (const Intern &existing)
// {
// 	std::cout << "Intern copy assign operator called" << std::endl;
// 	return (*this);
// } 

//-------------Public functions-----------------

Form* Intern::makeForm(std::string nameForm, std::string target)
{
	const std::string array[3] = {"shrubbery request", "robotomy request", "presidential request"};

	Form *newForm = NULL;

	if (nameForm.compare(array[0]) == 0)
	{
		std::cout << "Intern creates " << nameForm << std::endl;
		newForm = new ShrubberyCreationForm(target);
	}
	else if (nameForm.compare(array[1]) == 0)
	{
		std::cout << "Intern creates " << nameForm << std::endl;
		newForm = new RobotomyRequestForm(target);
	}
	else if (nameForm.compare(array[2]) == 0)
	{
		std::cout << "Intern creates " << nameForm << std::endl;
		newForm = new PresidentialPardonForm(target);
	}
	else
	{
		std::cout << "Intern creates just a basic form" << std::endl;
	}
	return (newForm);
}