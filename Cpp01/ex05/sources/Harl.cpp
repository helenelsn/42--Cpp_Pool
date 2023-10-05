/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:07:59 by hlesny            #+#    #+#             */
/*   Updated: 2023/10/05 17:14:51 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl()
{
    
}

Harl::~Harl()
{
    
}

void	Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money";
    std::cout << "You did not put enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.";
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

size_t  getIndex(std::string level)
{
    size_t index;
    std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (index = 0; index < 4; index++)
    {
        if (level == str[index])
            return (index);
    }
    return (index);
}

void Harl::complain( std::string level )
{
    void (Harl::*f)(void);
    switch (getIndex(level))
    {
        case 0:
            f = &Harl::debug;
            break;
        case 1:
            f = &Harl::info;
            break;
        case 2:
            f = &Harl::warning;
            break;
        case 3:
            f = &Harl::error;
            break;
        default:
            std::cout << "Not a HARL level. Try again." << std::endl;
            f = NULL;
    }
    if (f)
        (this->*f)();
}
