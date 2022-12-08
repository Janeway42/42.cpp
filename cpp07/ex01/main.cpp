#include "iter.hpp"

int main (void)
{

	std::string array1[] = {"Alpha", "Beta", "Gamma", "Delta"};
	iter(array1, 4, &display<std::string>);

	int array2[] = {99, 88, 77, 66, 55, 44};
	iter(array2, 6, &display<int>);

	return (0);
}