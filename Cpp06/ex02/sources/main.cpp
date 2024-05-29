/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:31:14 by Helene            #+#    #+#             */
/*   Updated: 2024/05/29 14:48:43 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

int main()
{
Base *b;
    for (int i = 0; i < 30; i++)
    {
        b = generate();
        Base &b2 = *b;
        std::cout << "*p : ";
        identify(b);
        std::cout << "&p : ";
        identify(b2);
        delete b;
    }

    return 0;
}