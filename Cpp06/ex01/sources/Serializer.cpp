/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:41:10 by Helene            #+#    #+#             */
/*   Updated: 2024/05/08 19:27:07 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer(/* args */)
{
	std::cout << "Serializer: Default constructor" << std::endl;
}

Serializer::Serializer(const Serializer& other) {

	std::cout << "Serializer: Copy constructor" << std::endl;
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    
	std::cout << "Serializer: Assignment operator" << std::endl;
	(void)other;
	return *this;
}

Serializer::~Serializer() {
    std::cout << "Serializer: Destructor" << std::endl;
}

// Takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

// Takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t raw) {
	// Data *unraw = reinterpret_cast<Data*>(raw);
	return reinterpret_cast<Data*>(raw);
}
