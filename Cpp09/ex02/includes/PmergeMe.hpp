/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:50:20 by Helene            #+#    #+#             */
/*   Updated: 2024/06/02 14:59:26 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <cmath>
#include <ctime>

class PmergeMe
{
    protected :
        /* Data */
    
    private :
        std::vector<int> _sequence;
        std::list<int> _listSequence;
        std::deque<int> _dequeSequence;

	public :
		PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe& other);
        ~PmergeMe();
        void sortSequences();
        void vectorSort();
        void listSort();
        void dequeSort();
        
};

#endif