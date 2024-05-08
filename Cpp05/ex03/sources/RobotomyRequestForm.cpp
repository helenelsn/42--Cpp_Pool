/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:51:18 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 02:04:52 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
: AForm("Robotomy request", target, 72, 45)
{
	std::cout << "RobotomyRequestForm: Default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
: AForm(other.getName(), other.getTarget(), 72, 45)
{

	std::cout << "RobotomyRequestForm: Copy constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    
	std::cout << "RobotomyRequestForm: Assignment operator" << std::endl;
	_isSigned = other.isItSigned();
	_target = other.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkRequirements(executor);
	std::cout << "*DRILLING NOISES*" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been successfully robotomized." << std::endl;
	else 
		std::cout << "robotomisation on " << _target << " failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm: Destructor" << std::endl;
}