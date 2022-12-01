#include "Serialization.hpp"

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