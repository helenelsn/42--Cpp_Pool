/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:02:55 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/11 00:15:42 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
	public:
		Dog();
        Dog(const Dog& other);
        Dog &operator=(const Dog& other);
        void    makeSound(void) const;
        /* std::string getType(void) const; */
        virtual ~Dog();

    private :
        Brain *_brain;
};

#endif