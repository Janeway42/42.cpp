#include "ShrubberyCreationForm.hpp"
#include <fstream>

//-----------Constructors & Destructors-----------

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShruberyForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
    _target = "no name";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShruberyForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &existing): 
		Form(existing.getName(), existing.getSignGrade(), existing.getSignGrade())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	_target = existing._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

//----------Overload operators-------------------

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &existing)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &existing)
	{
		_target = existing._target;
		this->copySigned(existing.getSigned());
	}
	return (*this);
}

//-------------Public functions-----------------

void ShrubberyCreationForm::runForm(void)const
{
    std::ofstream new_file;
    // std::ifstream fs_new;

    new_file.open(this->_target + "_shrubbery", std::ios::out | std::ios::trunc);
    // fs_new.open(thsi->_target + "_shrubbery", std::ios::in | std::ios::out | std::ios::app);

    if (new_file)
    {
        new_file << "  ,d\n"; 
        new_file << "  88\n";                     
        new_file << "MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba, \n";                             
        new_file << "  88    88P'   \"Y8 a8P_____88 a8P_____88  \n";                          
        new_file << "  88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"\n";                               
        new_file << "  88,   88         \"8b,   ,aa \"8b,   ,aa  \n";                             
        new_file << "  \"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"\'\n";  
        new_file.close();
    }
    else
        std::cout << "Error creating file" << std::endl;
}