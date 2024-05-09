/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:42:04 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/02 18:36:02 by hlesny           ###   ########.fr       */
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
        Point(float const x, float const y);
        Point(Point const& to_copy);
        Point &operator=(Point const& u);
        bool operator==(Point const& u);
        Fixed get_x(void) const;
        Fixed get_y(void) const;
        ~Point();

    private :
        const Fixed _x;
        const Fixed _y;
};

std::ostream& operator<<(std::ostream& out, Point const& p);

#endif