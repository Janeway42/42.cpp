#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Not enough arguments\n";
		return (0);
	}
	
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++ )
	{
		std::cout << argv[i] << " ";
	}
	std::cout << "\n";

	// first container: vector
	// std::clock_t startList = std::clock();
	std::vector<int> One;
	for (int i = 1; i < argc; i++)
	{
		std::string tempStr(argv[i]);
		int temp = std::stoi(tempStr);
		One.push_back(temp);

	}
		// One.push_back(*argv[i] - '0');
	mergeSortList(One, 0, One.size());
	printList(One, 0, One.size());
	// time?! 

	// second container: deque


	return (0);
}