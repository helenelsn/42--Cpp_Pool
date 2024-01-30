/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:16:12 by Helene            #+#    #+#             */
/*   Updated: 2024/01/30 21:44:18 by hlesny           ###   ########.fr       */
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
    else if (std::string(argv[1]).empty())
    {
        std::cout << "String s1 should not be empty!" << std::endl;
        return (PARSE_ERROR);
    }
    
    std::ifstream file(argv[1]);
    std::ofstream fileReplace((std::string(argv[1]).append(".replace")).c_str());
    
    std::string line;
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    bool flag = false;
    
    std::string inString;
    while (std::getline(file, line))
    {
        if (flag)
            inString.append("\n");
        else
            flag = true;
        inString.append(line);
    }
    
    size_t index = inString.find(s1);
    while (index != std::string::npos)
    {
        inString.erase(index, s1.length());
        inString.insert(index, s2);
        index = inString.find(s1, index + 1);
    }
    fileReplace << inString;

}