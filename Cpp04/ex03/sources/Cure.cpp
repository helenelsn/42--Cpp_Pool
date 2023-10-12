/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:44:23 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 15:31:58 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure()
:	AMateria("cure")
{
	std::cout << "Cure: Default constructor" << std::endl;
}

Cure::Cure(const Cure& other) 
:	AMateria("cure")
{
	std::cout << "Cure: Copy constructor" << std::endl;
	(void) other;
}

Cure& Cure::operator=(const Cure& other) {
    
	std::cout << "Cure: Assignment operator" << std::endl;
	(void) other;
	return *this;
}

AMateria* Cure::clone() const {

	return (new Cure()); // what else ?
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wound" << " *" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure: Destructor" << std::endl;
}