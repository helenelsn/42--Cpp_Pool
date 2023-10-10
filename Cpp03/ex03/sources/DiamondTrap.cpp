/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:48:18 by Helene            #+#    #+#             */
/*   Updated: 2023/10/10 16:47:49 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/* le soin d’initialiser les super-classes virtuelles incombe à la sous-classe la plus
dérivée */
DiamondTrap::DiamondTrap(std::string name)
:   ClapTrap(name + "_clap_trap"),
    ScavTrap(name + "_clap_trap"),
    FragTrap(name + "_clap_trap"),
    _name(name)
{
    _attackDamage = 30;
    _energyPoints = 100; /* y a pas une meilleure maniere de faire ? */
    std::cout << "Constructor of DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& to_copy)
:   ClapTrap(to_copy)
{
    std::cout << "Copy constructor of DiamondTrap called" << std::endl;
}

DiamondTrap DiamondTrap::operator=(DiamondTrap const& to_copy)
{
    // y a t il un moyen d'appeler la surcharge d'op de la classe parente ?
    // Après de multiple test, je n'ai pas trouver comment faire et internet semble relativement d'accord avec moi. Tendrement, Aurèle
    this->_name = to_copy._name;
    this->_attackDamage = to_copy._attackDamage;
    this->_energyPoints = to_copy._energyPoints;
    this->_hitPoints = to_copy._hitPoints;
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
   ScavTrap::attack(target);
}

void    DiamondTrap::WhoAmI(void)
{
    std::cout << "My name is : " << _name;
    std::cout << ", and my ClapTrap name : " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    this->ClapTrap::~ClapTrap();
    std::cout << "Destructor of DiamondTrap called" << std::endl;
}