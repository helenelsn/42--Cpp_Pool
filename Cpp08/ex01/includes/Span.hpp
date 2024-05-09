/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:25:06 by Helene            #+#    #+#             */
/*   Updated: 2024/05/09 21:03:17 by Helene           ###   ########.fr       */
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
		Span();
        Span(const Span& other);
        Span &operator=(const Span& other);
        void addNumber(); // add a single member to the span
        virtual ~Span();
};

#endif