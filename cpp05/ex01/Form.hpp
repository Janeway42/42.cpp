#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _executeGrade;


public:
	Form(void);
	Form (std::string name, int grade, int exec);
	Form(Form const &existing);
	~Form(void);

	Form& operator = (Form const &existing);

	void beSigned(Bureaucrat &office);

	bool getSigned(void)const;
	std::string getName(void)const;
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


#endif