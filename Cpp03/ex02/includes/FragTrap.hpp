/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:41:26 by Helene            #+#    #+#             */
/*   Updated: 2023/10/09 18:45:11 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public :
        FragTrap(std::string name);
        FragTrap(FragTrap const& to_copy);
        FragTrap operator=(FragTrap const& to_copy);
        void highFivesGuys(void);
        ~FragTrap();
};

#endif