/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:00:27 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 19:32:29 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base() {
    std::cout << "Base: Destructor" << std::endl;
}

Base * generate(void) {
	// srand(time(0));
	int n = rand() % 3;
	if (n == 0)
	{
		std::cout << "generating a new C" << std::endl;
		return new C;
	}
	if (n == 1)
	{
		std::cout << "generating a new B" << std::endl;
		return new B;
	}
	std::cout << "generating a new A" << std::endl;
	return new A;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else 
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception const& e) {}
	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception const& e) {}
	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception const& e) {}
	std::cout << "Unknown type" << std::endl;
}
