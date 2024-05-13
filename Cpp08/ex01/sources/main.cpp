/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 03:12:49 by Helene            #+#    #+#             */
/*   Updated: 2024/05/14 00:01:06 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(-1);
    sp.addNumber(19);
    sp.addNumber(4);
    sp.addNumber(11);
    std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
    std::cout << "longest span : " << sp.longestSpan() << std::endl;

    Span other = Span(15000);
    std::vector<int> v1;
    int t1[10000];
    for (int i = 0; i < 10000; i++)
    {
        v1.push_back(i);
        t1[i] = 10000 + i;
    }
    
    try {
        std::cout << "shortest span : " << other.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "longest span : " << other.longestSpan() << std::endl << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        other.addNumbers(v1.begin(), v1.end());
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "shortest span : " << other.shortestSpan() << std::endl;
    std::cout << "longest span : " << other.longestSpan() << std::endl << std::endl;
    try {
        other.addNumbers(t1, t1 + 10000);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "shortest span : " << other.shortestSpan() << std::endl;
    std::cout << "longest span : " << other.longestSpan() << std::endl << std::endl;
    try {
        other.addNumbers(t1, t1 + 5000);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "shortest span : " << other.shortestSpan() << std::endl;
    std::cout << "longest span : " << other.longestSpan() << std::endl << std::endl;

    return 0;
}