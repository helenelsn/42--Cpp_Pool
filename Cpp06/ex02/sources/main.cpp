/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:31:14 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 19:28:50 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

int main()
{
    Base *b;
    for (int i = 0; i < 30; i++)
    {
        b = generate();
        identify(b);
        delete b;
    }

    std::cout << std::endl << std::endl;
    
    Base *b2 = generate();
    Base &b3 = *b2;
    identify(b3);

    delete b2;
    return 0;
}