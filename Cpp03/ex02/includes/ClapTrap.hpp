/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:01:34 by Helene            #+#    #+#             */
/*   Updated: 2024/02/05 21:35:23 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap 
{
	
    public :
		ClapTrap(std::string name, unsigned int hit, unsigned int energy, unsigned int attack);
		ClapTrap(ClapTrap const& to_copy);
		ClapTrap& operator=(ClapTrap const& to_copy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		virtual std::string getName();
		~ClapTrap();

	protected :
		ClapTrap();
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif