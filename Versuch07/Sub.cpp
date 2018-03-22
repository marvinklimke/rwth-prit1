/*
 * Sub.cpp
 *
 *  Created on: 03.05.2016
 *      Author: mklimke
 */

/**
 * \file Sub.cpp
 * \brief This file contains the method definitions for Sub-class.
 */

#include "Sub.h"

Sub::Sub(Expression *minuend, Expression *subtrahend) : left(minuend), right(subtrahend)
{
}

Sub::~Sub()
{
	delete left;
	delete right;
}

double Sub::evaluate() const
{
	return left->evaluate() - right->evaluate();
}

std::string Sub::print() const
{
	return ("( " + left->print() + " - " + right->print() + " )");
}
