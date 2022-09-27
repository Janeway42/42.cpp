#include "RobotomyRequestForm.hpp"

//-----------Constructors & Destructors-----------

RobotomyRequestForm::RobotomyRequestForm(void): Form("Fancy Form", 150, 150)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
    _target = "no name";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Fancy Form", 72, 45)
{
    std::cout << "RobotomyRequestForm target constructor called" << std::endl;
    _target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

//----------Overload operators-------------------

//-------------Public functions-----------------

void RobotomyRequestForm::beSigned(Bureaucrat &office)
{
    try
    {
        if (office.getGrade() > 72)
            throw GradeTooLowException();
        else
            this->beSigned(office);
    }
    catch(const GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
    try
    {
        if (this->getSigned() == false)
            throw FormNotSigned();
        else
        {
            try
            {
                if (executor.getGrade() > 45)
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

void RobotomyRequestForm::runForm(void)const
{
    std::cout << "drilling noises" << std::endl;

    srand(time(0));
    int x = rand();

    if (x % 2 == 0)
        std::cout << this->_target << " has been robotomised succesfully!" << std::endl;
    else
        std::cout << this->_target << " robotomy has failed!" << std::endl;
}