#include "ShrubberyCreationForm.hpp"
#include <fstream>

//-----------Constructors & Destructors-----------

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("Fancy Form", 150, 150)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
    _target = "no name";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Fancy Form", 145, 137)
{
    std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
    _target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

//----------Overload operators-------------------

//-------------Public functions-----------------

void ShrubberyCreationForm::beSigned(Bureaucrat &office)
{
    try
    {
        if (office.getGrade() > 145)
            throw GradeTooLowException();
        else
            this->beSigned(office);
    }
    catch(const GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
    try
    {
        if (this->getSigned() == false)
            throw FormNotSigned();
        else
        {
            try
            {
                if (executor.getGrade() > 137)
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

void ShrubberyCreationForm::runForm(void)const
{
    std::ofstream new_file;
    // std::ifstream fs_new;

    new_file.open(this->_target + "_shrubbery", std::ios::out | std::ios::trunc);
    // fs_new.open(thsi->_target + "_shrubbery", std::ios::in | std::ios::out | std::ios::app);

    if (new_file)
    {
        new_file << "      ,d "; 
        std::cout << std::endl;                                
        new_file << "  88";
        std::cout << std::endl;                                
        new_file << "MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba, ";
        std::cout << std::endl;                                
        new_file << "  88    88P'   \"Y8 a8P_____88 a8P_____88  ";
        std::cout << std::endl;                                
        new_file << "  88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"";  
        std::cout << std::endl;                                
        new_file << "  88,   88         \"8b,   ,aa \"8b,   ,aa  ";
        std::cout << std::endl;                                
        new_file << "  \"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"\'";  
        new_file.close();
    }
    else
        std::cout << "Error creating file" << std::endl;
}