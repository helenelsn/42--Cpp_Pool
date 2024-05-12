/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:42:58 by Helene            #+#    #+#             */
/*   Updated: 2024/05/12 16:04:11 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"



int main(int argc, char **argv)
{

    if (argc != 2)
        return 0;
    
    (void)argv;

    BitcoinExchange btc;
    btc.getCurrencyValues(argv[1]); // meh, moche
    
}