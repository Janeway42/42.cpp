#include "Bureaucrat.hpp"
#include "Form.hpp"

void checkleaks(void)
{
    std::cout << "\n-------------- leaks check --------------------\n\n";
    system("leaks -q bureaucrat");
}

int main(void)
{
    atexit(checkleaks);
	std::cout << "----------------- Constructors -----------------\n\n" << std::endl;

	try
	{
		Form *A = new Form("PAPER", 200, 150);
		delete A;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form *B = new Form("PAPER", -20, 150);
		delete B;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form *C = new Form("PAPER", 5, 100);
		delete C;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	std::cout << std::endl;

	std::cout << "----------------- Sign Form -----------------\n\n" << std::endl;

	Form A("PAPER 1", 100, 150);
	Bureaucrat *X = new Bureaucrat("OFFICE", 10);
	try
	{
		X->signForm(A);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete X;

	Form *C = new Form("RED TAPE",50, 150);
	Bureaucrat *Y = new Bureaucrat("OFFICE", 100);
	try
	{
		Y->signForm(*C);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete C;
	delete Y;
	std::cout << std::endl;

	std::cout << "----------------- operator << -----------------\n\n" << std::endl;

	Form K("PRINT TEST", 5, 15);
	std::cout << K << std::endl;
	std::cout << std::endl;

    return (0);
}