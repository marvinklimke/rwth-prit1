/*
 * Const.cpp
 *
 *  Created on: 02.05.2016
 *      Author: mklimke
 */

/**
 * \file Const.cpp
 * \brief This file contains the method definitions for Const-class.
 */

#include "Const.h"

Const::Const(double val) : value(val)
{
}

Const::~Const()
{
}

double Const::evaluate() const
{
	return value;
}

std::string Const::print() const
{
	std::ostringstream strs;
	strs << value;
	return strs.str();
}
