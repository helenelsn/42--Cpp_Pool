/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:47:50 by Helene            #+#    #+#             */
/*   Updated: 2023/10/09 20:05:41 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public :
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const& to_copy);
        DiamondTrap operator=(DiamondTrap const& to_copy);
        void highFivesGuys(void);
        ~DiamondTrap();
    private :
        std::string _name;
}

#endif