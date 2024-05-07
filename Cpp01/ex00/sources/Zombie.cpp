/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:25 by Helene            #+#    #+#             */
/*   Updated: 2024/01/30 17:12:14 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string zombieName)
: _name(zombieName)
{
    std::cout << _name << " was created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " died..... again." << std::endl; 
}