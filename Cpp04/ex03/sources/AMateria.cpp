/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:08:48 by Helene            #+#    #+#             */
/*   Updated: 2023/10/11 17:39:02 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(/* args */)
{
	std::cout << "AMateria: Default constructor" << std::endl;
}

AMateria::AMateria(std::string const & type)
:	_type(type)
{
	std::cout << "AMateria: Constructor" << std::endl;
}

std::string const & AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void) target;
}


AMateria::AMateria(const AMateria& other) {

	std::cout << "AMateria: Copy constructor" << std::endl;
	(void) other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    
	std::cout << "AMateria: Assignment operator" << std::endl;
	(void) other;
	return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria: Destructor" << std::endl;
}