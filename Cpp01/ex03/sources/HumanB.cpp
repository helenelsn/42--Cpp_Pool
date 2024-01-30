/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:04:16 by Helene            #+#    #+#             */
/*   Updated: 2024/01/19 18:55:00 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
:   _name(name),
    _weapon(NULL) // ?
{}

void	HumanB::attack( void ) const
{
    if (! _weapon)
        std::cout << _name << "has no weapon." << std::endl;
    else
        std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}