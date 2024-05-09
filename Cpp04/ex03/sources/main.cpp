/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:30:47 by Helene            #+#    #+#             */
/*   Updated: 2024/02/07 00:11:29 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"

int main( void )
{
    /* {
        // Cure c;
        AMateria *i = new Ice();
        AMateria *j = new Cure();
        ICharacter *dra = new Character("dracofeu");
        // dra->equip(&c);
        dra->equip(i);
        std::cout << "i : type : " << i->getType() << std::endl;
        std::cout << "j : type : " << j->getType() << std::endl;
        AMateria *k = i->clone();
        std::cout << "k : type : " << k->getType() << std::endl;
        // delete i;
        delete j;
        delete dra;
        delete k;
        std::cout << std::endl << "-----------------------------" << std::endl << std::endl;;
    } */
    
    {
        AMateria *one = new Ice();
        AMateria *two = new Cure();
        AMateria *oneBis = one->clone();
        AMateria *three = new Ice();
        AMateria *four = new Ice();
        
        ICharacter *pik = new Character("pikachu");
        ICharacter *dra = new Character("dracofeu");

        std::cout << std::endl;
        
        pik->equip(one);
        pik->equip(two);
        pik->use(0, *dra);
        pik->use(1, *dra);
        
        pik->unequip(1);
        pik->use(0, *dra);
        pik->use(1, *dra); // should not do anything

        pik->equip(two);
        pik->equip(oneBis);
        pik->equip(four);
        pik->equip(three); // should not do anything
        pik->unequip(4); // should not do anything
        pik->unequip(-1); // should not do anything
        
        std::cout << std::endl << " ----------------------------- " << std::endl << std::endl;
        
        for (int i = 0; i < 4; i++)
            pik->use(i, *dra);
        
        std::cout << std::endl << " ----------------------------- " << std::endl << std::endl;
        
        pik->unequip(0);
        for (int i = 0; i < 4; i++)
            pik->use(i, *dra);
            
        std::cout << std::endl <<  " ----------------------------- " << std::endl << std::endl;
        
        for (int i = 0; i < 15; i++)
            pik->unequip(i);
        
        std::cout << std::endl <<  "-----------------------------" << std::endl << std::endl;
        
        for (int i = 0; i < 4; i++)
            pik->use(i, *dra);
        
        std::cout << std::endl <<  "-----------------------------" << std::endl << std::endl;

        IMateriaSource *mat_source = new MateriaSource();        
        mat_source->learnMateria(one);
        mat_source->learnMateria(two);
        std::cout << "lollllllllll"<<std::endl;
        pik->equip(mat_source->createMateria("ice"));
        pik->equip(mat_source->createMateria("cure"));
        dra->equip(mat_source->createMateria("ice"));

        std::cout << std::endl <<  "-----------------------------" << std::endl << std::endl;

        delete mat_source;        
        delete pik;
        delete dra;
        // delete one;
        // delete two;
        delete oneBis;
        delete three;
        delete four;
    }
    return (0);
}