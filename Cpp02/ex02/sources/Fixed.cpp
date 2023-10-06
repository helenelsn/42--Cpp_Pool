/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:31:50 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/06 15:54:34 by Helene           ###   ########.fr       */
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
    //std::cout << "getRawBits member function called" << std::endl;
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

Fixed &Fixed::operator=(Fixed const& to_copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(to_copy.getRawBits());
    return (*this);
}

bool Fixed::operator>(Fixed const& n)
{
    return (this->getRawBits() > n.getRawBits());
}

bool Fixed::operator<(Fixed const& n)
{
    return (!((*this) > n));
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

const Fixed Fixed::operator+(Fixed const& n)
{
    return (Fixed(n.toFloat() + this->toFloat()));
}

const Fixed Fixed::operator-(Fixed const& n)
{
    return (Fixed(n.toFloat() - this->toFloat()));
}

const Fixed Fixed::operator*(Fixed const& n)
{
    return (Fixed(n.toFloat() * this->toFloat()));
}

const Fixed Fixed::operator/(Fixed const& n)
{
    return (Fixed(n.toFloat() / this->toFloat()));
}

Fixed &Fixed::operator++(void)
{
    (_value)++;
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
    (_value)--;
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

const Fixed &Fixed::min(Fixed const&a, Fixed const&b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(Fixed const&a, Fixed const&b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}


std::ostream&    operator<<(std::ostream &stream, Fixed const& n)
{
    stream << n.toFloat();
    return (stream);
}
