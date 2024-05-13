/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 02:22:28 by Helene            #+#    #+#             */
/*   Updated: 2024/05/13 15:49:09 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(/* args */)
{
	std::cout << "Intern: Default constructor" << std::endl;
}

Intern::Intern(const Intern& other) {

	std::cout << "Intern: Copy constructor" << std::endl;
	(void) other;
}

Intern& Intern::operator=(const Intern& other) {
    
	std::cout << "Intern: Assignment operator" << std::endl;
	(void) other;
	return *this;
}

const char *Intern::FormDoesNotExist::what() const throw()
{
	return "The required form does not match any existing form";
}

AForm *Intern::newPPF(std::string const& target) const {
	return new PresidentialPardonForm(target);
}

AForm *Intern::newRRF(std::string const& target) const {
	return new RobotomyRequestForm(target);
}

AForm *Intern::newSCF(std::string const& target) const {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string const& name, std::string const& target) const {
	AForm * (Intern::*forms_ptrs[3])(std::string const&) const = {&Intern::newSCF, &Intern::newRRF, &Intern::newPPF};
	
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int form_id = -1 + 1 * (name == forms[0]) + 2 * (name == forms[1]) + 3 * (name == forms[2]);
	if (form_id < 0)
		throw FormDoesNotExist();
	else
		return (this->*forms_ptrs[form_id])(target);
}

Intern::~Intern() {
    std::cout << "Intern: Destructor" << std::endl;
}