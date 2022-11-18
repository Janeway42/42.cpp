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
		PresidentialPardonForm(const PresidentialPardonForm &existing);
        ~PresidentialPardonForm(void);

		PresidentialPardonForm& operator =(const PresidentialPardonForm &existing);

        void runForm(void)const;
};

#endif