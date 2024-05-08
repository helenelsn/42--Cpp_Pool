/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:37:21 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 18:40:39 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    
    ScalarConverter::convert(argv[1]);
    return 0;
}