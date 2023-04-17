#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>

typedef struct s_date
{
	std::string day;
	std::string month;
	std::string year;
}				t_date;

class BitcoinExchange
{
	private:
		std::map<t_date, double> input;
		std::map<t_date, double> database;

	public:

		BitcoinExchange();
		BitcoinExchange(std::fstream *fsInput, std::fstream *fsCsv);
		~BitcoinExchange();

		void runExchange();

};

#endif