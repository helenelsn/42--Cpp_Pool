/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:33:55 by Helene            #+#    #+#             */
/*   Updated: 2024/05/12 01:02:16 by Helene           ###   ########.fr       */
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
    // p.vectorSort();
    p.listSort();


    // std::list<int> test;
    // test.push_back(10);
    // test.push_back(5);
    // for (std::list<int>::iterator it = test.begin(); it != test.end(); it++)
    //     std::cout << *it << std::endl;
    
    // // std::move(test.end(), test.end(), test.begin());
    // test.splice(test.begin(), test, ++test.begin());
    // for (std::list<int>::iterator it = test.begin(); it != test.end(); it++)
    //     std::cout << *it << std::endl;
    
    
    return 0;
}