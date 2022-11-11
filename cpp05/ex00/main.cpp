#include "Bureaucrat.hpp"

void checkleaks(void)
{
    system("leaks -q bureaucrat");
}

int main(void)
{
	std::cout << " ----------------- Constructors -----------------" << std::endl;

	try
	{
		Bureaucrat *A = new Bureaucrat("Jon", 10);
		delete A;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat *B = new Bureaucrat("Doe", - 10);
		delete B;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat *C = new Bureaucrat("Doeee", 160);
		delete C;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << " ----------------- Pre Increment -----------------" << std::endl;

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
	
	Bureaucrat *B = new Bureaucrat("Winehouse", 150);
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
	
	Bureaucrat *C = new Bureaucrat("Winehouse", 100);
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
	


    std::cout << "-------------- leaks check --------------------\n\n";
    atexit(checkleaks);
    return (0);
}