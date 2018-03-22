/*
 * Mul.cpp
 *
 *  Created on: 03.05.2016
 *      Author: mklimke
 */

/**
 * \file Mul.cpp
 * \brief This file contains the method definitions for Mul-class.
 */

#include "Mul.h"

Mul::Mul(Expression *factor1, Expression *factor2) : left(factor1), right(factor2)
{
}

Mul::~Mul()
{
	delete left;
	delete right;
}

double Mul::evaluate() const
{
	return left->evaluate() * right->evaluate();
}

std::string Mul::print() const
{
	return ("( " + left->print() + " * " + right->print() + " )");
}
