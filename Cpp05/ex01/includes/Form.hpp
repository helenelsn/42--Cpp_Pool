/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:26:06 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 00:59:38 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    protected :
        /* Data */
    
    private :
        std::string const _name;
        bool _isSigned;
        int const _gradeToSign;
        int const _gradeToExec;

	public :
		Form(std::string const& name = "default form", int gradeToSign = 80, int gradeToExec = 20);
        Form(const Form& other);
        Form &operator=(const Form& other);
        std::string const getName() const;
        bool isItSigned() const;
        int whichGradeToSign() const;
        int whichGradeToExec() const;
        void beSigned(Bureaucrat const& b);
        virtual ~Form();
        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw(); // virtual ?
        };
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char *what() const throw(); // virtual ?
        };
};

std::ostream &operator<<(std::ostream &flux, Form const& form);

#endif