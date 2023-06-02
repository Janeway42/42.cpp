#include "PmergeMe.hpp"

void sortList(std::list<int> &one, int start, int end)
{
	int middle = (end - start) / 2;

	if (one.size() == 1)
		insertList(one);
	else
	{
		mergeList(one, start, size/2);
		mergeList(one, size - size/2, size);
	}
	


}

static void mergeList(std::list<int> one)
{

}

void insertList(std::list<int> one)
{

}

void printList(std::list<int> elem)
{
	std::list<int>::iterator it;

	for (it = list.beg)

}

0 1 2 3 4 5 6

6 - 0 / 2 = 3 

0 to 3  and 4 to 6

3 / 2 = 1

0 to 1 and 2 to 3      6 - 4 = 2   2/2 = 1   4+1  4+1+1 to 6
