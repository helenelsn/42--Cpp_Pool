/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:31:14 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 15:32:59 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

int main()
{
    Base *b = generate();
    identify(b);
    Base *b2 = generate();
    Base &b3 = *b2;
    identify(b3);

    delete b;
    delete b2;
    return 0;
}