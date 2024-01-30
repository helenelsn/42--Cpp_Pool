/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:49:10 by Helene            #+#    #+#             */
/*   Updated: 2024/01/30 17:38:30 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
    public :
		HumanA(std::string name, Weapon & weapon);
		void	attack( void ) const;

    private :
        std::string	_name;
        Weapon		&_weapon;
};