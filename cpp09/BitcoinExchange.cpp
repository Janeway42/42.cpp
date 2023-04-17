#include "BitcoinExchange.hpp"

// ------------ Constructors & Destructors ------------

BitcoinExchange::BitcoinExchange()
{
	// create database map 
}

BitcoinExchange::BitcoinExchange(std::fstream *fsInput, std::fstream *fsCsv)
{
	std::string buffer;

	while (!(*fsInput).eof())
	{
		getline((*fsInput), buffer);

		t_date temp;
		int out = buffer.find("-");
		temp.year = buffer.substr(out);
		buffer = buffer.substr(out + 1);

		out = buffer.find("-");
		temp.month = buffer.substr(out);
		buffer = buffer.substr(out + 1);

		out = buffer.find(",");
		temp.day = buffer.substr(out);
		buffer = buffer.substr(out + 1);

		double val = stod(buffer);

		input.insert(temp, val);

	}
}

BitcoinExchange::~BitcoinExchange()
{

}

// ------------ other functions ------------

void BitcoinExchange::runExchange()
{
	// compare dates from input with dates from database 

}