/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:42:04 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/06 19:52:37 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    public :
        Point();
        Point(double const x, double const y);
        Point(Point const& to_copy);
        Point &operator=(Point const& u);
        bool operator==()
        ~Point();

    private :
        const Fixed _x;
        const Fixed _y;
};


#endif