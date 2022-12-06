#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>

template <typename T>
void display(T elem)
{
	std::cout << elem << std::endl;
}

template <typename Array, typename S, typename element>
void iter(Array *a, S length, (* function)(element))
{
	for (S i = 0; i < length; i++)
		(* function)(a[i]);
}


#endif