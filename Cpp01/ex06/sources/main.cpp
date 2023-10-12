/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:19:03 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/12 16:08:08 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
    Harl h;

    if (argc != 2)
    {
        std::cout << "Invalid amount of arguments. Only one is needed. Please complain better" << std::endl;
    }
    h.complain(std::string(argv[1]));

    return (0);
}