/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:51:07 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 20:46:30 by hlesny           ###   ########.fr       */
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
void doubleValue(T &value)
{
    value = value + value;
}

template<typename T>
void print(T const& value)
{
    std::cout << value << std::endl;
}

class Awesome
{
    public:
        Awesome( void ) : _n( 42 ) { return; }
        int get( void ) const { return this->_n; }
    private:
        int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

#endif