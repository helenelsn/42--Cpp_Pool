/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:00:55 by Helene            #+#    #+#             */
/*   Updated: 2023/10/09 18:29:37 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const& to_copy);
        ScavTrap operator=(ScavTrap const& to_copy);
        void guardGate();
        ~ScavTrap();
};

#endif