/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:03:26 by Helene            #+#    #+#             */
/*   Updated: 2023/10/03 22:39:10 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void    PhoneBook::addContact(void)
{
    std::string firstName = "";
    std::string lastName = "";
    std::string nickname = "";
    std::string number = "";
    std::string secret = "";
    std::string check = "n";

    do
    {
        std::cout << "Enter their first name" << std::endl;
        getline(std::cin, firstName);
        std::cout << "First name : " << firstName << ". Type again ? [y/n]" << std::endl;
        getline(std::cin, check);
    } while (check == "y" || firstName == "");

    do
    {
        std::cout << "Enter their last name" << std::endl;
        getline(std::cin, lastName);
        std::cout << "Last name : " << lastName << ". Type again ? [y/n]" << std::endl;
        getline(std::cin, check);
    } while (check == "y" || lastName == "");

    do
    {
        std::cout << "Enter their nickname" << std::endl;
        getline(std::cin, nickname);
        std::cout << "Nickname : " << nickname << ". Type again ? [y/n]" << std::endl;
        getline(std::cin, check);
    } while (check == "y" || nickname == "");

    do
    {
        std::cout << "Enter their phone number" << std::endl;
        getline(std::cin, number);
        std::cout << "Phone number : " << number << ". Type again ? [y/n]" << std::endl;
        getline(std::cin, check);
    } while (check == "y" || number == "");

    do
    {
        std::cout << "Enter their darkest secret" << std::endl;
        getline(std::cin, secret);
        std::cout << "Darkest secret : " << secret << ". Type again ? [y/n]" << std::endl;
        getline(std::cin, check);
    } while (check == "y" && secret == "");
    
    Contact newContact = Contact(firstName, lastName, nickname, number, secret);
    
    if (count + 1 < PBOOK_SIZE)
    {
        contacts[count] = newContact;
        (count)++;
    }
    else
    {
        for (int i = 0; i < PBOOK_SIZE - 1; i++)
            contacts[i] = contacts[i + 1];
        contacts[PBOOK_SIZE - 1] = newContact;
    }
}

/* Display the saved contacts as a list of 4 columns: index, first name, last
name and nickname. */
void    PhoneBook::displayPhoneBookSnippet(void) const
{
    std::string tmp = "";
    std::string dashes(44, '-');
    for (size_t i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i + 1;
        std::cout << "|";
        
        tmp = contacts[i].getFirstName().substr(0, 10);
        if (contacts[i].getFirstName().length() > 9)
            tmp[9] = '.';
        std::cout << std::setw(10) << tmp;
        std::cout << "|";

        tmp = contacts[i].getLastName().substr(0, 10);
        if (contacts[i].getLastName().length() > 9)
            tmp[9] = '.';
        std::cout << std::setw(10) << tmp;
        std::cout << "|";

        tmp = contacts[i].getNickname().substr(0, 10);
        if (contacts[i].getNickname().length() > 9)
            tmp[9] = '.';
        std::cout << std::setw(10) << tmp << std::endl;
        std::cout << dashes << std::endl;
    }
}

void    PhoneBook::searchContact(void) const
{
    std::string input;
    size_t      index;

    if (!count)
    {
        std::cout << "This phonebook is currently empty." << std::endl;
        return ;
    }
    
    PhoneBook::displayPhoneBookSnippet();
    std::cout << "Contact's index to print : " << std::endl;
    getline(std::cin, input);
    index = atoi(input.c_str()) - 1;
    
    if (index < 0 || index >= count)
        std::cout << "Invalid index." << std::endl;   
    else
        contacts[index].print();
}