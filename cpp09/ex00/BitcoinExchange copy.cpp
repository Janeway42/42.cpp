#include "BitcoinExchange.hpp"

// ------------ Constructors & Destructors ------------

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::fstream *fsInput, std::fstream *fsCsv)
{
	database = createMap(fsCsv, ",");
	input = createMap(fsInput, "|");
	// std::cout << "-------------------------- print Input Constructor ---------------------------------\n";
	// for (std::list<std::pair<std::string, std::string> >::iterator it = input.begin(); it != input.end(); it++)
	// {
	// 	std::cout << "itInput->first: " << it->first << " itInput->second: " << it->second << std::endl;
	// }
	// std::cout << "-------------------------- print Input ---------------------------------\n\n\n";
}

BitcoinExchange::~BitcoinExchange(){}

// ------------ other functions ------------

void BitcoinExchange::runExchange()
{
	std::list<std::pair<t_date, std::string> >::iterator itInput;
	std::list<std::pair<t_date, std::string> >::iterator itDatabase;

	// std::cout << "-------------------------- print Input ---------------------------------\n";
	// for (std::list<std::pair<std::string, std::string> >::iterator it = input.begin(); it != input.end(); it++)
	// {
	// 	std::cout << "itInput->first: " << it->first << " itInput->second: " << it->second << std::endl;
	// }
	// std::cout << "-------------------------- print Input ---------------------------------\n";

	for (itInput = input.begin(); itInput != input.end(); itInput++)
	{
		if (itInput->second != "") //  || itInput->first.date != ""
		{
			try
			{
				// A valid value must be either a float or a positive integer between 0 and 1000.
				double quantity = stod(itInput->second);
				if (quantity > INT_MAX)
					std::cout << "Error: too large a number." << std::endl;
				else if (quantity < 0)
					std::cout << "Error: not a positive number.\n";
				else
				{
					for(itDatabase = database.begin(); itDatabase != database.end(); itDatabase++)
					{
						if (itInput->first.date == itDatabase->first.date)
						{
							double multiplied = stod(itDatabase->second) * quantity;
							std::cout << itInput->first.date << " => " << itInput->second << " = " << multiplied << std::endl;
							break ;
						}
					}
					if (itDatabase == database.end())
					{
						// std::cout << "checkdate item->date " << itInput->first.year << " amount: " << itInput->second << std::endl;

						// std::cout << "checkDate " << checkDate(&(itInput->first)) << std::endl;
						if (checkDate(&(itInput->first)) == 1)
							std::cout << "Error: Invalid date\n";
						else 
						{
							std::listr<std::pair<t_date, std::string> > temp;
							temp.push_back(make_pair(itInput->first, itInput->second));
							findClosest(&temp);
						}

					}
				}
			}
			catch(const std::exception& e)
			{
				std::cout << "Failed stod.\n";
			}
		}
		else
		{
			std::cout << "Error bad input => ";
			if (itInput->first.date != "")       // necessary ????????????????
				std::cout << itInput->first.date;
			std::cout << std::endl;
		}
		// std::cout << "next\n\n";
	}
}



