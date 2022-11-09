#include "Bureaucrat.hpp"

//-----------Constructors & Destructors-----------

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	try
	{
		if (grade < 1)
		{
			// this->_grade = 1;
			std::cout << "grade: " << this->_grade << std::endl; 
			throw GradeTooHighException();
		}
		else if (grade > 150)
		{
			// this->_grade = 150;
			std::cout << "grade: " << this->_grade << std::endl; 
			throw GradeTooLowException();
		}
		else
		{
			this->_grade = grade;
			std::cout << "Bureaucrat constructor " << this->_name << " with grade " << this->_grade << " created" << std::endl;
		}
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &existing)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = existing;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//----------Overload operators-------------------

// this->_name is a constant and normally can not be changed. 
// another option is to change the information at the address of the pointer. 
// this is a concious method of bypassing the compiler const rule. 

Bureaucrat& Bureaucrat::operator =(Bureaucrat const &existing)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &existing)
	{
		std::string *temp;
		temp = (std::string *)&this->_name;
		*temp = existing.getName();
		this->_grade = existing.getGrade();
	}
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

//-----------Increment/Decrement Operators-------------

Bureaucrat Bureaucrat::operator++(int) // post-increment // increments the value after the action
{
	Bureaucrat temp;

	temp = *this;
	try
	{
		if (this->_grade < 1 || this->_grade - 1 < 1)
			throw GradeTooHighException();
		else
			this->_grade += 1;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (temp);
}

Bureaucrat& Bureaucrat::operator++(void) // pre-increment // increments the value before using it further
{
	try
	{
		if (this->_grade < 1 || this->_grade - 1 < 1)
			throw GradeTooHighException();
		else
			this->_grade += 1;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int) // post-decrement
{
	Bureaucrat temp;

	temp = *this;
	try
	{
		if (this->_grade > 150 || this->_grade + 1 > 150)
			throw GradeTooLowException();
		else
			this->_grade -= 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (temp);
}

Bureaucrat& Bureaucrat::operator--(void) // pre-decrement // increments the value before using it further
{
	try
	{
		if (this->_grade > 150 || this->_grade + 1 > 150)
			throw GradeTooLowException();
		else
			this->_grade -= 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (*this);
}
