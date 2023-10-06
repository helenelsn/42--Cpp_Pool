/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:27:19 by Helene            #+#    #+#             */
/*   Updated: 2023/10/06 18:45:53 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact()
:   firstName(""),
    lastName(""),
    nickname(""),
    phoneNumber(""),
    darkestSecret("")
{}

Contact::Contact(std::string fname, std::string lname, std::string nname, std::string number, std::string secret)
:   firstName(fname),
    lastName(lname),
    nickname(nname),
    phoneNumber(number),
    darkestSecret(secret)
{}

void	Contact::print(void) const
{
    std::cout << "First name : " << firstName << std::endl;
    std::cout << "Last name : " << lastName << std::endl;
    std::cout << "Nickname : " << nickname << std::endl;
    std::cout << "Phone number : " << phoneNumber << std::endl;
    std::cout << "Darkest secret : " << darkestSecret << std::endl;
}

std::string 	Contact::getFirstName(void) const
{
    return (firstName);
}

std::string 	Contact::getLastName(void) const
{
    return (lastName);
}

std::string 	Contact::getNickname(void) const
{
    return (nickname);
}