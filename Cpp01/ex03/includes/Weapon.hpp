/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:40:25 by Helene            #+#    #+#             */
/*   Updated: 2024/01/19 18:44:58 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    public :
        Weapon(std::string type = "");
        ~Weapon();
        const std::string& getType( void ) const;
        void setType(std::string type);

    private :
        std::string _type;
    
};

#endif