/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:24:39 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/06 16:13:00 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
:	_type("Wrong animal")
{
	std::cout << "WrongAnimal: Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {

	std::cout << "WrongAnimal: Copy constructor" << std::endl;
	_type = other.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    
	std::cout << "WrongAnimal: Assignment operator" << std::endl;
	this->_type = other.getType();
	return *this;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const{
    return (_type);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor" << std::endl;
}