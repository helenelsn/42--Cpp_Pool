/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:30:47 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 15:11:21 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"

int main( void )
{
    /*{
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
        
    } */
    /*{
        ICharacter *pika = new Character("pikachu");
        ICharacter *draco(pika);

        
        std::cout <<  pika->getName() << std::endl;
        std::cout <<  draco->getName() << std::endl;
        delete pika;
        pika = NULL;
        std::cout << "ok here" << std::endl;
        std::cout <<  draco->getName() << std::endl;
    }*/
    {
        ICharacter *pika = new Character("pikachu");
        AMateria *ice = new Ice();
        IMateriaSource *mat_s = new MateriaSource();
        
        std::cout << "----" << std::endl;
        mat_s->learnMateria(ice);
        pika->equip(mat_s->createMateria("ice"));
    }

    

    return (0);
}