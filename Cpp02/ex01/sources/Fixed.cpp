/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:31:50 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/06 15:54:45 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int const   Fixed::_nbFractionalBits = 8;

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

Fixed::Fixed(const double n)
:   _value(roundf(n * (1 << _nbFractionalBits))) //_value(roundf(n * pow(2, _nbFractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
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


int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void    Fixed::setRawBits( int const raw )
{
    _value = raw;
}

float	Fixed::toFloat( void ) const
{
    //return (float(_value / (1 << _nbFractionalBits)));
    return (float(_value / pow(2, _nbFractionalBits)));
}

int		Fixed::toInt( void ) const
{
    return (_value >> _nbFractionalBits);
}

