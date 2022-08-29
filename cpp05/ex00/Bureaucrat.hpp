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
	~Bureaucrat(void);

	std::string getName(void);
	int getGrade(void);

	Bureaucrat& operator = (Bureaucrat const &existing);

	void incrementGrade(void);
	void decrementGrade(void);

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