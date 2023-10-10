/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:02:17 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/11 00:15:46 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal
{

	public:
		Cat();
        Cat(const Cat& other);
        Cat &operator=(const Cat& other);
        void    makeSound(void) const;
        /* std::string getType(void) const; */
        void    addIdea(std::string newIdea) { _brain->addIdea(newIdea); }
        void    printIdeas(void) const { std::cout << "Ideas inside a " << _type << "'s brain : " << std::endl; _brain->printIdeas(); }
        virtual ~Cat();
		
    private :
        Brain *_brain;
};

#endif