/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:48:53 by Helene            #+#    #+#             */
/*   Updated: 2023/10/08 15:34:20 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point()
:   _x(0),
    _y(0)
{}

Point::Point(double const x, double const y)
:   _x(x),
    _y(y)
{}

Point::Point(Point const& to_copy)
{
    *this = to_copy;
}

Point &Point::operator=(Point const& u)
{
    // _x = (Fixed)u.get_x();
    // _y = u._y;
    
    (void)u; // ??????????????
    return (*this);
}

bool Point::operator==(Point const& u)
{
    return (get_x() == u.get_x() && get_y() == u.get_y()); // pourquoi ca compile pas ?
}

Fixed Point::get_x(void) const
{
    return (_x);
}

Fixed Point::get_y(void) const
{
    return (_y);
}

Point::~Point()
{

}

std::ostream& operator<<(std::ostream& out, Point const& p)
{
    out << "( " << (p.get_x()).toFloat() << ", " << (p.get_y()).toFloat() << " )";
    return (out);
}
