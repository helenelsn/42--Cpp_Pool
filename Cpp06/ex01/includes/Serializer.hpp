/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:40:48 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 16:11:47 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "stdint.h"
#include "Data.hpp"

class Serializer
{
    protected :
        /* Data */
    
    private :
        /* Data */

	public :
		Serializer();
        Serializer(const Serializer& other);
        Serializer &operator=(const Serializer& other);
        virtual ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif