/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:26:03 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 00:37:26 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(std::string const& name, int gradeToSign, int gradeToExec)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form: Default constructor" << std::endl;
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException(); // pourquoi est-ce que le 'Form::' n'est pas nécessaire ?
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException(); // idem (?)
}

Form::Form(const Form& other) 
: _name(other.getName()), _isSigned(other.isItSigned()), _gradeToSign(other.whichGradeToSign()), _gradeToExec(other.whichGradeToExec())
{
	std::cout << "Form: Copy constructor" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form& other) {
    
	std::cout << "Form: Assignment operator" << std::endl;
	_isSigned = other.isItSigned();
	return *this;
}

Form::~Form() {
    std::cout << "Form: Destructor" << std::endl;
}

std::string const Form::getName() const {
	return _name;
}

bool Form::isItSigned() const {
	return _isSigned;
}

int Form::whichGradeToSign() const {
	return _gradeToSign;
}

int Form::whichGradeToExec() const {
	return _gradeToExec;
}

void Form::beSigned(Bureaucrat const& b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	b.signForm(*this);
}

const char *Form::GradeTooLowException::what() const throw() {
	return "The form's required grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "The form's required grade is too high";
}

std::ostream &operator<<(std::ostream &flux, Form const& form) {
	flux << "Form " << form.getName() << (form.isItSigned() ? " is signed" : "is not signed") << std::endl ;
	flux << "Grade required to sign it : " << form.whichGradeToSign() << std::endl ;
	flux << "Grade required to execute it : " << form.whichGradeToExec() ;
	return flux;
}