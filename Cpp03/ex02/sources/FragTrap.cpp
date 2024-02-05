/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:41:54 by Helene            #+#    #+#             */
/*   Updated: 2024/02/05 21:37:09 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap()
:   ClapTrap("Default_FragTrap", 100, 100, 30)
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

FragTrap &FragTrap::operator=(FragTrap const& to_copy)
{
    this->ClapTrap::operator=(to_copy);
    // this->_name = to_copy._name;
    // this->_attackDamage = to_copy._attackDamage;
    // this->_energyPoints = to_copy._energyPoints;
    // this->_hitPoints = to_copy._hitPoints;
    std::cout << "Copy assignment constructor of FragTrap called" << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " wishes to do a high fives" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor of FragTrap called" << std::endl;
}