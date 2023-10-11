/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:43:34 by Helene            #+#    #+#             */
/*   Updated: 2023/10/11 17:48:34 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{

	public :
		Ice();
        Ice(const Ice& other);
        Ice &operator=(const Ice& other);
        virtual AMateria* clone() const; // lose the virtual here ?
        virtual void use(ICharacter& target);
        virtual ~Ice();
    
    protected :

    private :
		
};

#endif