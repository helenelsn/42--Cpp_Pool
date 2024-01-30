/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:43:26 by Helene            #+#    #+#             */
/*   Updated: 2024/01/19 18:50:54 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type)
:   _type(type)
{}

Weapon::~Weapon()
{}

const std::string& Weapon::getType( void ) const
{
    return (_type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}
