#include "Span.hpp"

int main ()
{
	int array[] = {2, 4, 8, 10, 1, 30};
	Span test(6);
	for (int i = 0; i < 6; i++)
	{
		test.addNumber(array[i]);
	}
	std::cout << test.shortestSpan() << std::endl; 
	return (0);
}