#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

Form::Form(Form const &existing): _name(existing._name), _signed(existing._signed),
				_signGrade(existing._signGrade), _executeGrade(existing._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

//----------Overload operators-------------------

//-------------Public functions-----------------

void Form::beSigned(Bureaucrat &office)
{
	if (this->_signGrade < office.getGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

void Form::execute(Bureaucrat const &executor)const
{
	if (_signed == false)
		throw FormNotSigned();
	else
        this->runForm(executor.getGrade());
}

//---------Other Public Functions----------------

bool Form::getSigned(void) const
{
	return (this->_signed);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

int Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void Form::copySigned(bool copy)
{
	this->_signed = copy;
}

std::ostream& operator << (std::ostream& out, const Form& existing)
{
	out << "name: " << existing.getName() << ", signed: " << existing.getSigned()
		<< ", signGrade: " << existing.getSignGrade() << ", executeGrade: " << existing.getExecuteGrade();
	return (out);
}