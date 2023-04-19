#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>

typedef struct s_data
{
	std::string day;
	std::string month;
	std::string year;


}				t_data;

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> input;
		std::map<std::string, std::string> database;

	public:

		BitcoinExchange();
		BitcoinExchange(std::fstream *fsInput, std::fstream *fsCsv);
		~BitcoinExchange();

		void runExchange();
		std::map<std::string, std::string> createMap(std::fstream *fs, std::string separator);

};

#endif