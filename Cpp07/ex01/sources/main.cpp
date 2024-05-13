/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:31:35 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 20:46:44 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

/* int main() 
{
    int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
    Awesome tab2[5];
    iter( tab, 5, print);
    iter( tab2, 5, print<Awesome> );
    return 0;
} */

int main()
{
    
    int tab[3] = {2, 4, 8};

    Awesome aw[2];
    // iter(tab, 3, print<int>); 
    
    for (size_t i = 0; i < 3; i++)
        print(tab[i]);
        
    std::cout << std::endl;
    
    iter(tab, 3, doubleValue<int>); 
    for (size_t i = 0; i < 3; i++)
        print(tab[i]);

    return 0;
}