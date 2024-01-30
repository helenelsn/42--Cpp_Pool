/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:02:22 by hlesny            #+#    #+#             */
/*   Updated: 2024/01/19 19:44:03 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
  	public :
    	Harl();
    	~Harl();
    	void complain( std::string level );

  	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif