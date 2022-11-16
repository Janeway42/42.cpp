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
	~Form(void);

	void beSigned(Bureaucrat &office);

	bool getSigned(void);
	std::string getName(void);

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