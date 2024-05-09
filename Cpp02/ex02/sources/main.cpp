/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:58:58 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/02 18:58:13 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void )
{
    /* {
        Fixed a;
        Fixed const b( 10 );
        Fixed const c( 42.42f );
        Fixed const d( b );
        a = Fixed( 1234.4321f );
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;
        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
        return 0;
    } */

   { 
        Fixed a( Fixed( 5.05f ) * Fixed( 2 ) );
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        Fixed c(2.0f);
        Fixed test(NAN);
        // Fixed test(-142.55f);
        
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
        std::cout << "test = " << test << std::endl << std::endl;
        
        /* pre/post increment operators */
        std::cout << "++c : "; 
        std::cout << ++c << std::endl;
        std::cout << "c after : "; 
        std::cout << c << std::endl;
        std::cout << "c++ : "; 
        std::cout << c++ << std::endl;
        std::cout << "c after : "; 
        std::cout << c << std::endl << std::endl;
        
        /* pre/post decrement and increment operators */
        std::cout << "--c : "; 
        std::cout << --c << std::endl;
        std::cout << "c after : "; 
        std::cout << c << std::endl;
        std::cout << "c-- : "; 
        std::cout << c-- << std::endl;
        std::cout << "c after : "; 
        std::cout << c << std::endl << std::endl;
        
        /* [+*-/] operators */
        // std::cout << test << " + " << a << " = " << test + a << std::endl;
        // std::cout << test << " - " << a << " = " << test - a << std::endl;
        // std::cout << test << " * " << a << " = " << test * a << std::endl;
        // std::cout << test << " / " << a << " = " << test / a << std::endl;
        std::cout << a << " + " << c << " = " << a + c << std::endl;
        std::cout << a << " - " << c << " = " << a - c << std::endl;
        std::cout << a << " * " << c << " = " << a * c << std::endl;
        std::cout << a << " / " << c << " = " << a / c << std::endl << std::endl;

        /* <, <=, >, >= operators */
        if (a < c)
            std::cout << a << " < " << c << std::endl;
        if (a <= c)
            std::cout << a << " <= " << c << std::endl;
        if (a >= c)
            std::cout << a << " >= " << c << std::endl;
        if (a > c)
            std::cout << a << " > " << c << std::endl << std::endl;
        
        /* min() and max() methods */
        Fixed &d = a;
        Fixed &e = c;
        std::cout << "min(" << c << ", " << b << ") = " << Fixed::min(c, b) << std::endl;
        std::cout << "max(" << c << ", " << b << ") = " << Fixed::max(c, b) << std::endl;
        std::cout << "min(" << e << ", " << d << ") = " << Fixed::min(e, d) << std::endl;
        std::cout << "max(" << e << ", " << d << ") = " << Fixed::max(e, d) << std::endl << std::endl;
        return 0;
    }
}