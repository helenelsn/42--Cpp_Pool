/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:55 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 15:40:00 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int main( void )
{
	Zombie	*zozo = newZombie("zozo");
	zozo->announce();
	randomChump("zaza");
	
	delete zozo;
	zozo = NULL;
	return (0);
}