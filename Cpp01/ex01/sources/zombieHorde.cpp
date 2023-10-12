/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:56:59 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 15:41:09 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *firstZz = new (std::nothrow) Zombie[N];
    if (!firstZz)
        return (NULL);
    for (int i = 0; i < N; i++)
        firstZz[i].set_name(name);
    return (firstZz);
}