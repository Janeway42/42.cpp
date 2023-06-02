#include "RPN.hpp"
#include <fcntl.h>
#include <fstream>

// int verifyInput(std::string input)
// {
	
// }


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (1);
	}
	rpn storage(argv[1]);
	storage.runStack();

	// storage.printList();
	return (0);
}