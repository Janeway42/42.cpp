#include <iostream>
#include <string>
#include "CheckInput.hpp"
#include "ProcessItem.hpp"

void checkleaks(void)
{
    std::cout << "\n-------------- leaks check --------------------\n\n";
    system("leaks -q conversion");
}

int main(int argc, char **argv)
{

	atexit(checkleaks);
	
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" <<std::endl;
		return (1);
	}
	if (checkPrintable(argv[1]) == 1)
		return (1);
	if (processInput(argv[1]) == 1)
		return (1);	
	return (0);
}