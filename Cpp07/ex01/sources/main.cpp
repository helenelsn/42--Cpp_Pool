/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:31:35 by Helene            #+#    #+#             */
/*   Updated: 2024/05/09 13:38:51 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main()
{
    
    int tab[3] = {2, 4, 8};
    
    for (size_t i = 0; i < 3; i++)
        print(tab[i]);
        
    std::cout << std::endl;
    
    iter(tab, 3, doubleValue<int>); 
    for (size_t i = 0; i < 3; i++)
        print(tab[i]);

    return 0;
}