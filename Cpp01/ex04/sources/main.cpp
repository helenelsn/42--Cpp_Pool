/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:16:12 by Helene            #+#    #+#             */
/*   Updated: 2023/10/04 20:37:53 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> /* std::fstream  */
#include <string> // c_str

#define PARSE_ERROR 1

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Invalid amount of arguments! 3 required." << std::endl;
        return (PARSE_ERROR);
    }
    
    std::fstream file;
    std::fstream fileReplace;
    file.open(argv[1], std::fstream::in | std::fstream::out);
    file.open(std::string(argv[1]).append(".replace"), std::fstream::in | std::fstream::out);
    
}