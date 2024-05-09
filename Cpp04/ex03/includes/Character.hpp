/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:00:53 by Helene            #+#    #+#             */
/*   Updated: 2024/02/06 21:55:24 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{

	public :
		Character();
        Character(std::string const& name);
        Character(const Character& other);
        Character &operator=(const Character& other);
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx); // must not delete the materia (bc an instance of it still exists somewhere else)
        virtual void use(int idx, ICharacter& target);
        void printInventory(void) const; // todel
        virtual ~Character();

    private :
        std::string     _name;
        AMateria        *_inventory[4];
        unsigned int    _count;
		
};

#endif