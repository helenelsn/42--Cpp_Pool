/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:06:15 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/11 00:12:38 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal: Default constructor" << std::endl;
    _type = "Animal";
}

Animal::Animal(const Animal& other) {
    _type = other._type;
	std::cout << "Animal: Copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal: Assignment operator" << std::endl;
    _type = other._type;
	return *this;
}

void    Animal::makeSound(void) const
{
    std::cout << "animal sound" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor" << std::endl;
}

std::string Animal::getType(void) const{
    return (_type);
}
