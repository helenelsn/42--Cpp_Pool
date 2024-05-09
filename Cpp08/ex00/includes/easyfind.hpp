/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:27:23 by Helene            #+#    #+#             */
/*   Updated: 2024/05/09 20:02:57 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

// Assuming T is a container of integers, this function has to find the first occurrence
// of the second parameter in the first parameter.

class NotFoundException : public std::exception
{
	public :
		const char *what() const throw() {
			return "Value not found in container";
		}
};

template<typename T> // T is a container of integers here
typename T::iterator easyfind(T container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind); 
    return it != container.end() ? it : throw NotFoundException();
}



#endif