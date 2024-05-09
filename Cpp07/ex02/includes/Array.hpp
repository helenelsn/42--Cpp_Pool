#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template<class T>
class Array
{
    protected :
        /* Data */
    
    private :
        T *_array;
        unsigned int _size;

	public :
        Array(unsigned int n = 0);
        Array(const Array& other);
        Array &operator=(const Array& other);
        virtual ~Array();
        T& operator[](unsigned int index) const;
        unsigned int size(void) const;
        class OutOfBoundsException : public std::exception
        {
            public :
                char const* what() const throw();
        };
};

template<typename T>
std::ostream& operator<<(std::ostream& flux, Array<T> const& tab) {
    flux << "array = {" ;
    for (unsigned int i = 0; i < tab.size(); i++)
    {
        flux << tab[i] ;
        if (i + 1 != tab.size())
            flux << ", " ;
    }
    flux << "}" << std::endl;
        return flux;
}

template<typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Error : Out of bounds index";
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(const Array& other) : _array(new T(other.size())), _size(other.size()) { // pourquoi est ce que sans ca ca couille ?
    *this = other;
}

template<typename T>
unsigned int Array<T>::size(void) const {
    return _size;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T>& other) {
    delete [] _array;
    _size = other.size();
    _array = new T[_size]; // _array = Array<T>::Array(_size); ? 
    for (size_t i = 0; i < _size; i++)
        _array[i] = other._array[i];
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) const {
    if (index >= _size) // throw an exception ?
		throw OutOfBoundsException();
	return _array[index];
}

template<typename T>
Array<T>::~Array() {
    delete [] _array;
}

#endif