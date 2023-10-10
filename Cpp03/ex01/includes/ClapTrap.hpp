/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:01:34 by Helene            #+#    #+#             */
/*   Updated: 2023/10/10 16:21:53 by hlesny           ###   ########.fr       */
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
		ClapTrap(std::string name, unsigned int hit, unsigned int energy, unsigned int attack);
		ClapTrap(ClapTrap const& to_copy);
		ClapTrap operator=(ClapTrap const& to_copy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		~ClapTrap();

	protected : // ou protected, et n'a alors pas besoin d'autant de getters et setters
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif