/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:01:34 by Helene            #+#    #+#             */
/*   Updated: 2023/10/10 19:39:49 by hlesny           ###   ########.fr       */
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
		ClapTrap();
		ClapTrap(std::string name, unsigned int hit = 10, unsigned int energy = 10, unsigned int attack = 10);
		ClapTrap(ClapTrap const& to_copy);
		ClapTrap operator=(ClapTrap const& to_copy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		virtual ~ClapTrap();

	protected : // ou protected, et n'a alors pas besoin d'autant de getters et setters
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif