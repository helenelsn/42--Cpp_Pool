/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:26:03 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 02:00:25 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(std::string const& name, std::string const& target, int gradeToSign, int gradeToExec)
: _name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "AForm: Default constructor" << std::endl;
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException(); // pourquoi est-ce que le 'AForm::' n'est pas nécessaire ?
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException(); // idem (?)
}

AForm::AForm(const AForm& other) 
: _name(other.getName()), _isSigned(other.isItSigned()), _gradeToSign(other.whichGradeToSign()), _gradeToExec(other.whichGradeToExec())
{
	std::cout << "AForm: Copy constructor" << std::endl;
	*this = other;
}

AForm& AForm::operator=(const AForm& other) {
    
	std::cout << "AForm: Assignment operator" << std::endl;
	_isSigned = other.isItSigned();
	return *this;
}

AForm::~AForm() {
    std::cout << "AForm: Destructor" << std::endl;
}

std::string const AForm::getName() const {
	return _name;
}

bool AForm::isItSigned() const {
	return _isSigned;
}

int AForm::whichGradeToSign() const {
	return _gradeToSign;
}

int AForm::whichGradeToExec() const {
	return _gradeToExec;
}

std::string const AForm::getTarget() const {
	return _target;
}

void AForm::beSigned(Bureaucrat const& b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	b.signForm(*this);
}

void AForm::checkRequirements(Bureaucrat const& b) const {
	if (!_isSigned)
		throw FormIsntSignedException();
	if (b.getGrade() > _gradeToExec)
		throw GradeTooHighException();
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "The form's required grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "The form's required grade is too high";
}

const char *AForm::FormIsntSignedException::what() const throw() {
	return "The form is not signed yet";
}

std::ostream &operator<<(std::ostream &flux, AForm const& form) {
	flux << "Form " << form.getName() << (form.isItSigned() ? " is signed" : "is not signed") << std::endl ;
	flux << "Grade required to sign it : " << form.whichGradeToSign() << std::endl ;
	flux << "Grade required to execute it : " << form.whichGradeToExec() ;
	return flux;
}