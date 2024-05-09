/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:05:08 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/06 16:16:15 by hlesny           ###   ########.fr       */
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
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        j->makeSound();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();

        delete i;
        delete j;
        delete meta;
        
    }
    std::cout << "------------------------------------" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const Animal* j = new Dog();
        const WrongAnimal* i = new WrongCat();
        std::cout << j->getType() << " " << std::endl;
        j->makeSound();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();

        delete i;
        delete j;
        delete meta;
    }
    return 0;
}