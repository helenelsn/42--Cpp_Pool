/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:50:08 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/06 22:42:43 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

float   getw1(Point const x, Point const y, Point const z, Point const point)
{
    return (
        (x.get_x() * (z.get_y() - x.get_y()) + (point.get_y() - x.get_y()) * (z.get_x() - x.get_x())
        - (point.get_x() * (z.get_y() - x.get_y()))) 
        / ( (y.get_y() - x.get_y()) * (z.get_x() - x.get_x()) - (y.get_x() - x.get_x()) * (z.get_y() - x.get_y()))
    );
}

float   getw2(Point const x, Point const y, Point const z, Point const point, float const w1)
{
    return (
        (point.get_y() - x.get_y() - (y.get_y() - x.get_y()) * w1)
        / (z.get_y() - x.get_y())
    );
}

bool bsp( Point const x, Point const y, Point const z, Point const point)
{
    float w1;
    float w2;

    w1 = getw1(x, y, z, point);
    w2 = getw2(x, y, z, point, w1);
    
    return ((w1 > 0 && w2 > 0) && (w1 + w2 < 1));
}