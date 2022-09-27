#include "PresidentialPardonForm.hpp"

//-----------Constructors & Destructors-----------

PresidentialPardonForm::PresidentialPardonForm(void): Form("Fancy Form", 150, 150)  // should it be 25, 5?
{
    std::cout << "PresidentialPardonform default constructor called" << std::endl;
    _target = "no name";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Fancy Form", 25, 5)
{
    std::cout << "PresidentialPardonform target constructor called" << std::endl;
    _target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

//----------Overload operators-------------------

//-------------Public functions-----------------

void PresidentialPardonForm::beSigned(Bureaucrat &office)
{
    try
    {
        if (office.getGrade() > 25)
            throw GradeTooLowException();
        else
            this->beSigned(office);
    }
    catch(const GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
    try
    {
        if (this->getSigned() == false)
            throw FormNotSigned();
        else
        {
            try
            {
                if (executor.getGrade() > 5)
                    throw ExecTooLowException();
                // else if (executor.getGrade() < 1)
                // throw ExecTooHighException();
                else
                    this->runForm();
            }
            catch(const ExecTooLowException &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
    catch(const FormNotSigned &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void PresidentialPardonForm::runForm(void)const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}