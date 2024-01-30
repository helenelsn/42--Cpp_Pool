/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:19:03 by hlesny            #+#    #+#             */
/*   Updated: 2024/01/30 21:52:01 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
    Harl h;

    if (argc != 2)
    {
        std::cout << "Invalid amount of arguments. Only one is needed. Please complain better" << std::endl;
        return 0;
    }
    h.complain(std::string(argv[1]));

    return (0);
}