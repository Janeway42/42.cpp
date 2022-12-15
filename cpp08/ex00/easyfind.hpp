#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm> 

template <typename T>
int easyfind(T elem, int x)
{
	typename T::iterator it;
	it = std::find(elem.begin(), elem.end(), x);
	if (it != elem.end())
		std::cout << "postion of int is " << it - elem.begin() << "th element (counting from 0)\n" << std::endl;
	else
		std::cout << "postion of int is no where to be found!" << std::endl;
	return (0);
}

template <typename T> 
void printContainer(T element)
{
	for (typename T::iterator it = element.begin(); it != element.end(); it++)
	{
		std::cout << *it << " "; 
	}
	std::cout << std::endl;
}

#endif