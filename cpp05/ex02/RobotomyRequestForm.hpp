#ifndef PROBOTOMYREQUESTFORM_HPP
#define PROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm: public: Form
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm(void);

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