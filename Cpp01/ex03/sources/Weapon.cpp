/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:43:26 by Helene            #+#    #+#             */
/*   Updated: 2023/10/04 17:09:38 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type)
:   _type(type)
{}

Weapon::~Weapon()
{}

std::string Weapon::getType( void ) const
{
    return (_type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}
