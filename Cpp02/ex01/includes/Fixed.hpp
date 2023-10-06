/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:32:55 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/06 14:00:44 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed
{
    public :
        Fixed();
        Fixed(const int n);
        Fixed(const double n);
        Fixed(Fixed const& to_copy);
        Fixed& operator=(Fixed const&fNumber);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float	toFloat( void ) const;
        int		toInt( void ) const;

    private :
        int _value;
        static const int    _nbFractionalBits;
};

std::ostream& operator<<(std::ostream &stream, Fixed const& n);

#endif