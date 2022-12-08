#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>

template <typename T>
void display(T elem)
{
	std::cout << elem;;
}

template <typename Array, typename S, typename element>
void iter(Array *a, S length, void(* function)(element))
{
	for (S i = 0; i < length - 1; i++)
	{
		(*function)(a[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
}

#endif