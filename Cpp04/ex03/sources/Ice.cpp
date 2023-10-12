/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:44:46 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 15:34:10 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(/* args */)
:	AMateria("ice")
{
	std::cout << "Ice: Default constructor" << std::endl;
}

Ice::Ice(const Ice& other)
:	AMateria("ice")
{
	std::cout << "Ice: Copy constructor" << std::endl;
	(void) other;
}

Ice& Ice::operator=(const Ice& other) {
    
	std::cout << "Ice: Assignment operator" << std::endl;
	(void) other;
	return *this;
}

AMateria* Ice::clone() const {

	return (new Ice()); // what else ?
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice: Destructor" << std::endl;
}