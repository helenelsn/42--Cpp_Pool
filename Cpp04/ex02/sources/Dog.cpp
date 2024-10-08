/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:20:28 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/10 22:42:10 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor" << std::endl;
    _type = "Dog";
    _brain = new Brain;
}

Dog::Dog(const Dog& other) {
    _type = other._type;
    delete _brain;
    _brain = new Brain;
    *_brain = *(other._brain);
	std::cout << "Dog: Copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog: Assignment operator" << std::endl;
    delete _brain;
    _brain = new Brain;
    *_brain = *(other._brain);
    _type = other._type;
	return *this;
}

void    Dog::makeSound(void) const
{
    std::cout << "waf" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor" << std::endl;
    delete _brain;
}