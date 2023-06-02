#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Not enough arguments\n";
		return (0);
	}
	
	std::cout << "Before: ";
	for (int i = 1; i <= argc; i++ )
	{
		std::cout << argv[i] << " ";
	}
	std::cout << "\n";

	// first container: list
	std::clock_t startList = std::clock();
	std::list<int> listOne;
	for (int i = 1; i <= argc; i++)
		listOne.push_back(*argv[i] - '0');
	sortList(listOne);
	// time?! 

	// second container: deque


	return (0);
}