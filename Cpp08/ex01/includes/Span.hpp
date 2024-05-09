/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:25:06 by Helene            #+#    #+#             */
/*   Updated: 2024/05/09 23:46:35 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>

class Span
{
    protected :
        /* Data */
    
    private :
        unsigned int const _max; // loose the const here ?
        int *_values; // ?

	public :
		Span(unsigned int n = 1);
        Span(const Span& other);
        Span &operator=(const Span& other);
        void addNumber(); // add a single member to the span
        size_t shortestSpan() const;
        size_t longestSpan() const;
        virtual ~Span();
        class InvalidSpan : public std::exception {
            public :
                const char *what() const throw() {
                    return "Error : no span to be found";
                }
        };
};

#endif