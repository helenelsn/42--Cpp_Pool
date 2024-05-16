/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:17:43 by Helene            #+#    #+#             */
/*   Updated: 2024/05/16 01:33:42 by Helene           ###   ########.fr       */
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
	public :
		ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter& other);
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