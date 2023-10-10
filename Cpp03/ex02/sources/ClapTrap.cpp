/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:38:25 by Helene            #+#    #+#             */
/*   Updated: 2023/10/10 16:22:43 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hit = 10, unsigned int energy = 10, unsigned int attack = 10)
 :  _name(name),
    _hitPoints(hit),
    _energyPoints(energy),
    _attackDamage(attack)
{
    std::cout << "Constructor of ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& to_copy)
{
    std::cout << "Copy constructor of ClapTrap called" << std::endl;
    *this = to_copy;
}

ClapTrap    ClapTrap::operator=(ClapTrap const& to_copy)
{
    this->_name = to_copy._name;
    this->_attackDamage = to_copy._attackDamage;
    this->_energyPoints = to_copy._energyPoints;
    this->_hitPoints = to_copy._hitPoints;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (!_hitPoints || !_energyPoints)
        return ;
   
   _energyPoints--;

   std::cout << "ClapTrap " << _name <<  " attacks " << target;
   std::cout <<  ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{   
    if (amount > _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    
    std::cout << "ClapTrap " << _name << " took some damages.";
    std::cout << "It now has " << _hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!_hitPoints || !_energyPoints)
        return ;
    
    _hitPoints += amount;
    _energyPoints--;

    std::cout << "ClapTrap " << _name << " repaired itself.";
    std::cout << "It now has " << _hitPoints << " hit points." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor of ClapTrap called" << std::endl;
}