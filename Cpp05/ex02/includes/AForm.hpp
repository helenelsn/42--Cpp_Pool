/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:26:06 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 02:08:48 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    
    protected :
        std::string const _name;
        std::string _target;
        bool _isSigned;
        int const _gradeToSign;
        int const _gradeToExec;

	public :
		AForm(std::string const& name = "default form", std::string const& target = "default target", int gradeToSign = 80, int gradeToExec = 20);
        AForm(const AForm& other);
        AForm &operator=(const AForm& other);
        std::string const getName() const;
        std::string const getTarget() const;
        bool isItSigned() const;
        int whichGradeToSign() const;
        int whichGradeToExec() const;
        void beSigned(Bureaucrat const& b);
        void checkRequirements(Bureaucrat const& b) const;
        virtual void execute(Bureaucrat const & executor) const = 0;
        virtual ~AForm();
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
        class FormIsntSignedException : public std::exception
        {
            public :
                virtual const char *what() const throw(); // virtual ?
        };
};

std::ostream &operator<<(std::ostream &flux, AForm const& form);

#endif