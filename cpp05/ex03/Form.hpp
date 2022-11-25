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
	Form& operator = (Form const &existing);


public:
	Form(void);
	Form (std::string name, int grade, int exec);
	Form(Form const &existing);
	virtual ~Form(void);

	void beSigned(Bureaucrat &office);
	void execute(Bureaucrat const &executor)const;
	virtual void runForm(int grade)const = 0;

	bool getSigned(void)const;
	void copySigned(bool copy);
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

class ExecToolLowException: public std::exception
{
    public:
        const char *what() const throw()
        {
            return ("Exception grade too low!");
        }
};

class FormNotSigned: public std::exception
{
public: 

	const char *what() const throw()
	{
		return ("Form not signed!");
	}
};


#endif