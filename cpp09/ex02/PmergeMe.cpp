#include "PmergeMe.hpp"

void mergeSortList(std::vector<int> &one, int start, int end)
{
	std::cout << "start: " << start << " | end: " << end << std::endl;
	if (start < end)
	{
		int median = (start + end) / 2;
		std::cout << "median: " << median << "\n";
		mergeSortList(one, start, median);
		mergeSortList(one, median + 1, end);
		insertList(one, start, median, end);
		printList(one, start, end);
	}
}

void insertList(std::vector<int> &one, int start, int median, int end)
{
	int size1 = median - start + 1;
	int size2 = end - median;	

	std::vector<int> left(one.begin(), one.begin() + median + 1);
	std::vector<int> right(one.begin() + median + 1, one.begin() + end + 1);

	std::cout<< "left: " << left.size() << " | ";
	printList(left, 0, left.size());
	std::cout << std::endl;
	std::cout<< "right: ";
	printList(right, 0, right.size());
	std::cout << std::endl;

	int i = 0;
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
	for (int i = start; i >=start && i <= end; i++)
		std::cout << elem[i] << " ";
	std::cout << "\n";
}
