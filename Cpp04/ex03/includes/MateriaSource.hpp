#pragma once
#ifndef CLA_HPP
# define CLA_HPP

class Example
{

	public :
		Example();
        Example(const Example& other);
        Example &operator=(const Example& other);
        virtual ~Example();
    
    protected :

    private :
		
};

#endif