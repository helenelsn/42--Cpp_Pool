/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:00:35 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 17:46:01 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
:   ClapTrap(name, (unsigned int)100, (unsigned int)50, (unsigned int)20)
{
    std::cout << "Constructor of ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& to_copy)
:   ClapTrap(to_copy)
{
    std::cout << "Copy constructor of ScavTrap called" << std::endl;
}

ScavTrap ScavTrap::operator=(ScavTrap const& to_copy)
{
    this->ClapTrap::operator=(to_copy);
    // this->_name = to_copy._name;
    // this->_attackDamage = to_copy._attackDamage;
    // this->_energyPoints = to_copy._energyPoints;
    // this->_hitPoints = to_copy._hitPoints;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (!_hitPoints || !_energyPoints)
        return ;

   std::cout << "ScavTrap " << _name <<  " attacks " << target;
   std::cout <<  ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "Scav trap " << _name << " is now in Gate keeper mode " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor of ScavTrap called" << std::endl;
}