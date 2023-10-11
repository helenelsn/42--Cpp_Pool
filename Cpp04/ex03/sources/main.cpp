/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:30:47 by Helene            #+#    #+#             */
/*   Updated: 2023/10/11 23:54:40 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"

int main( void )
{
    {
        Cure c;
        AMateria *i = new Ice();
        AMateria *j = new Cure();
        ICharacter *dra = new Character("dracofeu");
        dra->equip(&c);
        std::cout << "i : type : " << i->getType() << std::endl;
        std::cout << "j : type : " << j->getType() << std::endl;
        AMateria *k = i->clone();
        std::cout << "k : type : " << k->getType() << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
    {
        AMateria *one = new Ice();
        AMateria *two = new Cure();
        AMateria *oneBis = one->clone();
        AMateria *three = new Ice();
        
        ICharacter *pik = new Character("pikachu");
        ICharacter *dra = new Character("dracofeu");
        pik->equip(one);
        pik->equip(two);
        std::cout << pik->getName() << " : ";
        pik->use(0, *dra);
        std::cout << pik->getName() << " : ";
        pik->use(1, *dra);
        
        pik->unequip(1);
        std::cout << pik->getName() << " : ";
        pik->use(0, *dra);
        std::cout << pik->getName() << " : ";
        pik->use(1, *dra);

        pik->equip(two);
        pik->equip(oneBis);
        pik->equip(three); // should not do anything
        pik->unequip(4); // should not do anything
        pik->unequip(-1); // should not do anything
        for (int i = 0; i < 4; i++)
        {
            std::cout << pik->getName() << " : ";
            pik->use(i, *dra);
        }
        std::cout << " ----------------------------- " << std::endl;
        pik->unequip(0);
        for (int i = 0; i < 4; i++)
        {
            std::cout << pik->getName() << " : ";
            pik->use(i, *dra);
        }
        std::cout << " ----------------------------- " << std::endl;
        for (int i = 0; i < 15; i++)
            pik->unequip(0);
        
        std::cout << "-------------------lol----------" << std::endl;
        for (int i = 0; i < 4; i++)
            pik->use(i, *dra);
        
    }
    {
        ICharacter *pika = new Character("pikachu");
        ICharacter *draco(pika);
        
        pika->getName();
        draco->getName();
        delete pika;
        draco->getName(); 
    }

    

    return (0);
}