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

Intern::Intern(const Intern &existing)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)existing;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

//----------Overload operators-------------------

Intern& Intern::operator = (const Intern &existing)
{
	std::cout << "Intern copy assign operator called" << std::endl;
	(void)existing;
	return (*this);
} 

//-------------Public functions-----------------

int Intern::getType(std::string nameForm)
{
	int type = 4;

	std::string formType[] = {"form request", "shrubbery request", "robotomy request", "presidential request"};

	for (int i = 0; i < 4; i++)
	{
		if (nameForm.compare(formType[i]) == 0)
			type = i;
	}
	return (type + 1);
}

Form* Intern::makeForm(std::string nameForm, std::string target)
{
	Form *newForm = NULL;

	switch (Intern::getType(nameForm))
	{
		case 1:
			newForm = makeDefault(newForm);
			break;
		case 2:
			newForm = makeShrubbery(newForm, nameForm, target);
			break;
		case 3:
			newForm = makeRobotomy(newForm, nameForm, target);
			break;
		case 4:
			newForm = makePresidential(newForm, nameForm, target);
			break;
		default:
			std::cout << "Intern has no idea what you want from it!" << std::endl;			
	}
	return (newForm);
}

Form* Intern::makeShrubbery(Form* newForm, std::string nameForm, std::string target)
{	
	std::cout << "Intern creates " << nameForm << std::endl;
	newForm = new ShrubberyCreationForm(target);
	return (newForm);
}

Form* Intern::makeRobotomy(Form* newForm, std::string nameForm, std::string target)
{
	std::cout << "Intern creates " << nameForm << std::endl;
	newForm  = new RobotomyRequestForm(target);
	return (newForm);
}

Form* Intern::makePresidential(Form* newForm, std::string nameForm, std::string target)
{
	std::cout << "Intern creates " << nameForm << std::endl;
	newForm  = new PresidentialPardonForm(target);
	return (newForm);
}

Form* Intern::makeDefault(Form* newForm)
{
	std::cout << "Intern creates just a basic form" << std::endl;
	newForm = NULL;
	return (newForm);
}
