#ifndef PROBOTOMYREQUESTFORM_HPP
#define PROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &existing);
        ~RobotomyRequestForm(void);

		RobotomyRequestForm& operator = (const RobotomyRequestForm &existing);

        void runForm(int grade)const;
};

#endif