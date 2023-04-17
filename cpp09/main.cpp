#include "BitcoinExchange.hpp"
#include <fcntl.h>
#include <fstream>

int fsCleanUp(std::fstream *fsIn, std::fstream *fsData)
{
	if ((*fsIn).is_open())
		fsIn->close();
	if ((*fsData).is_open())
		fsData->close();
}


int verifyInput(std::fstream *fsIn, std::fstream *fsData)
{
	if ((*fsIn).is_open() && (*fsData).is_open())
	{
		if ((*fsIn).eof())
		{
			std::cout << "Empty input file\n";
			return (1);
		}
		return (0);
	}
	std::cout << "Unable to open file\n";
	return (1);
}

int main(int argc, char **argv)
{
	std::fstream fsInput;
	std::fstream fsCsv;

	if (argc != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (1);
	}

	fsInput.open(argv[1], std::fstream::in);
	fsCsv.open("data.csv", std::fstream::in);
	if (verifyInput(&fsInput, &fsCsv) == 1)
	{
		fsCleanUp(&fsInput, &fsCsv);
		return (1);
	}

	BitcoinExchange info(&fsInput, &fsCsv);
	info.runExchange();
	fsCleanUp(&fsInput, &fsCsv);

	return (0);
}