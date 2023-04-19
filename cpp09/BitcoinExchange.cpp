#include "BitcoinExchange.hpp"

// ------------ Constructors & Destructors ------------

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::fstream *fsInput, std::fstream *fsCsv)
{
	database = createMap(fsCsv, ",");
	input = createMap(fsInput, "|");
}

BitcoinExchange::~BitcoinExchange(){}

// ------------ other functions ------------

void BitcoinExchange::runExchange()
{
	std::map<std::string, std::string>::iterator itInput;
	std::map<std::string, std::string>::iterator itDatabase;

	for (itInput = input.begin(); itInput != input.end(); itInput++)
	{
		for(itDatabase = database.begin(); itDatabase != database.end(); itDatabase++)
		{
			// std::cout << "test\n";
			// std::cout << "input: " << itInput->first << " | " << "database: " << itDatabase->first << std::endl;
			if (itInput->first == itDatabase->first)
			{
				std::cout << "test1\n";

				double multiplied;
				if (itInput->second != "")
				{
					double val;
					try{
						val = stod(itInput->second);
						if (val < 0)
							std::cout << "Error: not a positive number.\n";
						else 
						{
							multiplied = stod(itInput->second) * val;
							std::cout << itInput->first << " => " << itInput->second << " = " << multiplied << std::endl;
						}
					}
					catch(const std::exception& e)
					{
						std::cout << "Error: too large of a number.\n";
					}
				}
				else
					std::cout << "Error: bad input => " << (*itInput).first << std::endl;
				
			}
		}
	}
}

std::map<std::string, std::string> BitcoinExchange::createMap(std::fstream *fs, std::string separator)
{
	std::string buffer;
	std::map<std::string, std::string> dest;

	getline((*fs), buffer);
	while (!(*fs).eof())
	{
		getline((*fs), buffer);
		if (buffer != "")
		{
			std::string date;
			std::string val;
			size_t out;
			
			out = buffer.find(separator);
			// std::cout << "out: " << out << std::endl;
			date = buffer.substr(0, out);

			int len = 0;		
			for (int i = date.length(); date[i - 1] == ' '; i--){
				len++;}
			date = date.substr(0, date.length() - len);

			if (out == std::string::npos)
				val = "";
			else
				val = buffer.substr(out + 1);
			// std::cout << "val: " << val << ",\n\n";

			dest.insert(std::pair<std::string, std::string> (date, val));
		}
	}
	return (dest);
}