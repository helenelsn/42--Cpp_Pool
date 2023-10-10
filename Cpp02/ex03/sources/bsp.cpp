/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:50:08 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/08 16:57:55 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Fixed   getw1(Point const& x, Point const& y, Point const& z, Point const& point)
{
    return (
        ((x.get_x()).toFloat() * ((z.get_y()).toFloat() - (x.get_y()).toFloat()) + ((point.get_y()).toFloat() - (x.get_y()).toFloat()) * ((z.get_x()).toFloat() - (x.get_x()).toFloat())
        - ((point.get_x()).toFloat() * ((z.get_y()).toFloat() - (x.get_y()).toFloat()))) 
        / ( ((y.get_y()).toFloat() - (x.get_y()).toFloat()) * ((z.get_x()).toFloat() - (x.get_x()).toFloat()) - ((y.get_x()).toFloat() - (x.get_x()).toFloat()) * ((z.get_y()).toFloat() - (x.get_y()).toFloat()))
    );
}

Fixed   getw2(Point const& x, Point const& y, Point const& z, Point const& point, float const w1)
{
    return (
        ((point.get_y()).toFloat() - (x.get_y()).toFloat() - ((y.get_y()).toFloat() - (x.get_y()).toFloat()) * w1)
        / ((z.get_y()).toFloat() - (x.get_y()).toFloat())
    );
}

float  computeSignToNormal(Point const& a, Point const& b, Point const& x)
{
    return (( x.get_x().toFloat() - a.get_x().toFloat() ) 
            * ( b.get_y().toFloat() - a.get_y().toFloat() ) 
            - ((x.get_y().toFloat() - a.get_y().toFloat())
            * (b.get_x().toFloat() - a.get_x().toFloat()) ));
}

/*
compute d = <x - x1, y - y1> * <y2 - y1, -(x2 - x1)>
if d = 0, the point P(x,y) lies exactly on the line AB, A(x1,y1), B(x2,y2)
*/

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

bool    bsp( Point const& x, Point const& y, Point const& z, Point const& point)
{
    return (OnSameSide(x, y, z, point) && OnSameSide(y, z, x, point) && OnSameSide(z, x, y, point));
}