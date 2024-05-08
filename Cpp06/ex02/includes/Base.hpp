/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:55:00 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 19:39:16 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

class Base
{
    public :
        virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif