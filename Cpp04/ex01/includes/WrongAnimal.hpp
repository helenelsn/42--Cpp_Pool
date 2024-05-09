/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:24:58 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/06 16:20:27 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{

	public :
		WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal &operator=(const WrongAnimal& other);
        void    makeSound(void) const;
        std::string getType(void) const;
        virtual ~WrongAnimal();
    
    protected :
        std::string _type;
    private :
		
};

#endif