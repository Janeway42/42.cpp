#include "PmergeMe.hpp"

// make re && ./PmergeMe `jot -r 20 1 100 | tr '\n' ' ' `

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
	std::cout << "\n\n";

	for (int i = 1; i < argc; i++)
	{
		std::string temp(argv[i]);
		for (std::string::iterator it = temp.begin(); it != temp.end(); it++)
		{
			if (*it < 48 || *it > 57)
			{
				std::cout << "Error: wrong input\n";
				return (0);
			}
		}
	}

	// first container: vector
	std::clock_t startVector = std::clock();
	std::vector<unsigned long> One;
	for (int i = 1; i < argc; i++)
	{
		std::string tempStr(argv[i]);
		unsigned long temp;
		try
		{
			temp = std::strtoul(argv[i], NULL, 0);
			if (temp > INT_MAX)
			{
				std::cout << "Error: not an integer\n";
				return (0);
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: Failed stol!\n";
		}

		One.push_back(temp);
	}
	sort(One, 0, One.size() - 1);
	std::clock_t	endVector = std::clock();
	long double		timeVector = 1000.0 * (endVector - startVector) / CLOCKS_PER_SEC;
	printContainer(One);
	std::cout << "\nTime to process a range of " << argc - 1 << " elements with std::vector: " << timeVector << " us\n\n";

	// second container: deque
	std::clock_t startDeque = std::clock();
	std::deque<unsigned long> Two;
	for (int j = 1; j < argc; j++)
	{
		unsigned long temp;
		try
		{
			temp = std::strtoul(argv[j], NULL, 0);
			if (temp > INT_MAX)
			{
				std::cout << "Error: not an integer\n";
				return (0);
			}
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: Failed stol!\n";
		}
		Two.push_back(temp);
	}

	sort(Two, 0, Two.size() - 1);
	std::clock_t	endDeque = std::clock();
	long double		timeDeque = 1000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;
	printContainer(Two);
	std::cout << "\nTime to process a range of " << argc - 1 << " elements with std::deque: " << timeDeque << " us\n\n";
	return (0);
}