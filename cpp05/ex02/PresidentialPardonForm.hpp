#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm(void);

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