/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:43:54 by Helene            #+#    #+#             */
/*   Updated: 2023/10/11 17:48:27 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{

	public :
		Cure();
        Cure(const Cure& other);
        Cure &operator=(const Cure& other);
        virtual AMateria* clone() const; // lose the virtual here ?
        virtual void use(ICharacter& target);
        virtual ~Cure();
    
    protected :

    private :
		
};

#endif