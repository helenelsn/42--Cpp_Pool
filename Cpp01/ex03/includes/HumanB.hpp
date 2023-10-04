/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:51:48 by Helene            #+#    #+#             */
/*   Updated: 2023/10/04 18:00:52 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
    public :
		HumanB(std::string name);
		void	attack( void ) const;
        void    setWeapon(Weapon &weapon);

    private :
        std::string	_name;
        Weapon		*_weapon;
};