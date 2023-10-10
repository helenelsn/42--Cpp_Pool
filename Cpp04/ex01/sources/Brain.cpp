/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:01:01 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/10 20:01:07 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(/* args */)
{
	std::cout << "Brain: Default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {

	std::cout << "Brain: Copy constructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    
	std::cout << "Brain: Assignment operator" << std::endl;
	return *this;
}

Brain::~Brain()
{
    std::cout << "Brain: Destructor" << std::endl;
}