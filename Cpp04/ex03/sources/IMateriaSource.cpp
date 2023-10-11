/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:51:26 by Helene            #+#    #+#             */
/*   Updated: 2023/10/11 17:51:43 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IMateriaSource.hpp"

IMateriaSource::IMateriaSource(/* args */)
{
	std::cout << "IMateriaSource: Default constructor" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {

	std::cout << "IMateriaSource: Copy constructor" << std::endl;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other) {
    
	std::cout << "IMateriaSource: Assignment operator" << std::endl;
	return *this;
}

IMateriaSource::~IMateriaSource() {
    std::cout << "IMateriaSource: Destructor" << std::endl;
}