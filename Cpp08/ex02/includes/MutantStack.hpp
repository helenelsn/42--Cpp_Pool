/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:02:29 by Helene            #+#    #+#             */
/*   Updated: 2024/05/10 19:13:43 by Helene           ###   ########.fr       */
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
        // class StackIt 
        // {
        //     private :
        //         pointer m_ptr;
                
        //     public : 
        //         using iterator_category = std::bidirectional_iterator_tag;
        //         using difference_type   = std::ptrdiff_t;
        //         using value_type        = T;
        //         using pointer           = value_type*;
        //         using reference         = value_type&;
                
        //         StackIt(pointer ptr = nullptr) : m_ptr(ptr) {}
        //         StackIt(StackIt const& StackIt) {} // idk
                
        //         reference operator*() void {
        //             return *m_ptr;
        //         }
        //         pointer operator->() void {
        //             return m_ptr;
        //         }
        //         StackIt& operator++() { m_ptr++; return m_ptr; }
        //         StackIt& operator--() { m_ptr--; return m_ptr; }
        //         StackIt operator++(int) { pointer tmp = m_ptr; m_ptr++; return tmp; }
        //         StackIt operator--(int) { pointer tmp = m_ptr; m_ptr--; return tmp; }
        // }
};

#endif