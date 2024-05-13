/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:33:06 by Helene            #+#    #+#             */
/*   Updated: 2024/05/14 00:19:48 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>

#define DATABASE        "data.csv"
#define DATABASE_FORMAT ".csv"

class BitcoinExchange
{   
    private :
        std::map<std::string, float> _dataBase; // dataBase
        void printDataBase(void) const;

	public :
		BitcoinExchange(void); // passer le fichier .csv en argument plutot
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        
        void printCurrencyValue(std::pair<std::string,  float> line) const;
        void getCurrencyValues(std::string input) const;
        
        class numberTooLarge : public std::exception {
            public :
                const char *what() const throw() {
                    return "too large a number.";
                }
        };
        class notAPositiveNumber : public std::exception {
            public :
                const char *what() const throw() {
                    return "not a positive number.";
                }
        };
        class invalidFormat : public std::exception {
            public : 
                const char *what() const throw() {
                    return "not in the \"date | value\" format.";
                }
        };
        class invalidDate : public std::exception {
            private :
                std::string _errorMsg;
            public : 
                invalidDate(std::string input) : _errorMsg("bad input => " + input) {}
                ~invalidDate() throw() {}
                const char *what() const throw() {
                    return _errorMsg.c_str();
                }
        };
        class notANumber : public std::exception {
            public : 
                const char *what() const throw() {
                    return "value is not a number.";
                }
        };
        class fileIssue : public std::exception {
            public :
                const char *what() const throw() {
                    return "invalid input file.";
                }
        };
};

#endif