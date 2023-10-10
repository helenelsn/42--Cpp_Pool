/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:54:30 by Helene            #+#    #+#             */
/*   Updated: 2023/10/10 16:46:44 by hlesny           ###   ########.fr       */
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
    DiamondTrap dd((std::string)"child one");
    DiamondTrap cc((std::string)"child two");
    /* dd.attack("child two");
    ff.attack("child two");
    super.attack("child two");
    scav.attack("child two");
    dd.WhoAmI(); */
    
    return (0);
}