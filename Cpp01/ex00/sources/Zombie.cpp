/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:25 by Helene            #+#    #+#             */
/*   Updated: 2023/10/04 16:15:18 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string zombieName)
: _name(zombieName)
{}

Zombie::~Zombie()
{
    std::cout << _name << " died..... again." << std::endl; 
}