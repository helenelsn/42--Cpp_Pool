/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:06:15 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/11 00:11:35 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A_Animal.hpp"

A_Animal::A_Animal()
{
	std::cout << "A_Animal: Default constructor" << std::endl;
    _type = "A_Animal";
}

A_Animal::A_Animal(const A_Animal& other) {
    _type = other._type;
	std::cout << "A_Animal: Copy constructor" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal& other) {
	std::cout << "A_Animal: Assignment operator" << std::endl;
    _type = other._type;
	return *this;
}

A_Animal::~A_Animal()
{
    std::cout << "A_Animal: Destructor" << std::endl;
}

std::string A_Animal::getType(void) const{
    return (_type);
}
