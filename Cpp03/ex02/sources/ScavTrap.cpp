/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:00:35 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 17:43:19 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
:   ClapTrap(name, 100, 50, 20)
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
    // y a t il un moyen d'appeler la surcharge d'op de la classe parente ?
    this->_name = to_copy._name;
    this->_attackDamage = to_copy._attackDamage;
    this->_energyPoints = to_copy._energyPoints;
    this->_hitPoints = to_copy._hitPoints;
    return (*this);
}

void ScavTrap::guardGate(void)
{
    std::cout << "Scat trap " << _name << " is now in Gate keeper mode " << std::endl;
}

ScavTrap::~ScavTrap()
{
    //this->ClapTrap::~ClapTrap();
    std::cout << "Destructor of ScavTrap called" << std::endl;
}