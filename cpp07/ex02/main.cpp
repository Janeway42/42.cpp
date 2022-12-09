#include "Array.hpp"

int main (void)
{
	std::cout << "---------------------fill C-------------------------\n";
	Array<std::string>C(3);
	for(unsigned int i = 0; i < C.size(); i++)
	{
		C[i] = "a";
		std::cout <<"fill C: " << C[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "------------cpy assignment operator----------------\n";
	Array<std::string>D;
	D = C;
	for(unsigned int i = 0; i < D.size(); i++)
	{
		std::cout << "D[i]: " << D[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "----------------ot of range index------------------\n";
	try
	{
		std::cout << "C[10]: " << C[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "----------------copy constructor-------------------\n";
	Array<std::string>E(D);
	for(unsigned int i = 0; i < E.size(); i++)
	{
		std::cout << "E[i]: " << E[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "-------modify string & veryfy copy stays clear--------\n";

	C[1] = "b";
	for(unsigned int i = 0; i < C.size(); i++)
	{
		std::cout << "C modified: " << C[i] << std::endl;
	}
	for(unsigned int i = 0; i < D.size(); i++)
	{
		std::cout << "D[i]: " << D[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	return (0);
}