/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:00:35 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/10 23:36:23 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{

	public :
		Brain();
        Brain(const Brain& other);
        Brain &operator=(const Brain& other);
        void    addIdea(std::string newIdea);
        void    printIdeas(void);
        virtual ~Brain();
    
    protected :
        size_t      _ideasCount;
        std::string _ideas[100];

    private :
		
};

#endif