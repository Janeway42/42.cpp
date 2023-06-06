#include "PmergeMe.hpp"

void splitList(std::vector<int> &one, int start, int end)
{
	// std::cout << "start: " << start << " | end: " << end << std::endl;
	// if (start < end)
	// {
	// 	int median = (start + end) / 2;
	// 	std::cout << "median: " << median << " median value: " << one[median] << "\n";
	// 	splitList(one, start, median);
	// 	splitList(one, median + 1, end);
	// 	mergeInsertList(one, start, median, end);
	// 	// printList(one, start, end);
	// }

	std::cout << "start: " << start << " | end: " << end << std::endl;
	int median = (start + end) / 2;
	if (end - start >  1)
	{
		std::cout << "median: " << median << " median value: " << one[median] << "\n";
		splitList(one, start, median);
		splitList(one, median + 1, end);
		// printList(one, start, end);
	}
	else
		mergeInsertList(one, start, median, end);

}

void mergeInsertList(std::vector<int> &one, int start, int median, int end)
{
	int size1 = median - start + 1;
	int size2 = end - median;	

	std::cout << "size1: " << size1 << " | size2: " << size2 << " ---------------------------------------------------------\n" << std::endl;

	int i = 0;
	std::vector<int> left;
	for (; i < size1; i++)
		left.push_back(one[i]);
	std::vector<int> right;
	for (; i <= end; i++)
		right.push_back(one[i]);

	std::cout<< "left size: " << left.size() << " | left itself: ";
	printList(left, 0, left.size());
	std::cout << std::endl;
	std::cout<< "right: ";
	printList(right, 0, right.size());
	std::cout << std::endl;

	i = 0;
	int j = 0;
	int k = 0;

	for (;i < size1 && j < size2; k++)
	{
		if (left[i] <= right[j])
		{
			one[k] = left[i];
			i++;
		}
		else
		{
			one[i] = right[j]; 
			j++;
		}
	}
	for (; i < size1; i++)
		one[k] = left[i];
	for (; j < size2; j++)
		one[k] = right[j];
}

void printList(std::vector<int> elem, int start, int end)
{
	std::cout << "\nprint ends: start: " << start << " end: " << end << std::endl;
	for (int i = start; i >=start && i < end; i++)
		std::cout << elem[i] << " ";
	std::cout << "\n";
}
