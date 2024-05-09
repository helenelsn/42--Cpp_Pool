/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:01:35 by Helene            #+#    #+#             */
/*   Updated: 2024/05/09 20:12:17 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <vector>
#include <cmath>


int main()
{
    // std::vector<int> vector {2, 4, 8, 2};
    std::vector<int> vector;
    int n = 5;
    
    for (int i = 0; i < n; i++)
        vector.push_back(pow(2, i));

    for (int i = 0; i < pow(2, n); i++)
    {
        try {
            easyfind(vector, i);
            std::cout << i << " found in container" << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl; }
    }
        
    // try {
    //     easyfind(vector, 2);
    //     std::cout << ""
    // }
    // catch (std::exception &e) {
    //     std::cerr << e.what() << std::endl; }
    
    
    // try {
    //     easyfind(vector, 3);
    // }
    // catch (std::exception &e) {
    //     std::cerr << e.what() << std::endl; }

    return 0;
}