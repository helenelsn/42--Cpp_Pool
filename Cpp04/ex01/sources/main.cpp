/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:05:08 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/06 21:50:02 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
    {
        Cat *i = new Cat();
        Cat *j = new Cat();
        i->addIdea("first one");
        j->addIdea("youhou");
        i->printIdeas();
        j->printIdeas();
        Cat *k = new Cat();
        *k = *i;
        k->printIdeas();
        delete i;
        k->printIdeas();
        delete j;
        delete k;
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << std::endl;
    {
        int n(4);
        Animal *farm[n];
        for (int i = 0; i < n/2; i++)
            farm[i] = new Cat();
        for (int i = n/2; i < n; i++)
            farm[i] = new Dog();
        
        for (int i = 0; i < n; i++)
            delete farm[i];
    }
    return 0;
}