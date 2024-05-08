/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:18:17 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 19:23:32 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter: Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {

	std::cout << "ScalarConverter: Copy constructor" << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    
	std::cout << "ScalarConverter: Assignment operator" << std::endl;
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter: Destructor" << std::endl;
}



/*
- detect the type of the literal passed as parameter
	-> 	char -> si caractere alphabetique (sinon comment gere les caracteres numeriques)
		! non displayable characters shouldn't be used as inputs
		-> check, and print an error msg accordingly
		sinon : 
			int -> si aucune presence de '.' ni de 'f'
			float -> '.' et 'f' a la fin
			double -> '.' 
- convert it from string to its actual type 
- convert it explicitly to the three other data types
- display the results 
*/
void ScalarConverter::convert(std::string const& literal) {
	
	double toDouble;
	float toFloat;
	int toInt;
	char toChar;
	
	std::string pseudoTypes[6] = 
	{
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	
	// check input length 
	if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
	{
		// is a printable char
		// convert and print converted values, then return
		std::cout << "char : " << literal[0] << std::endl;
		std::cout << "int : " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(literal[0]) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(literal[0]) << ".0" << std::endl;
		return ;
	}


	int i = 0;
	for (; literal != pseudoTypes[i] && i < 6; i++) {} ;
	if (i < 6)
	{
		// pseudoType case
		std::cout << "char : impossible" << std::endl << "int : impossible" << std::endl;
		std::cout << "float : " << pseudoTypes[i % 3] << std::endl;
		std::cout << "double : " << pseudoTypes[(i % 3) + 3] << std::endl;
		return ;
	}
	
	// comment gerer INT_MAX, INT_MIN, FLT_MAX, FLT_MIN, DBL_MAX, DBL_MIN ?

	if (literal.find('.')) // est un double ou un float
	{
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble);
		toInt = static_cast<int>(toDouble);
	}
	else if (literal[literal.length() - 1] == 'f')// est un float
	{
		toFloat = std::atof(literal.c_str());
		toDouble = static_cast<double>(toFloat);
		toInt = static_cast<int>(toFloat);
	}
	else // est un int
	{
		toInt = std::atoi(literal.c_str());
		toFloat = static_cast<float>(toInt);
		toDouble = static_cast<double>(toInt);
	}

	toChar = static_cast<char>(toInt);
	if (!std::isprint(toChar))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << toChar << "'" << std::endl;
	
	
	// print the three remaining values
	std::cout << "int : " << toInt << std::endl;
	std::cout << "float : " << toFloat;
	if (!(toFloat - static_cast<float>(toInt)))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double : " << toDouble;
	if (!toDouble - static_cast<double>(toInt))
		std::cout << ".0" ;
	std::cout << std::endl;
}