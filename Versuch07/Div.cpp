/*
 * Div.cpp
 *
 *  Created on: 03.05.2016
 *      Author: mklimke
 */

/**
 * \file Div.cpp
 * \brief This file contains the method definitions for Div-class.
 */

#include "Div.h"

Div::Div(Expression *dividend, Expression *divisor) : left(dividend), right(divisor)
{
}

Div::~Div()
{
	delete left;
	delete right;
}

double Div::evaluate() const
{
	return left->evaluate() / right->evaluate();
}

std::string Div::print() const
{
	return ("( " + left->print() + " / " + right->print() + " )");
}
