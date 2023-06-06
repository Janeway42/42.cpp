#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Not enough arguments\n";
		return (0);
	}
	
	std::cout << "Before:	";
	for (int i = 1; i < argc; i++ )
		std::cout << argv[i] << " ";
	std::cout << "\n";

	// first container: vector
	std::clock_t startVector = std::clock();
	std::vector<unsigned long> One;
	for (int i = 1; i < argc; i++)
	{
		std::string tempStr(argv[i]);
		unsigned long temp = std::stol(tempStr);
		if (temp < 0)
			std::cout << "Error: not a positive integer\n";
		One.push_back(temp);

	}
	sort(One, 0, One.size() - 1);
	std::clock_t	endVector = std::clock();
	long double		timeVector = 1000.0 * (endVector - startVector) / CLOCKS_PER_SEC;
	printContainer(One);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << timeVector << " us"<< std::endl;

	// second container: deque
	std::clock_t startDeque = std::clock();
	std::deque<unsigned long> Two;
	for (int j = 1; j < argc; j++)
	{
		unsigned long temp = std::strtoul(argv[j], NULL, 0);
		if (temp < 0)
			std::cout << "Error: not a positive integer\n";
		Two.push_back(temp);
	}

	sort(Two, 0, Two.size() - 1);
	std::clock_t	endDeque = std::clock();
	long double		timeDeque = 1000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;
	printContainer(Two);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << timeDeque << " us" << std::endl;
	return (0);
}