/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:17:43 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 18:53:09 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <float.h>
#include <limits.h>
#include <cctype>
#include <cstdlib>

class ScalarConverter
{
    protected :
        /* Data */
    
    private :
        /* Data */

	public :
		ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static void convert(std::string const& literal);
};

#endif