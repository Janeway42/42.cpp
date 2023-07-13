#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>

#define min_size 5

void printContainerVector(std::vector<unsigned long> elem);
void mergeVector(std::vector<unsigned long> &elem, int start, int median, int end);
void insertionSortVector(std::vector<unsigned long> &elem, int start, int end);
void sortVector(std::vector<unsigned long> &elem, int start, int end);

void printContainerDeque(std::deque<unsigned long> elem);
void mergeDeque(std::deque<unsigned long> &elem, int start, int median, int end);
void insertionSortDeque(std::deque<unsigned long> &elem, int start, int end);
void sortDeque(std::deque<unsigned long> &elem, int start, int end);



// template <typename T>
// void printContainer(T elem)
// {
// 	std::cout << "After:	";
// 	typedef typename T::iterator it;
// 	it iterator;
	
// 	for (iterator = elem.begin(); iterator != elem.end(); iterator++)
// 		std::cout << *iterator << " ";
// 	std::cout << "\n";
// }

// // Step 3: merge the two small containers after they have been sorted 
// template <typename T>
// void merge(T &elem, int start, int median, int end)
// {
// 	int sizeLeft = median - start + 1;
// 	int sizeRight = end - median;

// 	int i = start;
// 	T left;
// 	for (; i < start + sizeLeft; i++)
// 		left.push_back(elem[i]);

// 	T right;
// 	for (int l = 0; l < sizeRight ; l++)
// 	{
// 		right.push_back(elem[i]);
// 		i++;
// 	}

// 	int indexLeft = 0;
// 	int indexRight = 0;

// 	for(int k = start; k <= end; k++)
// 	{
// 		if (indexRight == sizeRight)
// 		{
// 			elem[k] = left[indexLeft];
// 			indexLeft++;
// 		}
// 		else if (indexLeft == sizeLeft)
// 		{
// 			elem[k] = right[indexRight];
// 			indexRight++;
// 		}
// 		else if (right[indexRight] > left[indexLeft])
// 		{
// 			elem[k] = left[indexLeft];
// 			indexLeft++;
// 		}
// 		else
// 		{
// 			elem[k] = right[indexRight];
// 			indexRight++;
// 		}
// 	}
// }

// // Step 2: sort and insert the smallest containers resulted from "sort"
// template <typename T>
// void insertionSort(T &elem, int start, int end)
// {
// 	for (int i = start; i < end; i++)
// 	{
// 		unsigned long temp = elem[i + 1];
// 		int j = i + 1;
// 		while (j > start && elem[j - 1] > temp)
// 		{
// 			elem[j] = elem[j - 1];
// 			j--;
// 		}
// 		elem[j] = temp;
// 	}
// }

// // Step 1: divide the given n elements of the container into (n/min_size) groups of each group of size min_size
// template <typename T>
// void sort(T &elem, int start, int end)
// {
// 	if (end - start > min_size)
// 	{
// 		int median = (start + end) / 2;
// 		sort(elem, start, median);
// 		sort(elem, median + 1, end);
// 		merge(elem, start, median, end);
// 	}
// 	else
// 		insertionSort(elem, start, end);
// }
