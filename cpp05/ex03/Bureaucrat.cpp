#include "Bureaucrat.hpp"

//-----------Constructors & Destructors-----------

Bureaucrat::Bureaucrat(void): _name("no name")
{
	this->_grade = 150;
	std::cout << "Bureaucrat constructor " << this->_name << " with grade " << this->_grade << " created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		this->_grade = grade;
		std::cout << "Bureaucrat constructor " << this->_name << " with grade " << this->_grade << " created" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &existing): _name(existing._name), _grade(existing._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//----------Overload operators-------------------

// this->_name is a constant and normally can not be changed. 
// another option is to change the information at the address of the pointer. 
// this is a concious method of bypassing the compiler const rule. 
//		std::string *temp;
//		temp = (std::string *)&this->_name;
//		*temp = existing.getName();

Bureaucrat& Bureaucrat::operator =(Bureaucrat const &existing)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &existing)
		this->_grade = existing.getGrade();
	return (*this);
}

//-------------Public functions-----------------

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::signForm(Form &paper)
{
	paper.beSigned(*this);
	if (paper.getSigned() == true)
		std::cout << this->_name << " signed " << paper.getName() << std::endl;
	else
		std::cout << this->_name << "couldn't sign " << paper.getName() << " because he ran out of toothpicks." << std::endl;
}

//-----------Increment/Decrement Operators-------------

void Bureaucrat::incrementGrade(void) // pre-increment // increments the value before using it further
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void Bureaucrat::decrementGrade(void) // pre-decrement // increments the value before using it further
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}