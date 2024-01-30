/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:32:55 by hlesny            #+#    #+#             */
/*   Updated: 2023/12/22 21:31:16 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public :
        Fixed();
        Fixed(Fixed const& to_copy);
        Fixed& operator=(Fixed const&fNumber);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

    private :
        int _value;
        static const int    _nbFractionalBits;
};

#endif