/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:36:01 by hlesny            #+#    #+#             */
/*   Updated: 2024/05/29 15:48:29 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(unsigned int n) : _maxStorage(n), _size(0), _vec()
{
	std::cout << "Span: Default constructor" << std::endl;
}

Span::Span(const Span& other)
// : _maxStorage(other._maxStorage), _size(other.getSize()), _vec(other._vec)
{
	std::cout << "Span: Copy constructor" << std::endl;
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	std::cout << "Span: Assignment operator" << std::endl;
	_maxStorage = other.getStorage();
	_size = other.getSize();
	_vec = other.getVec();
	return *this;
}

Span::~Span() {
    std::cout << "Span: Destructor" << std::endl;
}

unsigned int Span::getStorage(void) const {
	return _maxStorage;
}

size_t Span::getSize(void) const {
	return _size;
}

std::vector<int> Span::getVec(void) const {
	return _vec;
}

void Span::addNumber(int const& n) {
	if (_size == _maxStorage)
		throw ArrayIsFull();
	_size++;
	_vec.push_back(n);
}

void Span::checkStorage(void) const {
	if (_size < 2)
		throw InvalidSpan();
}

size_t Span::shortestSpan() const {
	checkStorage();
	std::vector<int> vec = _vec;
	std::sort(vec.begin(), vec.end());
	
	// std::cout << "{ " ;
	// for (size_t i = 0; i < _vec.size(); i++)
	// 	std::cout << vec[i] << ", " ;
	// std::cout << "} " << std::endl;

	size_t minDist = UINT_MAX;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it !=  vec.begin() && (size_t) std::abs(*it - *(it - 1)) < minDist)
			minDist = std::abs(*it - *(it - 1));
		// std::cout << "vec[" << i << "] = " << _vec[i] << ", vec[" << i - 1 << "] = " << _vec[i - 1] << std::endl;
		
		// std::cout << "i = " << i << ", min dist = " << minDist << std::endl;
	}
	
	return minDist;
}

size_t Span::longestSpan() const {
	checkStorage();
	int max = *std::max_element(_vec.begin(), _vec.end());
	int min = *std::min_element(_vec.begin(), _vec.end());
	std::cout << "max = " << max << ", min = " << min << std::endl;
	return std::abs(max - min);
}
