#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &existing);
        ~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator = (const ShrubberyCreationForm &existing);

        void runForm(void)const;

		// class GradeTooHighException: public std::exception
		// {
		// 	public:

		// 	const char *what() const throw()
		// 	{
		// 		return ("Form grade too high!");
		// 	}
		// };

		// class GradeTooLowException: public std::exception
		// {
		// 	public: 

		// 	const char *what() const throw()
		// 	{
		// 		return ("Form grade too low!");
		// 	}
		// };
		
};

#endif