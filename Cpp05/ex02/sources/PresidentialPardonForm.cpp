/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:50:02 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 02:05:26 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
: AForm("Presidential pardon", target, 25, 5)
{
	std::cout << "PresidentialPardonForm: Default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
: AForm(other.getName(), other.getTarget(), 25, 5)
{
	std::cout << "PresidentialPardonForm: Copy constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    
	std::cout << "PresidentialPardonForm: Assignment operator" << std::endl;
	_isSigned = other.isItSigned();
	_target = other.getTarget();
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkRequirements(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm: Destructor" << std::endl;
}