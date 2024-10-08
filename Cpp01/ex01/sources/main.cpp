/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:56:32 by Helene            #+#    #+#             */
/*   Updated: 2023/10/06 19:03:18 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main ( void )
{
    Zombie *first = zombieHorde(5, "roro");
    for (int i = 0; i < 5; i++)
        first[i].announce();
    delete [] first;
    first = NULL;
}