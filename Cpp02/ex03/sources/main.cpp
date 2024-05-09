/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:58:58 by hlesny            #+#    #+#             */
/*   Updated: 2024/02/02 20:51:12 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

bool bsp( Point const x, Point const y, Point const z, Point const point);

int main( void )
{
    
    /* Triangle */
    Point x(0.0, 0.0);
    //Point y(0.0, 5.0100f);
    Point y(0.0, 5.0);
    Point z(5.0, 0.0);

    /* Point to test */
   Point p(0, 1.12345f);
   //Point p(0.2f, 1.12345f);
   //Point p(2.495, 2.495);
    
    std::cout << "P " << p << " is";
    if (bsp(x, y, z, p))
        std::cout << " inside ";
    else 
        std::cout << " outside ";
    std::cout << "the triangle made of the points " << x << ", " << y << ", " << z << std::endl;
    
    return (0);
}