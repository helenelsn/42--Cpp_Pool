/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:11:15 by hlesny            #+#    #+#             */
/*   Updated: 2024/05/13 16:00:22 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

int main (void)
{
    // print initial state of the three forms
     
     Bureaucrat bob("bob", 140);
     Bureaucrat alice("alice", 70);
     Bureaucrat boss("boss", 4);

    Intern it;
    AForm *scf = it.makeForm("ShrubberyCreationForm", "une belle feuille");
    AForm *ppf;
    try {
        ppf = it.makeForm("random form", "jsp");
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    ppf = it.makeForm("PresidentialPardonForm", "faf");
    AForm *rrf = it.makeForm("RobotomyRequestForm", "le trottoir");

     // --------------------------

     std::cout << std::endl << *ppf << std::endl << *rrf << std::endl << *scf << std::endl << std::endl;
    
    std::cout << std::endl << std::endl << " ------------------" << std::endl << std::endl;
    //ok
    try {
        bob.signForm(*scf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //exception
    try {
        bob.executeForm(*scf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //ok
    try {
        alice.executeForm(*scf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << *scf << std::endl << std::endl;

    //exception (not signed yet)
    try {
        alice.executeForm(*rrf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //ok
    try {
        alice.signForm(*rrf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //exception (grade too low to execute form)
    try {
        alice.executeForm(*rrf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //ok
    try {
        boss.executeForm(*rrf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << *rrf << std::endl << std::endl ;
    
    try {
        boss.signForm(*ppf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        boss.executeForm(*ppf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << *ppf << std::endl ;
     
    
    delete ppf;
    delete scf;
    delete rrf;

    return (0);
}