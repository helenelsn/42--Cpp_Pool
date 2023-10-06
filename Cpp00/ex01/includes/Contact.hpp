/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:39:11 by Helene            #+#    #+#             */
/*   Updated: 2023/10/06 18:46:07 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>


class Contact{

    public :
        Contact();
        Contact(std::string fname, std::string lname, std::string nname, std::string number, std::string secret);
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