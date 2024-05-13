/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:11:15 by hlesny            #+#    #+#             */
/*   Updated: 2024/05/13 15:30:55 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main (void)
{

    ShrubberyCreationForm scf("jsp");
    RobotomyRequestForm rrf("le trottoir");
    PresidentialPardonForm ppf("fafs");

    // print initial state of the three forms
    std::cout << std::endl << ppf << std::endl << rrf << std::endl << scf << std::endl << std::endl;
     
     Bureaucrat bob("bob", 140);
     Bureaucrat alice("alice", 70);
     Bureaucrat boss("boss", 4);
    
    //ok
    try {
        bob.signForm(scf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //exception
    try {
        bob.executeForm(scf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //ok
    try {
        alice.executeForm(scf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << scf << std::endl << std::endl;

    //exception (not signed yet)
    try {
        alice.executeForm(rrf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //ok
    try {
        alice.signForm(rrf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //exception (grade too low to execute form)
    try {
        alice.executeForm(rrf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //ok
    try {
        boss.executeForm(rrf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << rrf << std::endl << std::endl ;
    
    try {
        boss.signForm(ppf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        boss.executeForm(ppf);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << ppf << std::endl ;
     

    return (0);
}