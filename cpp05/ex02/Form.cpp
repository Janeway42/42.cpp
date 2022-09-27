#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

//-----------Constructors & Destructors-----------

Form::Form(void): _name("no name")
{
	std::cout << "Form default constructor called" << std::endl;
	this->_signed = false;
	this->_grade = 150;   // ????
}

Form::Form(std::string name, int grade): _name(name)
{
	std::cout << "Form constructor with name called" << std::endl;
	this->_signed = false;
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch(const GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
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
	try
	{
		if (office.getGrade() > this->_grade)
			throw GradeTooLowException();
		else
			this->_signed = true;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

bool Form::getSigned(void)
{
	return (this->_signed);
}

std::string Form::getName(void)
{
	return (this->_name);
}

int Form::getGrade(void)
{
	return (this->_signGrade);
}