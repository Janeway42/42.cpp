#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &existing);
	~Bureaucrat(void);

	std::string getName(void) const;
	int getGrade(void) const;

	Bureaucrat& operator = (Bureaucrat const &existing);

	Bureaucrat operator++(int); // post-increment
	Bureaucrat& operator++(void); // pre-increment 
	Bureaucrat operator--(int); // post-decrement
	Bureaucrat& operator--(void); // pre-increment 


	class GradeTooHighException: public std::exception
	{
	public:

		const char * what() const throw()
		{
			return ("Grade too high!");
		}
	};

	class GradeTooLowException: public std::exception
	{
	public:

		const char * what() const throw()
		{
			return ("Grade too low!");
		}
	};

};

#endif