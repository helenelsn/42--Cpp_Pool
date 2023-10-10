/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:25:02 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/10 19:26:51 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public :
		WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat &operator=(const WrongCat& other);
        void    makeSound(void) const;
        /* std::string getType(void) const; */
        virtual ~WrongCat();
    
    protected :

    private :
		
};

#endif