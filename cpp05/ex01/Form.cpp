#include "Form.hpp"

//-----------Constructors & Destructors-----------

Form::Form(void): _name("no name"), _signGrade(150), _executeGrade(150)
{
	this->_signed = false;
	std::cout << "Form default constructor created" << std::endl;
}

Form::Form(std::string name, int grade, int exec): _name(name), _signGrade(grade), _executeGrade(exec)
{
	if (grade < 1 || exec < 1)
		throw GradeTooHighException();
	else if (grade > 150 || exec > 150)
		throw GradeTooLowException();
	else
	{
		this->_signed = false;
		std::cout << "Form constructor " << this->_name << " with sign grade " << this->_signGrade << " and execute grade " << this->_executeGrade << " created" << std::endl;
	}
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

//----------Overload operators-------------------

//-------------Public functions-----------------

void Form::beSigned(Bureaucrat &office)
{
	if (office.getGrade() < this->_signGrade)
		throw GradeTooLowException();
	else
		this->_signed = true;
}

bool Form::getSigned(void)
{
	return (this->_signed);
}

std::string Form::getName(void)
{
	return (this->_name);
}