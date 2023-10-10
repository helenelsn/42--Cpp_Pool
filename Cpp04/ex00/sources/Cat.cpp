/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:08:14 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/10 19:10:59 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Default constructor" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat& other) {
    _type = other._type;
	std::cout << "Cat: Copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat: Assignment operator" << std::endl;
    _type = other._type;
	return *this;
}

void    Cat::makeSound(void) const
{
    std::cout << "meow" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor" << std::endl;
}