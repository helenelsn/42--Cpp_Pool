/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:17:43 by Helene            #+#    #+#             */
/*   Updated: 2024/05/29 14:37:48 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <float.h>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <cstring>

typedef struct  s_types {
    double  toDouble;
	float   toFloat;
	long    toInt;
	char    toChar;
}               t_types;

typedef struct  s_valid {
    bool validChar;
    bool validInt;
    bool validFloat;
    bool validDouble;
}               t_valid;

class ScalarConverter
{
    private :
		ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter& other);
        
	public :
        ~ScalarConverter();
        static void convert(std::string const& literal);
        class invalidType : public std::exception {
            public :
                const char * what() const throw() {
                    return "Invalid type";
                }
        };
};

#endif