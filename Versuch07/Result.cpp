/*
 * Result.cpp
 *
 *  Created on: 02.05.2016
 *      Author: mklimke
 */

/**
 * \file Result.cpp
 * \brief This file contains the method definitions for Result-class.
 */

#include "Result.h"

Result::Result(Expression* op) : operand(op)
{
}

Result::~Result()
{
	delete operand;
}

double Result::evaluate() const
{
	return operand->evaluate();
}

std::string Result::print() const
{
	return operand->print();
}
