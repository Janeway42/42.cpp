#include "RPN.hpp"
#include <fcntl.h>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (1);
	}
	try
	{
		rpn storage(argv[1]);
		storage.runStack();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return (0);
}