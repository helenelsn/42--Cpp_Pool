/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:50:08 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/02 20:49:11 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

float  computeSignToNormal(Point const& a, Point const& b, Point const& x)
{
    return (( x.get_x().toFloat() - a.get_x().toFloat() ) 
            * ( b.get_y().toFloat() - a.get_y().toFloat() ) 
            - ((x.get_y().toFloat() - a.get_y().toFloat())
            * (b.get_x().toFloat() - a.get_x().toFloat()) ));
}

bool    OnSameSide(Point const& x, Point const& y, Point const& z, Point const& p)
{
    float   a1;
    float   a2;

    a1 = computeSignToNormal(x, y, p);
    // std::cout << "x = " << x << ", y = " << y << std::endl;
    // std::cout << "p = " << p << ", c = " << z << std::endl;
    // std::cout << "d(p) = " << a1 << std::endl;
    if (!a1)
        return (false);
    a2 = computeSignToNormal(x, y, z);
    // std::cout << "d(c) = " << a2 << std::endl;
    return ((a1 > 0 && a2 >= 0 ) || (a1 < 0 && a2 < 0));
}

bool    bsp( Point const x, Point const y, Point const z, Point const point)
{
    return (OnSameSide(x, y, z, point) && OnSameSide(y, z, x, point) && OnSameSide(z, x, y, point));
}