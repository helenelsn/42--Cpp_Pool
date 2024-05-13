/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:51:07 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 23:21:23 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void iter(T *array, size_t length, void (*f)(T&)) 
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template<typename T>
void iter(T *array, size_t length, void (*f)(const T&)) 
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template<typename T>
void doubleValue(T &value)
{
    value = value + value;
}

template<typename T>
void print(T const& value)
{
    std::cout << value << std::endl;
}

#endif