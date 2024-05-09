/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:08:14 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/06 17:17:14 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Default constructor" << std::endl;
    _type = "Cat";
    _brain = new Brain();
    // _brain = NULL; // ?
}

Cat::Cat(const Cat& other) 
{    
	std::cout << "Cat: Copy constructor" << std::endl;
    if (_brain)
        delete _brain; // ?
    _brain = new Brain();
    *_brain = *(other._brain);
    _type = other._type;
}

Cat& Cat::operator=(const Cat& other)
{
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

void    Cat::addIdea(std::string newIdea)
{
    _brain->addIdea(newIdea);
}

void    Cat::printIdeas(void) const
{
    std::cout << "Ideas inside a " << _type << "'s brain : " << std::endl;
    _brain->printIdeas();
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor" << std::endl;
    delete _brain;
}