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
		int _signGrade;
		int _execGrade;

	public:
		Form(void);
		Form (std::string name, int grade);
		virtual ~Form(void);

		Form& operator = (const Form &copy);

		void beSigned(Bureaucrat &office);

		bool getSigned(void);
		std::string getName(void);
		int getGrade(void);

		virtual void execute(Bureaucrat const &executor)const = 0;
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

class FormNotSigned: public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Form not signed");
		}
};


#endif