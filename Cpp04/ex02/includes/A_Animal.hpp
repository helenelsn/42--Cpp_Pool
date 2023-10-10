/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:01:10 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/11 00:13:25 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class A_Animal
{
    public :
        A_Animal();
        A_Animal(A_Animal const& copy);
        A_Animal &operator=(A_Animal const& copy);
        virtual void    makeSound(void) const = 0;
        std::string getType(void) const;
        virtual ~A_Animal();

    protected :
        std::string _type;
};

#endif