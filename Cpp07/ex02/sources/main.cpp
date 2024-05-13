/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:39:58 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 20:49:47 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main()
{
    Array<int> emptyTab;
    Array<int> tab(6);
    Array<int>  test(tab);
        
    std::cout << "empty tab : " << emptyTab << std::endl; 
    std::cout << tab << std::endl; 
    tab[3] = 134;
    std::cout << tab << std::endl;
    
    try
    {
        tab[200] = 12;
        std::cout << "Uhuh, this should not be allowed" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << tab << std::endl; 

    Array<int> tab2 = tab;
    std::cout << "tab : " << tab << std::endl; 
    std::cout << "tab2 : " << tab2 << std::endl; 

    tab[tab.size() - 1] = -100;
    std::cout << "tab : " << tab << std::endl; 
    std::cout << "tab2 : " << tab2 << std::endl;
    
    return 0;
}