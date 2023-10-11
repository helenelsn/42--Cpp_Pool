/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:08:58 by Helene            #+#    #+#             */
/*   Updated: 2023/10/11 17:37:55 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
//#include "ICharacter.hpp"

class ICharacter;

class AMateria 
{
    
    protected :
        std::string _type; // const ?

	public :
		AMateria();
        AMateria(std::string const & type);
        std::string const & getType() const; //Returns the materia type
        AMateria(const AMateria& other);
        AMateria &operator=(const AMateria& other);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0; // = 0 ?
        virtual ~AMateria();
};

#endif