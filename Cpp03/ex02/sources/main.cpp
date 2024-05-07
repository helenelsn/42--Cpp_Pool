/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:54:30 by Helene            #+#    #+#             */
/*   Updated: 2024/02/05 20:10:24 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main(void)
{
    
    
    FragTrap meta("meta_pika");
    FragTrap one("pika");
    
    FragTrap two(one);

    one.highFivesGuys();
    one.attack("meta_pika");
    meta.takeDamage(20);
    meta.attack("pika");
    meta.beRepaired(20);
    meta.highFivesGuys();
    
}