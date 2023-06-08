#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <list>
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
		std::list<std::pair<t_date, std::string> > input;
		std::list<std::pair<t_date, std::string> > database;

	public:

		BitcoinExchange();
		BitcoinExchange(std::fstream *fsInput, std::fstream *fsCsv);
		BitcoinExchange(const BitcoinExchange& existing);
		~BitcoinExchange();

		void runExchange();
		std::list<std::pair<t_date, std::string> > createMap(std::fstream *fs, std::string separator);
		void findClosest(std::list<std::pair<t_date, std::string> > *item);
		int checkDate(t_date *item);

		std::list<std::pair<t_date, std::string> > getInput() const;
		std::list<std::pair<t_date, std::string> > getDatabase() const;

};

#endif