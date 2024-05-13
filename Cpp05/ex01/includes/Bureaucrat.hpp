/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:27:26 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 01:50:03 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    protected :
        /* Data */
    
    private :
        const std::string _name;
        int _grade;

	public :
		Bureaucrat(std::string const& name = "Baca", int const& grade = 150);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat& other);
        const std::string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form const& form) const;
        ~Bureaucrat();
        class GradeTooLowException : public std::exception
        {
            public :
                const char *what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public :
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &flux, Bureaucrat &someone);

#endif