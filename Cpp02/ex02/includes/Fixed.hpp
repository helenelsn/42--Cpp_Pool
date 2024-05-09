/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:32:55 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/02 18:53:13 by hlesny           ###   ########.fr       */
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
        Fixed(const float n);
        Fixed(Fixed const& to_copy);
        const Fixed& operator=(Fixed const&fNumber);
        bool operator>(Fixed const& n);
        bool operator<(Fixed const& n);
        bool operator>=(Fixed const& n);
        bool operator<=(Fixed const& n);
        bool operator!=(Fixed const& n);
        bool operator==(Fixed const& n);
        Fixed operator+(Fixed const& n);
        Fixed operator-(Fixed const& n);
        Fixed operator*(Fixed const& n);
        Fixed operator/(Fixed const& n);
        Fixed &operator++(void); /* ++p */
        Fixed operator++(int); /* p++ */
        Fixed &operator--(void); /* --p */
        Fixed operator--(int); /* p-- */
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &min(Fixed const&a, Fixed const&b);
        static Fixed &max(Fixed &a, Fixed &b);
        static Fixed &max(Fixed const&a, Fixed const&b);
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float	toFloat( void ) const;
        int		toInt( void ) const;
        ~Fixed();

    private :
        int _value;
        static const int    _nbFractionalBits;
};

std::ostream& operator<<(std::ostream &stream, Fixed const& n);

#endif