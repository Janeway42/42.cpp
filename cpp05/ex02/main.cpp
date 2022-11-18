#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


void checkleaks(void)
{
    std::cout << "\n-------------- leaks check --------------------\n\n";
    system("leaks -q bureaucrat");
}

int main(void)
{

	std::cout << "\n------------------------- Shrubbery test ----------------------\n\n";

	ShrubberyCreationForm A("target A");  // 145, 137
	Bureaucrat office("Ana", 20);
	
	try
	{
		A.beSigned(office);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		A.execute(office);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n------------------------- Robotomy test ----------------------\n\n";

	RobotomyRequestForm B("target B"); // 72, 45

	try
	{
		B.beSigned(office);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		B.execute(office);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n------------------------- Presidential test ----------------------\n\n";

	PresidentialPardonForm C("target C");
	try
	{
		C.beSigned(office);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		C.execute(office);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

    atexit(checkleaks);
    return (0);
}