/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:38:25 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 17:38:11 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
 :  _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(10)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& to_copy)
{
    std::cout << "Copy constructor called" << std::endl;
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
    {
        std::cerr << "No hit points or energy points left!" << std::endl;
        return ;
    }
   
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
    std::cout << " It now has " << _hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!_hitPoints || !_energyPoints)
    {
        std::cerr << "No hit points or energy points left!" << std::endl;
        return ;
    }
    
    _hitPoints += amount;
    _energyPoints--;

    std::cout << "ClapTrap " << _name << " repaired itself.";
    std::cout << " It now has " << _hitPoints << " hit points." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}