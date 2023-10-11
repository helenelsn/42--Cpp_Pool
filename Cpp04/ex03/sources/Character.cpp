/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:01:19 by Helene            #+#    #+#             */
/*   Updated: 2023/10/11 17:56:55 by Helene           ###   ########.fr       */
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

void Character::equip(AMateria* m)
{
	if (_count == 4)
		return ;
	_inventory[_count] = m;
	_count++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || (unsigned int)idx > _count)
		return ;
	int i;
	for (i = idx; (unsigned int)i < _count - 1; i++)
		_inventory[i] = _inventory[i + 1];
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || (unsigned int)idx > _count)
		return ;
	_inventory[idx]->use(target);
}


Character::Character(const Character& other) {

	std::cout << "Character: Copy constructor" << std::endl;
}

Character& Character::operator=(const Character& other) {
    
	std::cout << "Character: Assignment operator" << std::endl;
	return *this;
}

Character::~Character()
{
    std::cout << "Character: Destructor" << std::endl;
}