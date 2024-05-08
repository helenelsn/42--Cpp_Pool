/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:17:43 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 17:22:22 by Helene           ###   ########.fr       */
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
        virtual ~ScalarConverter();
        static void convert(std::string const& literal);
};

#endif