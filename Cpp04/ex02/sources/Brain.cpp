/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:01:01 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/10 23:48:59 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(/* args */)
:	_ideasCount(0)
{
	std::cout << "Brain: Default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {

	std::cout << "Brain: Copy constructor" << std::endl;
	std::copy(other._ideas, other._ideas + 100, this->_ideas);
	_ideasCount = other._ideasCount;
}

Brain& Brain::operator=(const Brain& other) {
    
	std::cout << "Brain: Assignment operator" << std::endl;
	std::copy(other._ideas, other._ideas + 100, this->_ideas);
	_ideasCount = other._ideasCount;
	return *this;
}

void	Brain::addIdea(std::string newIdea)
{
	if (_ideasCount == 100)
	{
		std::cout << "Brain is full : must delete an idea before adding a new one." << std::endl;
		return ;
	}
	_ideas[_ideasCount] = newIdea;
	_ideasCount++;
}

void Brain::printIdeas(void)
{
	for (size_t i = 0; i < _ideasCount; i++)
		std::cout << "Idea " << i << " : " << _ideas[i] << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain: Destructor" << std::endl;
}