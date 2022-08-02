#include <iostream>
#include <string>

int main (void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "Memory address of the string variable: ", std::cout << &string << std::endl;
	std::cout << "Memory address held by stringPTR: ", std::cout << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: ", std::cout << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string variable: ", std::cout << string << std::endl;
	std::cout << "Value pointed to by stringPTR: ", std::cout << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: ", std::cout << stringREF <<std::endl;

	return (0);
}
