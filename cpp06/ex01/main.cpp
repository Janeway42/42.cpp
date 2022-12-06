#include "Serialization.hpp"

// uintptr_t is an unsigned integer type 
// with the property that any valid pointer to void can be converted to this type, 
// then converted back to pointer to void, 
// and the result will compare equal to the original pointer".

// A pointer to void is a general-purpose pointer 
// used to hold references to any data type.

// reinterpret_cast is used to convert a pointer of some data type 
// into a pointer of another data type, even if the data types before and after conversion are different.
// It does not check if the pointer type and data pointed by the pointer is same or not.

uintptr_t serialize(Data* ptr)
{
	uintptr_t pointer = reinterpret_cast<uintptr_t>(ptr);
	return (pointer);
}

Data* deserialize(uintptr_t raw)
{
	Data *structure = reinterpret_cast<Data *>(raw);
	return (structure);

}

int main(void)
{
	Data example;
	Data *deserializedExample;
	uintptr_t pointer;

	example.filler1 = 1;
	example.filler2 = 2;

	pointer = serialize(&example);
	std::cout << "example.filler1: " << example.filler1 << std::endl;
	std::cout << "example.filler2: " << example.filler2 << std::endl;

	deserializedExample = deserialize(pointer);

	std::cout << "deserializedExample->filler1: " << deserializedExample->filler1 << std::endl;
	std::cout << "deserializedExample->filler2: " << deserializedExample->filler2 << std::endl;

	return (0);
}