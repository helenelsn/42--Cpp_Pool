/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:41:26 by Helene            #+#    #+#             */
/*   Updated: 2023/10/10 19:52:51 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    public :
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const& to_copy);
        FragTrap operator=(FragTrap const& to_copy);
        void highFivesGuys(void);
        virtual ~FragTrap();
};

#endif