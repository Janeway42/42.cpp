#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	srand(time(0));
	int i = rand() % 3;

	Base *newBase = NULL;

	switch(i)
	{
		case 1:
			newBase = new A();
			break ;
		case 2:
			newBase = new B();
			break;
		default:
			newBase = new C();
	}
	return (newBase);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Type C" << std::endl;	
}

// Dynamic Cast: A cast is an operator that converts data from one type to another type. 
// In C++, dynamic casting is mainly used for safe downcasting at run time. 
// To work on dynamic_cast there must be one virtual function in the base class. 
// A dynamic_cast works only polymorphic base class because it uses this information to decide safe downcasting.

// if dynamic_cast fails, std::bad_cast exception is thrown only 
// if the destination is a reference type. If the destination is a 
// pointer type then no exception is thrown from the cast. 

void identify(Base& p)
{
	try 
	{
		A& test = dynamic_cast<A&>(p);
		(void)test;
		std::cout << "Type A (reference)" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "failed cast" << std::endl;
	}

	try 
	{
		B& test = dynamic_cast<B&>(p);
		(void)test;
		std::cout << "Type B (reference)" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "failed cast" << std::endl;
	}

	try 
	{
		C& test = dynamic_cast<C&>(p);
		(void)test;
		std::cout << "Type C (reference)" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "failed cast" << std::endl;
	}
}

int main(void)
{
	Base *test = generate();

	identify(test);
	std::cout << std::endl;
	identify(*test);
	std::cout << std::endl;
	
	delete(test);
	return (0);
}