/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:52:01 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 02:03:50 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
: AForm("Shrubbery creation", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm: Default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
: AForm(other.getName(), other.getTarget(), 145, 137)
{
	std::cout << "ShrubberyCreationForm: Copy constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    
	std::cout << "ShrubberyCreationForm: Assignment operator" << std::endl;
	_isSigned = other.isItSigned();
	_target = other.getTarget();
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkRequirements(executor);
	std::string fileName = _target + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (! file.is_open())
		std::cerr << "Could not create " << fileName << std::endl;
	
	    file <<"                                         .         ;  " << std::endl;
        file <<"         .              .              ;%     ;;   " << std::endl;
        file <<"           ,           ,                :;%  %;   " << std::endl;
        file <<"            :         ;                   :;%;'     .," << std::endl;   
        file <<"   ,.        %;     %;            ;        %;'    ,;" << std::endl;
        file <<"     ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
        file <<"      %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
        file <<"       ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
        file <<"        `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
        file <<"         `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
        file <<"            `:%;.  :;bd%;          %;@%;'" << std::endl;
        file <<"              `@%:.  :;%.         ;@@%;'   " << std::endl;
        file <<"                `@%.  `;@%.      ;@@%;         " << std::endl;
        file <<"                  `@%%. `@%%    ;@@%;        " << std::endl;
        file <<"                    ;@%. :@%%  %@@%;       " << std::endl;
        file <<"                      %@bd%%%bd%%:;     " << std::endl;
        file <<"                        #@%%%%%:;;" << std::endl;
        file <<"                        %@@%%%::;" << std::endl;
        file <<"                        %@@@%(o);  . '         " << std::endl;
        file <<"                        %@@@o%;:(.,'         " << std::endl;
        file <<"                    `.. %@@@o%::;         " << std::endl;
        file <<"                       `)@@@o%::;         " << std::endl;
        file <<"                        %@@(o)::;        " << std::endl;
        file <<"                       .%@@@@%::;         " << std::endl;
        file <<"                       ;%@@@@%::;.          " << std::endl;
        file <<"                      ;%@@@@%%:;;;. " << std::endl;
        file <<"                  ...;%@@@@@%%:;;;;,..   " << std::endl;

		file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm: Destructor" << std::endl;
}