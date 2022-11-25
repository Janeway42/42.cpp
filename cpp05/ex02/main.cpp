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
    atexit(checkleaks);
	std::cout << "\n------------------------- Shrubbery test ----------------------\n\n";

	Bureaucrat office("ANA", 5);
	Bureaucrat office2("MARIA", 150);
	ShrubberyCreationForm A("TARGET A");  // 145, 137
	std::cout << std::endl;
	
	try
	{
		office.signForm(A);
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
	std::cout << std::endl;
	try
	{
		A.execute(office2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n------------------------- Robotomy test ----------------------\n\n";

	RobotomyRequestForm B("TARGET B"); // 72, 45
	std::cout << std::endl;

	try
	{
		office.signForm(B);
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
	std::cout << std::endl;
	try
	{
		B.execute(office2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n------------------------- Presidential test ----------------------\n\n";

	PresidentialPardonForm C("TARGET C"); // 25, 5
	std::cout << std::endl;

	try
	{
		office.signForm(C);
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
	try
	{
		C.execute(office2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

    return (0);
}