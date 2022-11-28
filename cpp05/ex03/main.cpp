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
    atexit(checkleaks);
	std::cout << "\n------------------------- Make Form ----------------------\n\n";

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

	output = newbie.makeForm("abc", "practice");
	delete output;


	std::cout << "\n------------------------- Print test ----------------------\n\n";

	Bureaucrat A("NAME", 120);
	PresidentialPardonForm B("TARGET");
	std::cout << std::endl;

	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;

    return (0);
}