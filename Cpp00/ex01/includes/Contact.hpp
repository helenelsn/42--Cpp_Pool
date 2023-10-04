/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:39:11 by Helene            #+#    #+#             */
/*   Updated: 2023/10/03 22:21:12 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>


class Contact{

    public :
        // Contact() /* Utile ?*/
        // :   firstName(""),
        //     lastName(""),
        //     nickname(""),
        //     phoneNumber(""),
        //     darkestSecret("")
        // {}
        Contact(std::string fname = "", std::string lname = "", std::string nname = "", std::string number = "", std::string secret = "")
        :   firstName(fname),
            lastName(lname),
            nickname(nname),
            phoneNumber(number),
            darkestSecret(secret)
        {}
        void			print(void) const;
		std::string 	getFirstName(void) const;
		std::string 	getLastName(void) const;
		std::string 	getNickname(void) const;
        
    private :
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif