/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:31:50 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/02 18:55:06 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int const   Fixed::_nbFractionalBits = 8;


Fixed::Fixed()
:   _value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
:   _value(n << _nbFractionalBits)
{
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
:   _value((int)roundf(n * (1 << _nbFractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
    int exp_mask = 0x7f800000;
    float f = n;
    int *test = (int *)&f;
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
    // std::cout << "Copy constructor called" << std::endl;
    *this = to_copy;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void    Fixed::setRawBits( int const raw )
{
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

const Fixed &Fixed::operator=(Fixed const& to_copy)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(to_copy.getRawBits());
    return (*this);
}

bool Fixed::operator>(Fixed const& n)
{
    return (this->getRawBits() > n.getRawBits());
}

bool Fixed::operator<(Fixed const& n)
{
    return (!(*this > n) && !(*this == n));
}

bool Fixed::operator>=(Fixed const& n)
{
    return ((*this) > n || (*this) == n);
}

bool Fixed::operator<=(Fixed const& n)
{
    return ((*this) < n || (*this) == n);
}

bool Fixed::operator!=(Fixed const& n)
{
    return (! ((*this) == n));
}

bool Fixed::operator==(Fixed const& n)
{
    return (this->getRawBits() == n.getRawBits());
}

// const ?
Fixed Fixed::operator+(Fixed const& n)
{
    return (Fixed(n.toFloat() + this->toFloat()));
}

Fixed Fixed::operator-(Fixed const& n)
{
    return (Fixed(this->toFloat() - n.toFloat()));
}

Fixed Fixed::operator*(Fixed const& n)
{
    return (Fixed(n.toFloat() * this->toFloat()));
}

Fixed Fixed::operator/(Fixed const& n)
{
    if (!n.toFloat())
    {
        std::cerr << "Division by zero not allowed" << std::endl;
        return Fixed();
    }
    return (Fixed(this->toFloat() / n.toFloat()));
}

Fixed &Fixed::operator++(void)
{
    _value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _value++;
    return (tmp);
}

Fixed &Fixed::operator--(void)
{
    _value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _value--;
    return (tmp);
}

/* returns a reference to the smallest one */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::min(Fixed const&a, Fixed const&b)
{
    if (a.getRawBits() < b.getRawBits())
        return ((Fixed &)a);
    return ((Fixed &)b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed const&a, Fixed const&b)
{
    if (a.getRawBits() > b.getRawBits())
        return ((Fixed &)a);
    return ((Fixed &)b);
}


std::ostream&    operator<<(std::ostream &stream, Fixed const& n)
{
    stream << n.toFloat();
    return (stream);
}
