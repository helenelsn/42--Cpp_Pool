/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:54:30 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 17:36:44 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void)
{
    
    ClapTrap test("pikapika");
    ClapTrap another("ronflex");

    test.attack("ronflex");
    another.takeDamage(3);
    another.beRepaired(20);
    return (0);
}