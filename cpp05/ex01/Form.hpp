#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _executeGrade;
	Form& operator = (Form const &existing);

public:
	Form(void);
	Form (std::string name, int grade, int exec);
	Form(Form const &existing);
	~Form(void);

	void beSigned(Bureaucrat &office);

	std::string getName(void)const;
	bool getSigned(void)const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
};

class GradeTooHighException: public std::exception
{
public:

	const char *what() const throw()
	{
		return ("Form grade too high!");
	}
};

class GradeTooLowException: public std::exception
{
public: 

	const char *what() const throw()
	{
		return ("Form grade too low!");
	}
};

std::ostream& operator << (std::ostream& out, const Form& existing);

#endif