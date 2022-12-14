#include "easyfind.hpp"

int main(void)
{
	//int 
	std::vector<int> list;

	for (int i = 3; i < 20; i++)
	{
		list.push_back(i);
	}

	printContainer(list);
	easyfind(list, 5);

	// string 
	int array[] = {123, 231, 321, 453, 543, 657, 731};
	std::vector<int> list2;

	for (int i = 0; i < 7; i++)
	{
		list2.push_back(array[i]);
	}

	printContainer(list2);
	easyfind(list2, 453);

	//error
	easyfind(list, 200);

	return (0);
}
