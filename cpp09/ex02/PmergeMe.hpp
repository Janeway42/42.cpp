#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>

// #define min_size 25

template <typename T>
void printContainer(T elem)
{
	std::cout << "After:	";
	typedef typename T::iterator it;
	it iterator;
	
	for (iterator = elem.begin(); iterator != elem.end(); iterator++)
		std::cout << *iterator << " ";
	std::cout << "\n";
}

// Step 3: merge the two small containers after they have been sorted 
template <typename T>
void merge(T &elem, int start, int median, int end)
{
	int sizeLeft = median - start + 1;
	int sizeRight = end - median;

	// std::cout << "sizeLeft: " << sizeLeft << " | sizeRight: " << sizeRight << std::endl;

	T left (elem.begin() + start, elem.begin() + median + 1);
	T right (elem.begin() + median + 1, elem.begin() + end + 1);

	int indexLeft = 0;
	int indexRight = 0;

	for(int k = start; k < (end - start + 1); k++)
	{
		// std::cout << " ----------------------------------- \n";
		// std::cout << "k: " << k << " indexRight: " << indexRight << " indexLeft: " << indexLeft << std::endl;
		// std::cout << "left[indexLeft]: " << left[indexLeft] << " |  right[indexright]: " << right[indexRight] << std::endl;
		// std::cout << "elem["<< k << "] before: " << elem[k] << std::endl;

		if (indexRight == sizeRight)
		{
			// std::cout << "full right\n";
			elem[k] = left[indexLeft];
			indexLeft++;
		}
		else if (indexLeft == sizeLeft)
		{
			// std::cout << "full left\n";
			elem[k] = right[indexRight];
			indexRight++;
		}
		else if (right[indexRight] > left[indexLeft])
		{
			// std::cout << "right > left\n";
			elem[k] = left[indexLeft];
			indexLeft++;
		}
		else
		{
			// std::cout << "left > right\n";
			elem[k] = right[indexRight];
			indexRight++;
		}
		// std::cout << "elem["<< k << "]: " << elem[k] << std::endl;
		// std::cout << " ----------------------------------- \n";
	}
}

// Step 2: sort and insert the smallest containers resulted from "sort"
template <typename T>
void insertionSort(T &elem, int start, int end)
{
	// std::cout << "insertion: ";
	// for (int i = start; i <= end; i++)
	// 	std::cout << elem[i] << " ";
	// std::cout << std::endl;

	for (int i = start; i < end; i++)
	{
		unsigned long temp = elem[i + 1];
		int j = i + 1;
		while (j > start && elem[j - 1] > temp)
		{
			// std::cout << "elem[" << j << "]: " << elem[j] << " | elem[" << j - 1 << "]: " << elem[j - 1] << std::endl; 
			elem[j] = elem[j - 1];
			// std::cout << "full["<< j << "]: " << elem[j]<< std::endl;
			j--;
		}
		elem[j] = temp;
	}
}

// Step 1: divide the given n elements of the container into (n/min_size) groups of each group of size min_size
template <typename T>
void sort(T &elem, int start, int end)
{
	int min = elem.size() / 2;
	min = 5;
	if (end - start > min)
	{
		int median = (start + end) / 2;
		sort(elem, start, median);
		sort(elem, median + 1, end);
		// std::cout << "Before merge:	";
		// printContainer(elem);
		merge(elem, start, median, end);
		// std::cout << "After merge:	";
		// printContainer(elem);
	}
	else
	{
		// std::cout << "Before insertion:	";
		// printContainer(elem);
		insertionSort(elem, start, end);
		// std::cout << "After insertion:	";
		// printContainer(elem);
	}
}

