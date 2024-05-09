/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:24:33 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/06 16:20:42 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "Wrong cat";
	std::cout << "WrongCat: Default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {

	std::cout << "WrongCat: Copy constructor" << std::endl;
	_type = other.getType();
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    
	std::cout << "WrongCat: Assignment operator" << std::endl;
	_type = other.getType();
	return *this;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "wrong meow" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor" << std::endl;
}