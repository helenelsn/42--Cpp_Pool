/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 02:21:56 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 03:12:17 by Helene           ###   ########.fr       */
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
        /* Data */

	public :
		Intern();
        Intern(const Intern& other);
        Intern &operator=(const Intern& other);
        AForm *newPPF(std::string const& target) const;
        AForm *newRRF(std::string const& target) const;
        AForm *newSCF(std::string const& target) const;
        AForm *makeForm(std::string const& name, std::string const& target) const;
        virtual ~Intern();
        class FormDoesNotExist : public std::exception {
            public :
                virtual const char *what() const throw();
        };
};

#endif