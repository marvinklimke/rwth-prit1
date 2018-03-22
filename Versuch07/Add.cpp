/*
 * Add.cpp
 *
 *  Created on: 02.05.2016
 *      Author: mklimke
 */

/**
 * \file Add.cpp
 * \brief This file contains the method definitions for Add-class.
 */

#include "Add.h"

Add::Add(Expression* summand1, Expression* summand2) : left(summand1), right(summand2)
{
}

Add::~Add()
{
	delete left;
	delete right;
}

double Add::evaluate() const
{
	return left->evaluate() + right->evaluate();
}

std::string Add::print() const
{
	return ("( " + left->print() + " + " + right->print() + " )");
}
