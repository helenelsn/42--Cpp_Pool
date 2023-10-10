/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:00:35 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/10 20:02:07 by hlesny           ###   ########.fr       */
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
        virtual ~Brain();
    
    protected :
        std::string _ideas[100];

    private :
		
};

#endif