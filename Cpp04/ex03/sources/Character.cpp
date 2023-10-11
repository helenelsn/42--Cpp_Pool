/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:01:19 by Helene            #+#    #+#             */
/*   Updated: 2023/10/11 21:35:01 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(/* args */)
:	_name("default_character"),
	_count(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character: Default constructor" << std::endl;
}

Character::Character(std::string const& name)
:	_name(name),
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
	_inventory[_count] = newMateria;
	_count++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || (unsigned int)idx >= _count)
		return ;
	int i;
	/* std::cout << "idx = " << idx << std::endl;
	std::cout << " ------ before : " << std::endl;
	printInventory(); */
	for (i = idx; (unsigned int)i < _count - 1; i++)
		_inventory[i] = _inventory[i + 1];
	_inventory[i] = 0;
	_count--;
	/* std::cout << " ------ after : " << std::endl;
	printInventory(); */
	std::cout << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || (unsigned int)idx >= _count)
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
	
	_name = other._name;
	_count = other._count;
	for (unsigned int i = 0; i < _count; i++)
	{
		delete _inventory[i];
		if (_inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
    
	std::cout << "Character: Assignment operator" << std::endl;
	_name = other._name;
	_count = other._count;
	for (unsigned int i = 0; i < _count; i++)
	{
		delete _inventory[i];
		if (_inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
    std::cout << "Character: Destructor" << std::endl;
	/* AMateria mustn't be desallocated in this class, as an instance still exists
	somewhere else*/
}