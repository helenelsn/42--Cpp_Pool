/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:08:14 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/10 23:55:14 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Default constructor" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& other) {
    
    if (_brain)
        delete _brain; // ?
    _brain = new Brain();
    *_brain = *(other._brain);
    _type = other._type;
	std::cout << "Cat: Copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat: Assignment operator" << std::endl;
    if (_brain)
        delete _brain; // ?
    _brain = new Brain();
    *_brain = *(other._brain);
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
    delete _brain;
}