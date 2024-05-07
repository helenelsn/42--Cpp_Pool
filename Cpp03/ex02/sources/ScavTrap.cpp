/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:00:35 by Helene            #+#    #+#             */
/*   Updated: 2024/02/05 21:34:57 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap()
:   ClapTrap("Default_ScavTrap", 100, 50, 20)
{
    std::cout << "Default constructor of ScavTrap called" << std::endl;
}

// Unless otherwise specified, the constructors of a derived class calls the default constructor of its base classes
ScavTrap::ScavTrap(std::string name)
:   ClapTrap(name, 100, 50, 20)
{
    std::cout << "Constructor of ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& to_copy)
{
    *this = to_copy;
    std::cout << "Copy constructor of ScavTrap called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& to_copy)
{
    this->ClapTrap::operator=(to_copy);
    // this->_name = to_copy._name;
    // this->_attackDamage = to_copy._attackDamage;
    // this->_energyPoints = to_copy._energyPoints;
    // this->_hitPoints = to_copy._hitPoints;
    std::cout << "Copy assignment constructor of ScavTrap called" << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (!_hitPoints || !_energyPoints)
    {
        std::cerr << _name << " cannot attack : it has no hit points or energy points left!" << std::endl;
        return ;
    }

   std::cout << "ScavTrap " << this->getName() <<  " attacks " << target;
   std::cout <<  ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor of ScavTrap called" << std::endl;
}