#include "Bureaucrat.hpp"
#include "Form.hpp"

//-----------Constructors & Destructors-----------

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor " << this->_name << " with grade " << grade << " called" << std::endl;

	try
	{
		if (grade < 1)
		{
			this->_grade = 1;
			throw GradeTooHighException();
		}
		else if (grade > 150)
		{
			this->_grade = 150;
			throw GradeTooLowException();
		}
		else
		{
			this->_grade = grade;
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

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//----------Overload operators-------------------

//-------------Public functions-----------------

void Bureaucrat::signForm(Form paper)
{
	if (paper.getSigned() == true)
		std::cout << this->_name << "signed" << paper.getName() << std::endl;
	else
		std::cout << this->_name << "couldn't sign" << paper.getName() << "because he ran out of toothpicks." << std::endl;
}

std::string Bureaucrat::getName(void)
{
	return (this->_name);
}

int Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

//-----------Increment/Decrement Operators-------------

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw GradeTooHighException();
		else
			this->_grade += 1;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw GradeTooLowException();
		else
			this->_grade -= 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
