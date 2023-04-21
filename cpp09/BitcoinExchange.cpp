#include "BitcoinExchange.hpp"

// ------------ Constructors & Destructors ------------

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::fstream *fsInput, std::fstream *fsCsv)
{
	database = createMap(fsCsv, ",");
	input = createMap(fsInput, "|");
	// std::cout << "-------------------------- print Input Constructor ---------------------------------\n";
	// for (std::vector<std::pair<std::string, std::string> >::iterator it = input.begin(); it != input.end(); it++)
	// {
	// 	std::cout << "itInput->first: " << it->first << " itInput->second: " << it->second << std::endl;
	// }
	// std::cout << "-------------------------- print Input ---------------------------------\n\n\n";
}

BitcoinExchange::~BitcoinExchange(){}

// ------------ other functions ------------

void BitcoinExchange::runExchange()
{
	std::vector<std::pair<t_date, std::string> >::iterator itInput;
	std::vector<std::pair<t_date, std::string> >::iterator itDatabase;

	// std::cout << "-------------------------- print Input ---------------------------------\n";
	// for (std::vector<std::pair<std::string, std::string> >::iterator it = input.begin(); it != input.end(); it++)
	// {
	// 	std::cout << "itInput->first: " << it->first << " itInput->second: " << it->second << std::endl;
	// }
	// std::cout << "-------------------------- print Input ---------------------------------\n";

	for (itInput = input.begin(); itInput != input.end(); itInput++)
	{
		// std::cout << "itInput->first: " << itInput->first << " itInput->second: " << itInput->second << std::endl;

		for(itDatabase = database.begin(); itDatabase != database.end(); itDatabase++)
		{
			// std::cout << "test\n";
			// std::cout << "input: " << itInput->first << " | " << "database: " << itDatabase->first << std::endl;
			if (itInput->first.date == itDatabase->first.date)
			{
				// std::cout << "we have a match ---------------\n";

				if (itInput->second != "")
				{
					// std::cout << "itInput->first: " << itInput->first << " itInput->second: " << itInput->second << std::endl;

					double multiplied;
					double quantity;
					try{
						quantity = stod(itInput->second);
						if (quantity > INT_MAX)
							std::cout << "Error: too large a number." << std::endl;
						else
						{
							// std::cout << "itInput->second: " << itInput->second << std::endl;
							// std::cout << "quantity: " << quantity << std::endl;
							if (quantity < 0)
								std::cout << "Error: not a positive number.\n";
							else 
							{
								multiplied = stod(itDatabase->second) * quantity;
								std::cout << itInput->first.date << " => " << itInput->second << " = " << multiplied << std::endl;
							}
						}						
					}
					catch(const std::exception& e)
					{
						std::cout << "Failed stod.\n";
					}
				}
				else
					std::cout << "Error: bad input => " << (*itInput).first.date << std::endl;
				
			}
			else
			{
				findClosest(&(*itInput));


			}
		}
		std::cout << std::endl;
	}
}

std::vector<std::pair<t_date, std::string> > BitcoinExchange::createMap(std::fstream *fs, std::string separator)
{
	std::string buffer;
	std::vector <std::pair<t_date, std::string> > dest;

	getline((*fs), buffer);
	while (!(*fs).eof())
	{
		getline((*fs), buffer);
		if (buffer != "")
		{
			t_date temp;
			std::string val;
			size_t out;
			
			out = buffer.find(separator);
			// std::cout << "out: " << out << std::endl;
			temp.date = buffer.substr(0, out);

			int len = 0;		
			for (int i = temp.date.length(); temp.date[i - 1] == ' '; i--){
				len++;}
			temp.date = temp.date.substr(0, temp.date.length() - len);
			temp.year = stoi(temp.date.substr(0,3));
			temp.month = stoi(temp.date.substr(5,6));
			temp.day = stoi(temp.date.substr(8,9));

			if (out == std::string::npos)
				val = "";
			else
				val = buffer.substr(out + 1);
			// std::cout << "val: " << val << ",\n\n";

			dest.push_back(make_pair(temp, val));
		}
	}

	// std::cout << "-------------------------- print Input createMap ---------------------------------\n";
	// for (std::vector<std::pair<std::string, std::string> >::iterator it = dest.begin(); it != dest.end(); it++)
	// {
	// 	std::cout << "itInput->first: " << it->first << " itInput->second: " << it->second << std::endl;
	// }
	// std::cout << "-------------------------- print Input ---------------------------------\n\n\n";
	return (dest);
}

void BitcoinExchange::findClosest(std::vector<std::pair<t_date, std::string> > *item)
{
	std::vector<std::pair<t_date, std::string> >::iterator itDatabase;

	for(itDatabase = database.begin(); itDatabase != database.end(); itDatabase++)
	{
		for (itDatabase; itDatabase->first.year > item->front().first.year; itDatabase++){}
		if (item->front().first.year > itDatabase->first.year)
		{
			if (itDatabase != database.begin())
			{
				itDatabase--;
				double multiplied = stod(itDatabase->second) * stod(item->front().second);
				std::cout << item->front().first.date << " => " << item->front().second << " = " << multiplied << std::endl;
				break ;
			}
		}
		else
		{
			for (itDatabase; itDatabase->first.month > item->front().first.month; itDatabase){}
			if (item->front().first.month > itDatabase->first.month)
			{
				itDatabase--;
				double multiplied = stod(itDatabase->second) * stod(item->front().second);
				std::cout << item->front().first.date << " => " << item->front().second << " = " << multiplied << std::endl;
				break ;
			}
			else
			{
				for (itDatabase; itDatabase->first.day > item->front().first.day; itDatabase){}
				if (item->front().first.day > itDatabase->first.day)
				{

				}
			}

		}

	}
}