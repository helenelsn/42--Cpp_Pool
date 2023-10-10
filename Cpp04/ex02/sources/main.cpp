/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:05:08 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/11 00:15:13 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A_Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
    {
        const A_Animal* meta = new A_Animal();
        const A_Animal* j = new Dog();
        const A_Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete i;
        delete j;
        delete meta;
        
    }
    std::cout << "------------------------------------" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const A_Animal* j = new Dog();
        const WrongAnimal* i = new WrongCat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete i;
        delete j;
        delete meta;
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << std::endl;
    {
        Cat *i = new Cat();
        Cat *j = new Cat();
        i->addIdea("first one");
        j->addIdea("youhou");
        i->printIdeas();
        j->printIdeas();
        Cat *k(j);
        k->printIdeas();
        j->~Cat();
        k->printIdeas();
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << std::endl;
    {
        int n(4);
        A_Animal *farm[n];
        for (int i = 0; i < n/2; i++)
            farm[i] = new Cat();
        for (int i = n/2; i < n; i++)
            farm[i] = new Dog();
        
        for (int i = 0; i < n; i++)
            delete farm[i];
    }
    return 0;
}