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

        void runForm(int grade)const;
		
};

#endif