/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:32:55 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/06 22:42:01 by Helene           ###   ########.fr       */
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
        bool operator>(Fixed const& n);
        bool operator<(Fixed const& n);
        bool operator>=(Fixed const& n);
        bool operator<=(Fixed const& n);
        bool operator!=(Fixed const& n);
        bool operator==(Fixed const& n);
        const Fixed operator+(Fixed const& n);
        const Fixed operator-(Fixed const& n);
        const Fixed operator*(Fixed const& n);
        const Fixed operator/(Fixed const& n);
        const Fixed operator*(double a);
        Fixed &operator++(void); /* ++p */
        Fixed operator++(int); /* p++ */
        Fixed &operator--(void); /* --p */
        Fixed operator--(int); /* p-- */
        static Fixed &min(Fixed &a, Fixed &b);
        const static Fixed &min(Fixed const&a, Fixed const&b);
        static Fixed &max(Fixed &a, Fixed &b);
        const static Fixed &max(Fixed const&a, Fixed const&b);
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
//const Fixed operator*(double a, Fixed const& n);

#endif