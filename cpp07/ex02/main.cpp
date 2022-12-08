#include "Array.hpp"

void checkleaks(void)
{
	std::cout << '\n';
	system("leaks -q array");
}
int main (void)
{
	atexit(checkleaks);
	// int * a = new int();
	// std::cout << a << std::endl;

	Array<std::string>C(3);

	std::cout << C.size() << std::endl;
	std::cout << "C[5]: "<< C[5] << std::endl;

	// delete a;

	return (0);
}