/*
 * Pow.cpp
 *
 *  Created on: 04.05.2016
 *      Author: mklimke
 */

/**
 * \file Pow.cpp
 * \brief This file contains the method definitions for Pow-class.
 */

#include "Pow.h"
#include <math.h>

Pow::Pow(Expression* base, Expression* exponent) : b(base), e(exponent)
{
}

Pow::~Pow()
{
	delete b;
	delete e;
}

double Pow::evaluate() const
{
	return pow(b->evaluate(), e->evaluate());
}

std::string Pow::print() const
{
	return ("( " + b->print() + " ^ " + e->print() + " )");
}
