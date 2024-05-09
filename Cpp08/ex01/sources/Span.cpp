/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:36:01 by hlesny            #+#    #+#             */
/*   Updated: 2024/05/09 23:37:10 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(unsigned int n) : _max(n)
{
	std::cout << "Span: Default constructor" << std::endl;
}

Span::Span(const Span& other) {

	std::cout << "Span: Copy constructor" << std::endl;
}

Span& Span::operator=(const Span& other) {
    
	std::cout << "Span: Assignment operator" << std::endl;
	return *this;
}

Span::~Span() {
    std::cout << "Span: Destructor" << std::endl;
}