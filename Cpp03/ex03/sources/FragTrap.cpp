/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:41:54 by Helene            #+#    #+#             */
/*   Updated: 2023/10/10 16:31:24 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap()
:   ClapTrap((std::string)"default_frag_trap", 100, 100, 30)
{
    std::cout << "Default constructor of FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string name)
:   ClapTrap(name, 100, 100, 30)
{
    std::cout << "Constructor of FragTrap called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& to_copy)
:   ClapTrap(to_copy)
{
    std::cout << "Copy constructor of FragTrap called" << std::endl;
}

FragTrap FragTrap::operator=(FragTrap const& to_copy)
{
    // y a t il un moyen d'appeler la surcharge d'op de la classe parente ?
    this->_name = to_copy._name;
    this->_attackDamage = to_copy._attackDamage;
    this->_energyPoints = to_copy._energyPoints;
    this->_hitPoints = to_copy._hitPoints;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Scat trap " << _name << " wishes to do a high fives" << std::endl;
}

FragTrap::~FragTrap()
{
    this->ClapTrap::~ClapTrap();
    std::cout << "Destructor of FragTrap called" << std::endl;
}