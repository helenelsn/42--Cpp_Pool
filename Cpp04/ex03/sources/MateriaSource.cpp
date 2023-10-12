/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:20:36 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/12 15:03:30 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
:	_count(0)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	std::cout << "MateriaSource: Default constructor" << std::endl;
}

void MateriaSource::learnMateria(AMateria* to_learn)
{
	if (_count == 4)
		return ;
	_materias[_count] = to_learn; //to_learn->clone();
	_count++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (unsigned int i = 0; i < _count; i++)
	{
		if (_materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	return (0);
}


MateriaSource::MateriaSource(const MateriaSource& other) {

	std::cout << "MateriaSource: Copy constructor" << std::endl;
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    
	std::cout << "MateriaSource: Assignment operator" << std::endl;

	(void) other; // todel
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = 0;
		if (other._materias[i])
			_materias[i] = other._materias[i];
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource: Destructor" << std::endl;
	for (int i = 0; i < 4; i++) /* not even that useful */
		_materias[i] = NULL;
}