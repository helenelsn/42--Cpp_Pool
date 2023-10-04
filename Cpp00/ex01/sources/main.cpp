/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:47:39 by Helene            #+#    #+#             */
/*   Updated: 2023/10/03 22:24:59 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"



int main(void)
{
    std::string userInput;
    PhoneBook phoneBook; /* quel constructeur ?*/
    
    std::cout << "Welcome to this phonebook reenactment. This program only accepts ADD, SEARCH and EXIT" << std::endl;
    do
    {
        std::cout << ">";
        getline(std::cin, userInput);
        if (userInput != "ADD" && userInput != "SEARCH" && userInput != "EXIT")
            std::cout << "Not a valid command. Please try again." << std::endl;
        else
        {
            if (userInput == "ADD")
                phoneBook.addContact();
            else if (userInput == "SEARCH")
                phoneBook.searchContact();  
        }
    } while (userInput != "EXIT");
    std::cout << "Exiting this shitty phonebook" << std::endl;
    
    return (0);
}