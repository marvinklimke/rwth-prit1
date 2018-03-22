/*
 * Sqrt.cpp
 *
 *  Created on: 04.05.2016
 *      Author: mklimke
 */

/**
 * \file Sqrt.cpp
 * \brief This file contains the method definitions for Sqrt-class.
 */

#include "Sqrt.h"
#include <math.h>

Sqrt::Sqrt(Expression* discriminant) : diskr(discriminant)
{
}

Sqrt::~Sqrt()
{
	delete diskr;
}

double Sqrt::evaluate() const
{
	return sqrt(diskr->evaluate());
}

std::string Sqrt::print() const
{
	return ("sqrt( " + diskr->print() + " )");
}
