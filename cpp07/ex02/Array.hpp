#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T> 

class Array
{
	private:
		T *_element;
		unsigned int _size;

	public:

		Array(void): _element(new T[0]), _size(0)
		{
			std::cout << "default constructor" << std::endl;
			_element = new T[0];
		}

		Array(unsigned int n): _element(new T[n]), _size(n)
		{
			std::cout << "constructor with value" << std::endl;
		}

		Array(const Array &existing): _element(new T[existing._size]), _size(existing._size)
		{
			std::cout << "copy constructor" << std::endl;
			for (unsigned int i = 0; i < existing._size; i++)
					_element[i] = existing._element[i];
		}

		~Array(void)
		{
			std::cout << "destructor called" << std::endl;
			delete[] _element;
		}

		Array& operator =(const Array &existing)
		{
			std::cout << "copy assignment operator" << std::endl;
			if (this != &existing)
			{
				delete[] _element;
				this->_size = existing._size;
				_element = new T[_size];
				for (unsigned int i = 0; i < existing._size; i++)
					_element[i] = existing._element[i];
			}
			return (*this);
		}

		T& operator [] (unsigned int index)
		{
			// std::cout << "test" << std::endl;
			if (index > _size)
				throw IndexOutOfBound();
			return(_element[index]);	
		}

		unsigned int size(void) const
		{
			return (this->_size);
		}

		T* getElement(void)
		{
			return (this->_element);
		}

		class IndexOutOfBound: public std::exception
		{
			const char * what() const throw()
			{
				return ("Index out of range!");
			}	 
		};

};

#endif