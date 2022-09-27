#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm: public: Form
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm(void);

        void execute(Bureaucrat const &executor)const;
        void runForm(void)const;

        void beSigned(Bureaucrat &office);

        class ExecToolLowException: public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Eception grade too low!");
                }
        };
};

#endif