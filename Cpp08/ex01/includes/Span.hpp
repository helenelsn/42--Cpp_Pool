/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:25:06 by Helene            #+#    #+#             */
/*   Updated: 2024/05/10 12:59:03 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Span
{
    protected :
        /* Data */
    
    private :
        unsigned int _maxStorage; // loose the const here ?
        size_t _size;
        std::vector<int> _vec;

	public :
		Span(unsigned int n = 1);
        Span(const Span& other);
        Span &operator=(const Span& other);
        virtual ~Span();
        
        size_t getSize(void) const;
        unsigned int getStorage(void) const;
        std::vector<int> getVec(void) const;
        void checkStorage(void) const;
        void addNumber(int const& n); // add a single member to the span
        size_t shortestSpan() const;
        size_t longestSpan() const;
        
        template<typename Inputit>
        void addNumbers(Inputit begin, Inputit end) {
            int valueType;
            for (Inputit it = begin; it != end; it++)
            {
                if (typeid(*it) != typeid(valueType))
                    throw InvalidType();
            }
            if ((size_t)std::distance(begin, end) > _maxStorage - _size)
                throw ArrayIsFull();
            _vec.insert(_vec.end(), begin, end);
            _size += std::distance(begin, end);
        }
        class InvalidType : public std::exception {
            public : 
                const char *what() const throw() {
                    return "Error : not an int";
                }
        };
        class InvalidSpan : public std::exception {
            public :
                const char *what() const throw() {
                    return "Error : Invalid span : not enough stored values";
                }
        };
        class ArrayIsFull : public std::exception {
            public :
                const char *what() const throw() {
                    return "Error : max amount of storage would be exceeded";
                }
        };
};

#endif