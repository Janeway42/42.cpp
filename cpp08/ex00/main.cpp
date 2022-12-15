#include "easyfind.hpp"

int main(void)
{
	// find int
	std::vector<int> list;

	for (int i = 3; i < 20 - 1; i++)
	{
		list.push_back(i);
	}
	list.push_back(5);


	printContainer(list);
	easyfind(list, 5);

	int array[] = {123, 231, 321, 453, 543, 657, 453, 329};
	std::vector<int> list2;

	for (int i = 0; i < 8; i++)
	{
		list2.push_back(array[i]);
	}

	printContainer(list2);
	easyfind(list2, 453);

	//error
	easyfind(list, 200);

	return (0);
}
