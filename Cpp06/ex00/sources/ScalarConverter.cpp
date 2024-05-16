/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:18:17 by Helene            #+#    #+#             */
/*   Updated: 2024/05/16 02:02:28 by Helene           ###   ########.fr       */
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



void checkRanges(std::string const & input, t_valid &valid) 
{
	double n = std::strtod(input.c_str(), 0);
	if (n < - std::numeric_limits<double>::max() || n > std::numeric_limits<double>::max())
		valid.validDouble = false;
	if (n < - std::numeric_limits<float>::max() || n > std::numeric_limits<float>::max())
		valid.validFloat = false;
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		valid.validInt = false;
}

bool checkChar(std::string const& input, t_types &types) 
{
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		types.toChar = input[0];
		types.toInt = static_cast<int>(input[0]);
		types.toFloat = static_cast<float>(input[0]);
		types.toDouble = static_cast<double>(input[0]);
		return true ;
	}
	return false;
}

bool checkInt(std::string const& input, t_types &types, t_valid &valid) 
{
	size_t i = 0;
	for (; i < input.size(); i++)
	{
		if (i == 0 && input[i] == '-')
			continue ;
		if (!isdigit(input[i]))
			return false ;
	}
			
	checkRanges(input, valid);
	types.toInt = static_cast<int>(std::atoi(input.c_str()));
	types.toFloat = static_cast<float>(std::atof(input.c_str()));
	types.toDouble = static_cast<double>(std::strtod(input.c_str(), 0));

	return true ;
}

bool checkFloat(std::string const& input, t_types &types, t_valid &valid)
{
	if (input.find('f') == input.length() - 1)
	{		
		checkRanges(input, valid);
		types.toFloat = std::atof(input.c_str());
		types.toDouble = static_cast<double>(types.toFloat);
		types.toInt = static_cast<int>(types.toFloat);
		return true ;
	}
	return false ;
}

bool checkDouble(std::string const& input, t_types &types, t_valid &valid)
{
	if (input.find('.') != std::string::npos) // est un double ou un float
	{		
		checkRanges(input, valid);
		types.toDouble = std::strtod(input.c_str(), 0);
		types.toFloat = static_cast<float>(types.toDouble);
		types.toInt = static_cast<int>(types.toDouble);
		return true ;
	}
	return false ;
}

bool isPseudoType(std::string const& input)
{
	std::string pseudoTypes[6] = 
	{
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};

	int i = 0;
	for (; input != pseudoTypes[i] && i < 6; i++) {} ;
	if (i < 6)
	{
		std::cout << "char : impossible" << std::endl << "int : impossible" << std::endl;
		std::cout << "float : " << pseudoTypes[i % 3] << std::endl;
		std::cout << "double : " << pseudoTypes[(i % 3) + 3] << std::endl;
		return true ;
	}
	return false;
}

void printConvertedValues(t_types &types, t_valid &valid)
{
	types.toChar = static_cast<char>(types.toInt);
	if (types.toInt < 0 || types.toInt > 127 || !std::isprint(types.toChar)) // a checker
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << types.toChar << "'" << std::endl;
	
	
	if (valid.validInt)
		std::cout << "int : " << types.toInt << std::endl;
	else
		std::cout << "int : impossible : would overflow" << std::endl;
	if (valid.validFloat) 
	{
		std::cout << "float : " << types.toFloat;
		if (!(types.toFloat - static_cast<float>(types.toInt)))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	else
		std::cout << "float : impossible : would overflow" << std::endl;
	if (valid.validDouble) 
	{
		std::cout << "double : " << types.toDouble;
		if (!types.toDouble - static_cast<long long>(types.toDouble))
			std::cout << ".0" ;
		std::cout << std::endl;
	}
	else
		std::cout << "double : impossible : would overflow" << std::endl;
}

bool checkType(std::string const &input, t_types &types, t_valid &valid)
{
	if (!input.size())
		throw ScalarConverter::invalidType();
	if (isPseudoType(input))
		return false ;
	if (!checkChar(input, types)
		&& !checkDouble(input, types, valid)
		&& !checkFloat(input, types, valid)
		&& !checkInt(input, types, valid))
		throw ScalarConverter::invalidType();
	return true ;
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
void ScalarConverter::convert(std::string const& literal)
{
	t_types types;
	t_valid valid;
	memset(&types, 0, sizeof(t_types));
	
	memset(&valid, true, sizeof(t_valid)); // true : marche ?
	// valid.validChar = true;
	// valid.validDouble = true;
	// valid.validFloat = true;
	// valid.validInt = true;
		

	try {
		if (!checkType(literal, types, valid))
			return ;
		printConvertedValues(types, valid);
	}
	catch (ScalarConverter::invalidType &e) {
		std::cerr << e.what() << std::endl;
		return ;
	}
}