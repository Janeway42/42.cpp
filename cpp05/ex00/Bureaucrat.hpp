#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;  // lowest 150 - highest 1
	Bureaucrat& operator = (Bureaucrat const &existing);

public:

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &existing);
	~Bureaucrat(void);

	std::string getName(void) const;
	int getGrade(void) const;
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

std::ostream& operator << (std::ostream &out, const Bureaucrat &existing);

#endif