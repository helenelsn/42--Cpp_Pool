/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:01:19 by Helene            #+#    #+#             */
/*   Updated: 2024/02/06 23:53:28 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
:	ICharacter(), // va le faire dans tous les cas
	_name("default_character"),
	_count(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character: Default constructor" << std::endl;
}

Character::Character(std::string const& name)
:	ICharacter(), // va le faire dans tous les cas
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
	{
		std::cout << "The " << getName() << " character already has 4 materias.";
		std::cout << " Please remove one before adding a new one." << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = newMateria;
			break;
		}
	}
	std::cout << _name << " was successfully equiped" << std::endl;
	_count++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || (unsigned int)idx > 3 || !_inventory[idx])
	{
		std::cout << _name << " cannot be unequiped : bad index or empty slot" << std::endl;
		return ;
	}
	std::cout << _name << " was successfully unequiped" << std::endl;
	/* std::cout << "idx = " << idx << std::endl;
	std::cout << " ------ before : " << std::endl;
	printInventory(); */
	// int i;
	// for (i = idx; (unsigned int)i < _count - 1; i++)
	// 	_inventory[i] = _inventory[i + 1];
	// _inventory[i] = 0;
	_inventory[idx] = NULL;
	_count--;
	/* std::cout << " ------ after : " << std::endl;
	printInventory();
	std::cout << std::endl; */
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || (unsigned int)idx > 3 || !_inventory[idx])
	{
		std::cout << _name << " cannot use the materia : bad index or empty slot" << std::endl;
		return ;
	}
	std::cout << _name << " : ";
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
	// this->~Character();
	std::cout << "ok here too" << std::endl;
	for (unsigned int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = 0;
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
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