/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:33:51 by Helene            #+#    #+#             */
/*   Updated: 2024/05/12 17:16:01 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

Rpn::Rpn(std::string rpn)
: _rpn (rpn)
{
	std::cout << "Rpn: Default constructor" << std::endl;
}

Rpn::Rpn(const Rpn& other) {

	std::cout << "Rpn: Copy constructor" << std::endl;
	*this = other;
}

Rpn& Rpn::operator=(const Rpn& other) {
    
	std::cout << "Rpn: Assignment operator" << std::endl;
	_rpn = other._rpn;
	return *this;
}

Rpn::~Rpn() {
    std::cout << "Rpn: Destructor" << std::endl;
}

void doOp(std::stack<int> &stack, char op)
{
	if (stack.size() < 2)
		throw Rpn::wrongOperatorsOrder();
		
	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();

	switch (op) {
		case '+' :
		{
			stack.push(a + b);
			break;
		}
		case '-' :
		{
			stack.push(a - b);
			break;
		}
		case '/' :
		{
			if (!b)
				throw Rpn::forbiddenOperation();
			stack.push(a / b);
			break;
		}
		case '*' :
		{
			stack.push(a * b);
			break; 
		}
		default :
			throw Rpn::incorrectOperator();
	}
}

void Rpn::processOperation(void) const {
	std::stack<int> stack;
	
	for (size_t i = 0; i < _rpn.size(); i++)
	{
		for (; i < _rpn.size() && _rpn[i] == ' '; i++) {}
		if (isnumber(_rpn[i]))
			stack.push(atoi(&_rpn[i]));
		else
			doOp(stack, _rpn[i]);
	}

	std::cout << "result = " << stack.top() << std::endl;
}