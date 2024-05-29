/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:02:29 by Helene            #+#    #+#             */
/*   Updated: 2024/05/29 15:53:20 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <cstddef>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{       
    public :
        MutantStack() : std::stack<T, Container>() {}
        MutantStack(const MutantStack& other) { *this = other; };
        MutantStack &operator=(const MutantStack& other) { std::stack<T, Container>::operator=(other); return *this; }
        ~MutantStack() {}
        
        typedef typename Container::iterator iterator;
        iterator begin() { return this->c.begin(); }
        iterator end() { return (*this).c.end(); }
};

#endif