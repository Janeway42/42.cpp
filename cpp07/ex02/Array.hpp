#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T> 

class Array
{
	private:
		unsigned int _length;

	public:
		T *element;

		Array(void): _length(5)
		{
			std::cout << "default constructor" << std::endl;
			element = new T[_length];
		}
		~Array(void);
};

#endif