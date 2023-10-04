/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:17 by Helene            #+#    #+#             */
/*   Updated: 2023/10/04 16:09:05 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <vector>

class Zombie
{
    public :
        Zombie(std::string zombieName = "zozo");
        ~Zombie();
        void announce( void );
        void set_name(std::string name);

    private :
        std::string _name;
};

#endif