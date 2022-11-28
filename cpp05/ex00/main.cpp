#include "Bureaucrat.hpp"

void checkleaks(void)
{
	std::cout << "\n-------------- leaks check --------------------\n\n";
    system("leaks -q bureaucrat");
}

int main(void)
{
    atexit(checkleaks);
	std::cout << "\n----------------- Constructors -----------------" << std::endl;

	try
	{
		Bureaucrat *A = new Bureaucrat("JON", 10);
		delete A;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat *B = new Bureaucrat("DOE", - 10);
		delete B;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat *C = new Bureaucrat("DOEEEE", 160);
		delete C;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "----------------- Increment -----------------" << std::endl;

	Bureaucrat *A = new Bureaucrat("Amy", 1);
	try
	{
		std::cout << "A: " << A->getGrade() << std::endl;
		A->incrementGrade();
		std::cout << "A: " << A->getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete A;
	std::cout << std::endl;
	
	Bureaucrat *B = new Bureaucrat("WINEHOUSE", 150);
	try
	{
		std::cout << "B: " << B->getGrade() << std::endl;
		B->decrementGrade();
		std::cout << "B: " << B->getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete B;
	std::cout << std::endl;
	
	Bureaucrat *C = new Bureaucrat("AMY", 100);
	try
	{
		std::cout << "C: " << C->getGrade() << std::endl;
		C->decrementGrade();
		std::cout << "C: " << C->getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete C;
	std::cout << std::endl;

	std::cout << "----------------- << operator -----------------" << std::endl;

	Bureaucrat V("TYPE TEST", 75);
	std::cout << std::endl;	
	std::cout << V << std::endl;
    std::cout << std::endl;	
    return (0);
}