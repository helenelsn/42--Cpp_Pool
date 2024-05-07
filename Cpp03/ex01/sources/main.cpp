/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:54:30 by Helene            #+#    #+#             */
/*   Updated: 2024/02/05 20:01:07 by hlesny           ###   ########.fr       */
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
    meta.takeDamage(20);
    meta.attack("pika");
    meta.beRepaired(20);

    meta.guardGate();
    
    
    
    return (0);
}