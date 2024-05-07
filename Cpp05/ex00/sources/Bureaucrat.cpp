/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:27:23 by Helene            #+#    #+#             */
/*   Updated: 2024/05/07 22:27:24 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const& name, int const& grade)
:	_name(name), _grade(grade)
{
	std::cout << "Bureaucrat: Default constructor" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {

	std::cout << "Bureaucrat: Copy constructor" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    
	std::cout << "Bureaucrat: Assignment operator" << std::endl;
	_grade = other.getGrade();
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat: Destructor" << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high";
}

std::ostream &operator<<(std::ostream &flux, Bureaucrat &someone) {
	flux << someone.getName() << ", bureaucrat grade " << someone.getGrade() << std::endl;
	return (flux);
}