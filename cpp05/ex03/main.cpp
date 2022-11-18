#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


void checkleaks(void)
{
    std::cout << "\n-------------- leaks check --------------------\n\n";
    system("leaks -q bureaucrat");
}

int main(void)
{

	std::cout << "\n------------------------- Shrubbery test ----------------------\n\n";

	Intern newbie;
	Form* output;
	std::cout << std::endl;
	
	output = newbie.makeForm("shrubbery request", "the mountain");
	delete output;
	std::cout << std::endl;

	output = newbie.makeForm("robotomy request", "the mountain");
	delete output;
	std::cout << std::endl;

	output = newbie.makeForm("presidential request", "the mountain");
	delete output;
	std::cout << std::endl;

	output = newbie.makeForm("form request", "practice");
	delete output;
	std::cout << std::endl;

    atexit(checkleaks);
    return (0);
}