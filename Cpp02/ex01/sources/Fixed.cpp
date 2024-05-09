/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:31:50 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/02 18:40:57 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int const   Fixed::_nbFractionalBits = 8;

Fixed::Fixed()
:   _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
:   _value(n << _nbFractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
:   _value((int)(roundf(n * (1 << _nbFractionalBits)))) //_value(roundf(n * pow(2, _nbFractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
    int exp_mask = 0x7f800000;
    int *test = (int *)&n;
    *test = *test & exp_mask;
    *test = *test >> 23;
    if (*test == 0xff)
    {
        setRawBits(0);
        std::cerr << "Nan or Infinity, raw value set to zero." << std::endl; 
    }
}


Fixed::Fixed(Fixed const& to_copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = to_copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream&    operator<<(std::ostream &stream, Fixed const& n)
{
    stream << n.toFloat();
    return (stream);
}

Fixed &Fixed::operator=(Fixed const& to_copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(to_copy.getRawBits());
    return (*this);
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

/* In general, mathematically, given a fixed binary point position, 
shifting the bit pattern of a number to the right by 1 bit always divide the number by 2.
Similarly, shifting a number to the left by 1 bit multiplies the number by 2. */
float	Fixed::toFloat( void ) const
{
    // return (float(_value / pow(2, _nbFractionalBits)));
    return (float((float)_value / (1 << _nbFractionalBits)));
}

int		Fixed::toInt( void ) const
{
    // return ((int)roundf(_value / pow(2, _nbFractionalBits)));
    return ((int)(roundf(_value / (1 << _nbFractionalBits))));
}

