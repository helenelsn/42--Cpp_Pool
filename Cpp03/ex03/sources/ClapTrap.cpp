/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:38:25 by Helene            #+#    #+#             */
/*   Updated: 2024/02/05 22:18:37 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
:   _name("Default ClapTrap"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "Default constructor of ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hit = 10, unsigned int energy = 10, unsigned int attack = 0)
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

ClapTrap    &ClapTrap::operator=(ClapTrap const& to_copy)
{
    std::cout << "Copy assignment operator of ClapTrap called" << std::endl;
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
        std::cerr << getName() << " cannot attack : it has no hit points or energy points left!" << std::endl;
        return ;
    }
   
   _energyPoints--;

   std::cout << "ClapTrap " << getName() <<  " attacks " << target;
   std::cout <<  ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{   
    if (amount > _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    
    std::cout << "ClapTrap " << getName() << " took some damages.";
    std::cout << " It now has " << _hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
   if (!_energyPoints)
    {
        std::cerr << getName() << " cannot repair itself : it has no energy points left!" << std::endl;
        return ;
    }
    
    _hitPoints += amount;
    _energyPoints--;

    std::cout << "ClapTrap " << getName() << " repaired itself.";
    std::cout << " It now has " << _hitPoints << " hit points." << std::endl;
}

std::string ClapTrap::getName( void ) const
{
    return (_name);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor of ClapTrap called" << std::endl;
}

std::ostream &operator<<(std::ostream& stream, ClapTrap const &trap)
{
    stream << "Name : " << trap.getName() << std::endl;
    return (stream);
}