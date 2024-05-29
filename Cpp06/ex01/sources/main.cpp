/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:58:02 by Helene            #+#    #+#             */
/*   Updated: 2024/05/29 14:51:26 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main()
{
    Data data = {1, -1};

    // Serializer s;

    std::cout << "Data values before serialization : " << data.x << ", " << data.y << std::endl;
    
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "---- Serializing data... ----" << std::endl;
    Data *bis = Serializer::deserialize(raw);
    std::cout << "---- Deserializing data... ----" << std::endl;

    std::cout << "Data values after serialization : " << bis->x << ", " << bis->y << std::endl;
    
    
    return 0;
}