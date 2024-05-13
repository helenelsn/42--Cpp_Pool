/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:17:34 by Helene            #+#    #+#             */
/*   Updated: 2024/05/14 00:25:01 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLA_HPP
# define CLA_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stack>

class Rpn
{
    protected :
        /* Data */
    
    private :
        std::string _rpn;

	public :
		Rpn(std::string rpn); // quelle valeur par défuat ?
        Rpn(const Rpn& other);
        Rpn &operator=(const Rpn& other);
        ~Rpn();
        void processOperation(void) const;
        class incorrectOperator : public std::exception
        {
            public :
                const char *what() const throw() {
                    return "Error : incorrect operator.";
                }
        };
        class forbiddenOperation : public std::exception 
        {
            public :
                const char *what() const throw() {
                    return "Error : operation impossible.";
                }
        };
        class wrongRpnFormat : public std::exception 
        {
            public :
                const char *what() const throw() {
                    return "Error : Expression is not a valid Rpn format";
                }
        };
};

#endif