void BitcoinExchange::findClosest(std::list<std::pair<t_date, std::string> > *item)
{
	std::list<std::pair<t_date, std::string> >::iterator itDatabase = database.begin();	

	for (; itDatabase != database.end() && itDatabase->first.year <= item->front().first.year; itDatabase++){
		if (item->front().first.year == itDatabase->first.year)
		{
			// std::cout << "break: itDatabase->date " << itDatabase->first.year << " | " << itDatabase->first.month << " | " << itDatabase->first.day << " amount: " << itDatabase->second << std::endl;
			// std::cout << "break: item->date " << item->front().first.date << " amount: " << item->front().second << std::endl;

			break ;
		}
	}
	if (itDatabase == database.begin())
	{
		std::cout << "ERROR\n";
		return ;
	}
	else if (itDatabase == database.end())
	{
		itDatabase--;
		double multiplied = stod(itDatabase->second) * stod(item->front().second);
		// std::cout << "itDatabase->date " << itDatabase->first.date << " amount: " << itDatabase->second << std::endl;
		std::cout << item->front().first.date << " ====> " << item->front().second << " = " << multiplied << std::endl;
		return ;
	}
	else if (itDatabase->first.year > item->front().first.year)
	{
		itDatabase--;
		double multiplied = stod(itDatabase->second) * stod(item->front().second);
		// std::cout << "itDatabase->date " << itDatabase->first.date << " amount: " << itDatabase->second << std::endl;
		std::cout << item->front().first.date << " ====> " << item->front().second << " = " << multiplied << std::endl;
		return ;
	}
	else
	{
		// std::cout << "findClosest\n";
		for(;itDatabase->first.year == item->front().first.year; itDatabase++)
		{
			if (itDatabase->first.month == item->front().first.month)
			{
				for (;itDatabase->first.month == item->front().first.month; itDatabase++)
				{
					if (itDatabase->first.day > item->front().first.day)
					{
						itDatabase--;
						// std::cout << "itDatabase->date " << itDatabase->first.date << " amount: " << itDatabase->second << std::endl;
						double multiplied = stod(itDatabase->second) * stod(item->front().second);
						std::cout << item->front().first.date << " ====> " << item->front().second << " = " << multiplied << std::endl;
						return ;
					}
				}
			}
			else if (itDatabase->first.month >= item->front().first.month)
			{
				itDatabase--;
				// std::cout << "itDatabase->date " << itDatabase->first.date << " amount: " << itDatabase->second << std::endl;
				double multiplied = stod(itDatabase->second) * stod(item->front().second);
				std::cout << item->front().first.date << " ====> " << item->front().second << " = " << multiplied << std::endl;
				return ;
			}
		}
	}
}

std::list<std::pair<t_date, std::string> > BitcoinExchange::createMap(std::fstream *fs, std::string separator)
{
	std::string buffer;
	std::list <std::pair<t_date, std::string> > dest;

	getline((*fs), buffer);
	while (!(*fs).eof())
	{
		getline((*fs), buffer);
		if (buffer != "")
		{
			t_date temp;
			temp.year = -55;
			temp.month = -55;
			temp.day = -55;
			std::string val;
			size_t out;
			
			out = buffer.find(separator);
			// std::cout << "out: " << out << std::endl;
			temp.date = buffer.substr(0, out);

			int len = 0;		
			for (int i = temp.date.length(); temp.date[i - 1] == ' '; i--){
				len++;}
			temp.date = temp.date.substr(0, temp.date.length() - len);
			try 
			{
				temp.year = stoi(temp.date.substr(0,4));
				temp.month = stoi(temp.date.substr(5,7));
				temp.day = stoi(temp.date.substr(8,10));
			}
			catch(std::invalid_argument const& ex)
			{
				// std::cout << "#1: " << ex.what() << '\n';
			}


			if (out == std::string::npos)
				val = "";
			else
				val = buffer.substr(out + 1);
			// std::cout << "val: " << val << ",\n\n";

			dest.push_back(make_pair(temp, val));
		}
	}

	// std::cout << "-------------------------- print Input createMap ---------------------------------\n";
	// for (std::list<std::pair<std::string, std::string> >::iterator it = dest.begin(); it != dest.end(); it++)
	// {
	// 	std::cout << "itInput->first: " << it->first << " itInput->second: " << it->second << std::endl;
	// }
	// std::cout << "-------------------------- print Input ---------------------------------\n\n\n";
	return (dest);
}


int BitcoinExchange::checkDate(t_date *item)
{
	if ((*item).year == -55 || (*item).month == -55 || (*item).day == -55)
		return (1);
	if ((*item).month < 1 || (*item).month > 12)
		return (1);
	if ((*item).day < 1 || (*item).day > 31)
		return (1);
	return (0);
}