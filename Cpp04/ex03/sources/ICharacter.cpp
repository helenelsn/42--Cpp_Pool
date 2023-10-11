/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:59:30 by Helene            #+#    #+#             */
/*   Updated: 2023/10/11 17:53:57 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "ICharacter: Default constructor" << std::endl;
}

ICharacter::ICharacter(const ICharacter& other) {

	std::cout << "ICharacter: Copy constructor" << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter& other) {
    
	std::cout << "ICharacter: Assignment operator" << std::endl;
	return *this;
}

ICharacter::~ICharacter() {
    std::cout << "ICharacter: Destructor" << std::endl;
}