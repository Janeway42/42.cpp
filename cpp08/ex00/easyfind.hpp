#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

template <typename T>
int easyfind(T elem, int x)
{
	size_t i;
	for (i = 0; i < elem.size(); i++)
	{
		if (elem[i] == x)
		{
			std::cout << "postion of int is " << i + 1 << "th element (counting from 1)\n" << std::endl;
			return (i + 1);
		}
	}
	if (i == elem.size())
	{
		std::cout << "postion of int is no where to be found!" << std::endl;
		return (-1);
	}
	return (0);
}

template <typename T>
void printVector(T elem)
{
	for (size_t i = 0; i < elem.size(); i++)
	{
		std::cout << elem[i] << " ";
	}
	std::cout << std::endl;
}
#endif