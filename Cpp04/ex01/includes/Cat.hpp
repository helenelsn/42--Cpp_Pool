/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:02:17 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/06 17:05:36 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

	public:
		Cat();
        Cat(const Cat& other);
        Cat &operator=(const Cat& other);
        void    makeSound(void) const;
        /* std::string getType(void) const; */
        void    addIdea(std::string newIdea);
        void    printIdeas(void) const;
        virtual ~Cat();
		
    private :
        Brain *_brain;
};

#endif