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

Bureaucrat::Bureaucrat(const Bureaucrat &existing): _name(existing.getName()), _grade(existing.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//----------Overload operators-------------------

//-------------Public functions-----------------

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

//-----------Increment/Decrement Operators-------------

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}


void Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

//-------------Other Public functions-----------------

std::ostream& operator << (std::ostream &out, const Bureaucrat &existing)
{
	out << existing.getName() << ", bureaucrat grade " << existing.getGrade();
	return (out);
}
