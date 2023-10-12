/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:01:19 by Helene            #+#    #+#             */
/*   Updated: 2023/10/12 15:09:46 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(/* args */)
:	ICharacter(), // ?
	_name("default_character"),
	_count(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character: Default constructor" << std::endl;
}

Character::Character(std::string const& name)
:	ICharacter(), // ?
	_name(name),
	_count(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character: Default constructor" << std::endl;
}

std::string const & Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* newMateria)
{
	if (_count == 4)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = newMateria;
			break;
		}
	}
	_count++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || (unsigned int)idx > 4 || !_inventory[idx])
		return ;
	/* std::cout << "idx = " << idx << std::endl;
	std::cout << " ------ before : " << std::endl;
	printInventory(); */
	// int i;
	// for (i = idx; (unsigned int)i < _count - 1; i++)
	// 	_inventory[i] = _inventory[i + 1];
	// _inventory[i] = 0;
	_inventory[idx] = 0;
	_count--;
	/* std::cout << " ------ after : " << std::endl;
	printInventory();
	std::cout << std::endl; */
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || (unsigned int)idx >4)
		return ;
	_inventory[idx]->use(target);
}

void	Character::printInventory(void) const {
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			std::cout << "inventory[" << i << "] = " << _inventory[i]->getType() << std::endl;
		else 
			std::cout << "inventory[" << i << "] is empty" << std::endl; 
	}
}


Character::Character(const Character& other) {

	std::cout << "Character: Copy constructor" << std::endl;
	
	// _name = other._name;
	// _count = other._count;
	// for (unsigned int i = 0; i < _count; i++)
	// {
	// 	delete _inventory[i];
	// 	if (_inventory[i])
	// 		_inventory[i] = other._inventory[i]->clone();
	// 	else
	// 		_inventory[i] = NULL;
	// }
	
	*this = other;
}

/* During copy, the Materias of a Character must be deleted before the new ones are added
to their inventory*/
Character& Character::operator=(const Character& other) {
	
	std::cout << "Character: Assignment operator" << std::endl;
    if (this == &other)
		return (*this);
	_name = other._name;
	_count = other._count;
	 this->~Character();
	// for (int i = 0; i < 4; i++)
	// {
	// 	delete _inventory[i];
	// 	_inventory[i] = 0;
	// }
	std::cout << "ok here too" << std::endl;
	for (unsigned int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	return (*this);
}

/*  The Materias must be deleted when a Character is destroyed */
Character::~Character()
{
    std::cout << "Character: Destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = 0;
	}
}