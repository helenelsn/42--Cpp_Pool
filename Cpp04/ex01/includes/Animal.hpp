/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:01:10 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/10 19:39:09 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public :
        Animal();
        Animal(Animal const& copy);
        Animal &operator=(Animal const& copy);
        virtual void    makeSound(void) const;
        std::string getType(void) const;
        virtual ~Animal();

    protected :
        std::string _type;
};

#endif