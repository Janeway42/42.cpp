#include <iostream>
#include <string>
#include <vector>

void printList(std::vector<int> elem, int start, int end)
{
	for (int i = start; i >=start && i <= end; i++)
		std::cout << elem[i] << " ";
	std::cout << "\n";
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Not enough arguments\n";
		return (0);
	}
	
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++ )
	{
		std::cout << argv[i] << " ";
	}
	std::cout << "test \n";

	std::vector<int> One;
	std::cout <<"test\n";
	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
		std::string tempStr(argv[i]);
		std::cout << tempStr << std::endl;
		int temp = std::stoi(tempStr);
		One.push_back(temp);
	}
	printList(One, 0, One.size());

	return (0);
}