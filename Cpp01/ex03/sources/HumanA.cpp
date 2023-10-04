/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:53:04 by Helene            #+#    #+#             */
/*   Updated: 2023/10/04 17:58:48 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon & weapon)
:   _name(name),
    _weapon(weapon)
{}

void	HumanA::attack( void ) const
{
    std::cout << _name << " attacks with " << _weapon.getType() << std::endl;
}