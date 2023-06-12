#include "BitcoinExchange.hpp"

// ------------ Constructors & Destructors ------------

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::fstream *fsInput, std::fstream *fsCsv)
{
	database = createMap(fsCsv, ",");
	input = createMap(fsInput, "|");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &existing): input(existing.getInput()), database(existing.getDatabase())
{
}

BitcoinExchange& BitcoinExchange:: operator = (const BitcoinExchange &existing)
{
	if (this != &existing)
	{
		for (std::list<std::pair<t_date, std::string> >::iterator it = existing.getInput().begin(); it != existing.getInput().end(); it++)
			input.push_back(make_pair(it->first, it->second));
		for (std::list<std::pair<t_date, std::string> >::iterator it = existing.getDatabase().begin(); it != existing.getDatabase().end(); it++)
			database.push_back(make_pair(it->first, it->second));
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

// ------------ other functions ------------

void BitcoinExchange::runExchange()
{
	std::list<std::pair<t_date, std::string> >::iterator itInput;
	std::list<std::pair<t_date, std::string> >::iterator itDatabase;

	for (itInput = input.begin(); itInput != input.end(); itInput++)
	{
		if (itInput->second != "" && itInput->first.date != "")
		{
			try
			{
				double quantity = stod(itInput->second);
				if (quantity > INT_MAX || quantity > 1000)
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
						if (checkDate(&(itInput->first)) == 1)
							std::cout << "Error: Invalid date\n";
						else 
						{
							std::list<std::pair<t_date, std::string> > temp;
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
			if (itInput->first.date != "")
				std::cout << itInput->first.date;
			std::cout << std::endl;
		}
	}
}

void BitcoinExchange::findClosest(std::list<std::pair<t_date, std::string> > *item)
{
	std::list<std::pair<t_date, std::string> >::iterator itDatabase = database.begin();	

	for (; itDatabase != database.end() && itDatabase->first.year <= item->front().first.year; itDatabase++){
		if (item->front().first.year == itDatabase->first.year)
			break ;
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
		std::cout << item->front().first.date << " ====> " << item->front().second << " = " << multiplied << std::endl;
		return ;
	}
	else if (itDatabase->first.year > item->front().first.year)
	{
		itDatabase--;
		double multiplied = stod(itDatabase->second) * stod(item->front().second);
		std::cout << item->front().first.date << " ====> " << item->front().second << " = " << multiplied << std::endl;
		return ;
	}
	else
	{
		for(;itDatabase->first.year == item->front().first.year; itDatabase++)
		{
			if (itDatabase->first.month == item->front().first.month)
			{
				for (;itDatabase->first.month == item->front().first.month; itDatabase++)
				{
					if (itDatabase->first.day > item->front().first.day)
					{
						itDatabase--;
						double multiplied = stod(itDatabase->second) * stod(item->front().second);
						std::cout << item->front().first.date << " ====> " << item->front().second << " = " << multiplied << std::endl;
						return ;
					}
				}
			}
			else if (itDatabase->first.month >= item->front().first.month)
			{
				itDatabase--;
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
			temp.date = buffer.substr(0, out);

			int len = 0;		
			for (int i = temp.date.length(); temp.date[i - 1] == ' '; i--){
				len++;}
			temp.date = temp.date.substr(0, temp.date.length() - len);

			if (temp.date != "")
			{
				try 
				{
					temp.year = stoi(temp.date.substr(0,4));
					temp.month = stoi(temp.date.substr(5,7));
					temp.day = stoi(temp.date.substr(8,10));
				}
				catch(std::invalid_argument const& ex)
				{
					std::cout << ex.what() << '\n';
				}
			}
			if (out == std::string::npos)
				val = "";
			else
				val = buffer.substr(out + 1);
			dest.push_back(make_pair(temp, val));
		}
	}
	return (dest);
}

int BitcoinExchange::checkDate(t_date *item)
{
	int year = (*item).year;
	int month = (*item).month;
	int day = (*item).day;

	if (year == -55 || month == -55 || day == -55)
		return (1);
	if (month < 1 || month > 12)
		return (1);
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
	{
		if (day < 1 && day > 29)
			return (1);
	}
	else if ((month > 8 && month % 2 != 0) || (month < 7 && month % 2 == 0)) // 4 6  9 11
	{
		if (day < 1 || (month == 2 && day > 28) || day > 30)
			return (1);
	}
	else if ((month > 7 && month % 2 == 0) || (month < 8 && month % 2 != 0)) // 1 3 5 7  8 10 12
	{
		if (day < 1 && day > 31)
			return (1);
	}
	return (0);
}

// -----------------------  getters ----------------------

std::list<std::pair<t_date, std::string> > BitcoinExchange::getInput() const
{
	return (input);
}
	
std::list<std::pair<t_date, std::string> > BitcoinExchange::getDatabase() const
{
	return (database);
}
