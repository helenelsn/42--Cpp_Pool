/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:17:36 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/12 15:06:59 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	public :
		MateriaSource();
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
        MateriaSource(const MateriaSource& other);
        MateriaSource &operator=(const MateriaSource& other);
        virtual ~MateriaSource();
    
    protected :

    private :
		  AMateria	*_materias[4];
		  unsigned int _count;
};

#endif