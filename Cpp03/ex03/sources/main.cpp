/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:54:30 by Helene            #+#    #+#             */
/*   Updated: 2024/02/05 22:21:18 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main(void)
{
   /*  ClapTrap super((std::string)"super");
    ScavTrap scav((std::string)"scav");
    
    FragTrap    ff("frag"); */
    DiamondTrap dd((std::string)"Draco");
    DiamondTrap cc((std::string)"Pika");

    DiamondTrap bb = cc;
    
    std::cout << std::endl << std::endl;
    bb.WhoAmI();
    
    std::cout << std::endl << std::endl;
    dd.WhoAmI();
    dd.attack("Pika");
    // ff.attack("child two");
    // super.attack("child two");
    // scav.attack("child two");
    dd.beRepaired(20);

    std::cout << std::endl << std::endl;
    
    return (0);
}