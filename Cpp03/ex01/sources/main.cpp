/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:54:30 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 17:44:59 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
    
    ScavTrap meta("meta_pika");
    ScavTrap one("pika");
    ScavTrap two(one);

    one.guardGate();
    one.attack("meta_pika");
    meta.attack("pika");

    two.guardGate();
    
    
    
    return (0);
}