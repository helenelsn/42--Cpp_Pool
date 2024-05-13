/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 02:21:56 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 15:52:29 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    protected :
        /* Data */
    
    private :
        AForm *newPPF(std::string const& target) const;
        AForm *newRRF(std::string const& target) const;
        AForm *newSCF(std::string const& target) const;

	public :
		Intern();
        Intern(const Intern& other);
        Intern &operator=(const Intern& other);
        AForm *makeForm(std::string const& name, std::string const& target) const;
        virtual ~Intern();
        class FormDoesNotExist : public std::exception {
            public :
                virtual const char *what() const throw();
        };
};

#endif