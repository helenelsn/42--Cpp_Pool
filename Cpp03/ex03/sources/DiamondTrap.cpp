/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:48:18 by Helene            #+#    #+#             */
/*   Updated: 2024/02/05 22:25:53 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/* le soin d’initialiser les super-classes virtuelles incombe à la sous-classe la plus
dérivée */
DiamondTrap::DiamondTrap(std::string name)
:   ClapTrap(name + "_clap_trap", 100, 50, 30),
    ScavTrap(),
    FragTrap(),
    _name(name)
{
    std::cout << "Constructor of DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& to_copy)
:   ClapTrap(to_copy),
    _name(to_copy._name)
{
    std::cout << "Copy constructor of DiamondTrap called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const& to_copy)
{
    this->ClapTrap::operator=(to_copy);
    this->_name = to_copy._name;
    // this->_attackDamage = to_copy._attackDamage;
    // this->_energyPoints = to_copy._energyPoints;
    // this->_hitPoints = to_copy._hitPoints;
    return (*this);
}

void    DiamondTrap::WhoAmI(void)
{
    std::cout << "My name is : " << getName();
    std::cout << ", and my ClapTrap name is : " << ClapTrap::getName() << std::endl;
    std::cout << "I have " << _hitPoints << " hit points, " << _energyPoints << " energy points, and " << _attackDamage << " damage points" << std::endl;
}

std::string DiamondTrap::getName() const
{
    return (DiamondTrap::_name);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor of DiamondTrap called" << std::endl;
}