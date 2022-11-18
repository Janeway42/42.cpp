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
	try
	{
		X->signForm(*A);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete A;
	delete X;
	std::cout << std::endl;

	Form *C = new Form("red tape",50, 150);
	Bureaucrat *Y = new Bureaucrat("office", 100);
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

	std::cout << " ----------------- Copy Form -----------------" << std::endl;

 	Form E = Form("copy", 5, 25);
	Bureaucrat Z("office", 6);
	try
	{
		E.beSigned(Z);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << " Form E: name - " << E.getName() << std::endl;
	std::cout << " Form E: signed - " << E.getSigned() << std::endl;
	std::cout << " Form E: signGrade - " << E.getSignGrade() << std::endl;
	std::cout << " Form E: executeGrade - " << E.getExecuteGrade() << std::endl;
	std::cout << std::endl;

	Form *B = new Form("paste", 150, 20);
	std::cout << " Form B: name - " << B->getName() << std::endl;
	std::cout << " Form B: signed - " << B->getSigned() << std::endl;
	std::cout << " Form B: signGrade - " << B->getSignGrade() << std::endl;
	std::cout << " Form B: executeGrade - " << B->getExecuteGrade() << std::endl;
	std::cout << std::endl;

	*B = E;
	std::cout << std::endl;

	std::cout << " Form B: name - " << B->getName() << std::endl;
	std::cout << " Form B: signed - " << B->getSigned() << std::endl;
	std::cout << " Form B: signGrade - " << B->getSignGrade() << std::endl;
	std::cout << " Form B: executeGrade - " << B->getExecuteGrade() << std::endl;
	std::cout << std::endl;

	delete B;

    std::cout << "-------------- leaks check --------------------\n\n";
    atexit(checkleaks);
    return (0);
}