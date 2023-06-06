#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>
#include <iostream>
#include <fstream>

typedef struct s_date
{
	std::string date;
	int year;
	int month;
	int day;
}		t_date;

class BitcoinExchange
{
	private:
		std::vector<std::pair<t_date, std::string> > input;
		std::vector<std::pair<t_date, std::string> > database;

	public:

		BitcoinExchange();
		BitcoinExchange(std::fstream *fsInput, std::fstream *fsCsv);
		~BitcoinExchange();

		void runExchange();
		std::vector<std::pair<t_date, std::string> > createMap(std::fstream *fs, std::string separator);
		void findClosest(std::vector<std::pair<t_date, std::string> > *item);
		int checkDate(t_date *item);

};

#endif