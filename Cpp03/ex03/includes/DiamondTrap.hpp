/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:47:50 by Helene            #+#    #+#             */
/*   Updated: 2024/02/05 22:25:49 by hlesny           ###   ########.fr       */
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
        DiamondTrap &operator=(DiamondTrap const& to_copy);
        std::string getName() const;
        using ScavTrap::attack;
        void    WhoAmI(void);
        ~DiamondTrap();
    
    private :
        std::string _name;
};

#endif