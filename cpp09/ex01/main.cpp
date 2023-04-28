#include "RPN.hpp"
#include <fcntl.h>
#include <fstream>

// int verifyInput(std::string input)
// {
	
// }


int main(int argc, char **argv)
{
	std::fstream fs;
	std::string buffer;

	if (argc < 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (1);
	}

	fs.open(argv[1], std::fstream::in);
	getline(fs, buffer);

	std::cout << "buffer: " << buffer << std::endl;
	
	// if (verifyInput(buffer) == 1)
	// 	return (1);

	rpn storage;
	// storage.runList();

	storage.printList();
	return (0);
}