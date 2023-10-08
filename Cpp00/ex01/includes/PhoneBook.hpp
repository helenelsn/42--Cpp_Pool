/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:41 by Helene            #+#    #+#             */
/*   Updated: 2023/10/08 15:12:21 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Contact.hpp"

# define PBOOK_SIZE	3

class PhoneBook {
    
    public :
		PhoneBook();
        void    addContact(void);
        void    displayContact(size_t index) const;
		void    displayPhoneBookSnippet(void) const;
		void 	searchContact(void) const;

    private :
        Contact	contacts[PBOOK_SIZE];
        size_t					count;
    
};

#endif