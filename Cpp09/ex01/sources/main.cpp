/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:08:32 by Helene            #+#    #+#             */
/*   Updated: 2024/05/12 02:18:45 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char **argv)
{

    if (argc != 2)
        return 0;
        
    Rpn test(argv[1]);
    try {
        test.processOperation();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}