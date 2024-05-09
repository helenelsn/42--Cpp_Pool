/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:20:28 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/06 16:12:39 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor" << std::endl;
    _type = "Dog";
    // _brain = new Brain;
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog: Copy constructor" << std::endl;
    _type = other._type;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog: Assignment operator" << std::endl;
    _type = other._type;
	return *this;
}

void    Dog::makeSound(void) const
{
    std::cout << "Wouf" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor" << std::endl;
    // delete _brain;
}