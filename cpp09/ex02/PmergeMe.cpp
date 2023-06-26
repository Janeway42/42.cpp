#include "PmergeMe.hpp"

// vector 
// -----------------------------------------------------------------------

void printContainer(std::vector<int> elem)
{
	std::cout << "After:	";
	std::vector<int>::iterator it;
	for (it = elem.begin(); it != elem.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

// Step 3: merge the two small containers after they have been sorted 
void merge(std::vector<int> &elem, int start, int median, int end)
{
	int sizeLeft = median - start + 1;
	int sizeRight = end - median;

	int i = start;
	std::vector<int> left;
	for (; i < start + sizeLeft; i++)
		left.push_back(elem[i]);

	std::vector<int> right;
	for (int l = 0; l < sizeRight ; l++)
	{
		right.push_back(elem[i]);
		i++;
	}

	int indexLeft = 0;
	int indexRight = 0;

	for(int k = start; k <= end; k++)
	{
		if (indexRight == sizeRight)
		{
			elem[k] = left[indexLeft];
			indexLeft++;
		}
		else if (indexLeft == sizeLeft)
		{
			elem[k] = right[indexRight];
			indexRight++;
		}
		else if (right[indexRight] > left[indexLeft])
		{
			elem[k] = left[indexLeft];
			indexLeft++;
		}
		else
		{
			elem[k] = right[indexRight];
			indexRight++;
		}
	}
}

// Step 2: sort and insert the smallest containers resulted from "sort"
void insertionSort(std::vector<int> &elem, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		unsigned long temp = elem[i + 1];
		int j = i + 1;
		while (j > start && elem[j - 1] > temp)
		{
			elem[j] = elem[j - 1];
			j--;
		}
		elem[j] = temp;
	}
}

// Step 1: divide the given n elements of the container into (n/min_size) groups of each group of size min_size
void sort(std::vector<int> &elem, int start, int end)
{
	if (end - start > min_size)
	{
		int median = (start + end) / 2;
		sort(elem, start, median);
		sort(elem, median + 1, end);
		merge(elem, start, median, end);
	}
	else
		insertionSort(elem, start, end);
}

// dque 
// -----------------------------------------------------------------------

void printContainer(std::deque<int> elem)
{
	std::cout << "After:	";
	std::deque<int>::iterator it;
	for (it = elem.begin(); it != elem.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

// Step 3: merge the two small containers after they have been sorted 
void merge(std::deque<int> &elem, int start, int median, int end)
{
	int sizeLeft = median - start + 1;
	int sizeRight = end - median;

	int i = start;
	std::deque<int> left;
	for (; i < start + sizeLeft; i++)
		left.push_back(elem[i]);

	std::deque<int> right;
	for (int l = 0; l < sizeRight ; l++)
	{
		right.push_back(elem[i]);
		i++;
	}

	int indexLeft = 0;
	int indexRight = 0;

	for(int k = start; k <= end; k++)
	{
		if (indexRight == sizeRight)
		{
			elem[k] = left[indexLeft];
			indexLeft++;
		}
		else if (indexLeft == sizeLeft)
		{
			elem[k] = right[indexRight];
			indexRight++;
		}
		else if (right[indexRight] > left[indexLeft])
		{
			elem[k] = left[indexLeft];
			indexLeft++;
		}
		else
		{
			elem[k] = right[indexRight];
			indexRight++;
		}
	}
}

// Step 2: sort and insert the smallest containers resulted from "sort"
void insertionSort(std::deque<int> &elem, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		unsigned long temp = elem[i + 1];
		int j = i + 1;
		while (j > start && elem[j - 1] > temp)
		{
			elem[j] = elem[j - 1];
			j--;
		}
		elem[j] = temp;
	}
}

// Step 1: divide the given n elements of the container into (n/min_size) groups of each group of size min_size
void sort(std::deque<int> &elem, int start, int end)
{
	if (end - start > min_size)
	{
		int median = (start + end) / 2;
		sort(elem, start, median);
		sort(elem, median + 1, end);
		merge(elem, start, median, end);
	}
	else
		insertionSort(elem, start, end);
}

