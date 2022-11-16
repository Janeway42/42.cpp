#include "Bureaucrat.hpp"
#include "Form.hpp"

void checkleaks(void)
{
    system("leaks -q bureaucrat");
}

int main(void)
{
	std::cout << " ----------------- Constructors -----------------" << std::endl;

	try
	{
		Form *A = new Form("paper", 200, 150);
		delete A;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form *B = new Form("paper", -20, 150);
		delete B;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form *C = new Form("paper", 5, 100);
		delete C;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	std::cout << std::endl;

	std::cout << " ----------------- Sign Form -----------------" << std::endl;

	Form *A = new Form("paper", 100, 150);
	Bureaucrat *X = new Bureaucrat("office", 10);
	try
	{
		A->beSigned(*X);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	X->signForm(*A);
	delete A;
	delete X;
	std::cout << std::endl;

	Form *C = new Form("red tape",50, 150);
	Bureaucrat *Y = new Bureaucrat("office", 100);
	try
	{
		C->beSigned(*Y);
		Y->signForm(*C);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete C;
	delete Y;
	std::cout << std::endl;


    std::cout << "-------------- leaks check --------------------\n\n";
    atexit(checkleaks);
    return (0);
}