#pragma once
#ifndef CLA_HPP
# define CLA_HPP

#include <iostream>
#include <string>

class Example
{
    protected :
        /* Data */
    
    private :
        /* Data */

	public :
		Example();
        Example(const Example& other);
        Example &operator=(const Example& other);
        virtual ~Example();
};

#endif