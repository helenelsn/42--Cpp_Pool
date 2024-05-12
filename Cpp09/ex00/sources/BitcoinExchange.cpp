/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:42:26 by Helene            #+#    #+#             */
/*   Updated: 2024/05/12 16:41:35 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

// une année est bissextile si elle est divisible par 4 ET n'est pas divisible par 100, ou alors est divisible par 400
bool	isLapYear(int year)
{
	if (year % 4)
		return false;
	if (year % 100)
		return true;
	if (year % 400 == 0)
		return true;
	return false;
}

// encore 2-3 checks a faire sur cette fonction
void	checkDateFormat(std::string line)
{
	if (line.size() != 10 || line[4] != '-' || line [7] != '-') // line.size() != 11 ?
		throw BitcoinExchange::invalidFormat(); // a verif
	
	std::string year, month, day;
	std::istringstream data(line);
	std::getline(data, year, '-');
	std::getline(data, month, '-');
	std::getline(data, day); // '\n'
	
	if (year.size() != 4 || month.size() != 2 || day.size() != 2)
		throw BitcoinExchange::invalidDate(line);

	int iyear = std::stoi(year);
	int imonth = std::stoi(month);
	int iday = std::stoi(day);
	// check is year is < 0 ? miskine les gens nés avant jesus
	if (iyear > 2024 || imonth > 12|| imonth < 0 || iday > 31 || iday < 0
		|| (!(imonth % 2) && iday == 31) || (imonth == 2 && isLapYear(iyear) && iday > 28))
		throw BitcoinExchange::invalidDate(line);
}

void	checkValueFormat(std::string line)
{
	if (!line.size())
		throw BitcoinExchange::invalidFormat();
	if (line.find_first_not_of("0123456789.-") != std::string::npos)
		throw BitcoinExchange::notANumber();
	
	float value = std::stof(line);
	if (value < 0)
		throw BitcoinExchange::notAPositiveNumber();
	if (std::stol(line) > 1000)
		throw BitcoinExchange::numberTooLarge();
}

void	checkDBFileFormat(std::string fileName, std::ifstream &db, std::string format) {
	size_t pos = fileName.find(format);
	
	if (pos == std::string::npos || fileName.find(format, pos + 1) != std::string::npos)
		throw BitcoinExchange::fileIssue();
	
	db.open(DATABASE);
	if (!db.is_open())
		throw BitcoinExchange::fileIssue();
}


BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange: Default constructor" << std::endl;

	std::ifstream databaseFile;
	
	checkDBFileFormat(DATABASE, databaseFile, DATABASE_FORMAT);
	std::string line, date, value;
	
	// parse the .csv file and update the _dataBase
	getline(databaseFile, line); // skip the first line
	while (getline(databaseFile, line))
	{
		std::istringstream lineStream(line);
		std::getline(lineStream, date, ',');
		std::getline(lineStream, value); 
		_dataBase[date] = std::atof(value.c_str());
	}    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {

	std::cout << "BitcoinExchange: Copy constructor" << std::endl;
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    
	std::cout << "BitcoinExchange: Assignment operator" << std::endl;
	_dataBase = other._dataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange: Destructor" << std::endl;
}





void BitcoinExchange::printCurrencyValue(std::pair<std::string, float> line) const {
	std::map<std::string, float> db = _dataBase; // sinon les const me prennent la tete 
	std::map<std::string, float>::iterator it_pos = db.lower_bound(line.first);
	
	if (it_pos != db.begin() && db.find(line.first) == db.end())
		it_pos--;
	std::cout << line.first << " => " << line.second << " = " << line.second * (it_pos->second) << std::endl;
}

void BitcoinExchange::printDataBase(void) const {
	// POURQUOI WESH
	std::map<std::string, float> db = _dataBase;
	
	std::cout << "data base : " << std::endl;
	for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); it++)
		std::cout << it->first << "," << it->second << std::setprecision(7) << std::endl;
	std::cout << std::endl;
}

void BitcoinExchange::getCurrencyValues(std::string input) const {
	
	std::ifstream inputFile(input);
	if (!inputFile.is_open())
	{
		std::cout << "eh merde, pas l'input file" << std::endl;
		return ; // throw exception 
	}

	// this->printDataBase();

	std::string line, date, value;
	while (getline(inputFile, line))
	{
		if (line == "date | value")
			continue;
			try {
				size_t pos = line.find('|');
				date = line.substr(0, pos - 1);
				checkDateFormat(date);
				if (pos == std::string::npos)
					throw BitcoinExchange::invalidFormat(); 
				value = line.substr(pos + 2);
				checkValueFormat(value);
				
				std::pair<std::string, float> toConvert(date, std::stof(value.substr()));
				printCurrencyValue(toConvert);
				
			}
			catch (std::exception &e) {
				std::cerr << "Error : " << e.what() << std::endl;
			}
	}
	
}