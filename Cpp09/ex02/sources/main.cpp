/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:33:55 by Helene            #+#    #+#             */
/*   Updated: 2024/05/12 23:33:30 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// the program must use an integer sequance as argument


void recursiveInsertionTest(std::vector<int> input)
{
    std::vector<int> ordered;
    bool stopSearch = false;
    
    for (size_t i = 0; i < input.size(); i++)
	{
		stopSearch = false;        
		for (std::vector<int>::iterator it = ordered.begin(); it != ordered.end() && !stopSearch; it++)
			if (*it > input[i])
			{
				ordered.insert(it, input[i]); // it + 1 ?
				stopSearch = true;
			}
		if (!stopSearch)
			ordered.push_back(input[i]);
	}


    for (size_t i = 0; i < ordered.size(); i++)
        std::cout << ordered[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 0;
    
    // parser pour etre sur qu'il n'y a que des unsigned int passés en argument ?

    PmergeMe p(argc, argv);
    
    return 0;
}