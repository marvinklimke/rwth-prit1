/*
 * Result.h
 *
 *  Created on: 02.05.2016
 *      Author: mklimke
 */

/**
 * \file Result.h
 * \brief This file contains the class declaration of Result-class.
 */

#ifndef RESULT_H_
#define RESULT_H_

#include "expression.h"

/**
 * \brief Result-class
 * This class stores the result of an expression as a pointer to an expression
 */
class Result : public Expression
{

private:

	/**
	 * \brief pointer to the expression of the result
	 */
	Expression* operand;

public:

	/**
	 * \brief Constructor for Const
	 * \param op pointer to the expression of the result to be stored
	 */
	Result(Expression* op);

	/**
	 * \brief Destructor
	 * Deletes the containing expression
	 */
	virtual ~Result();

	/**
	 * \brief Evaluates the Result
	 * This function evaluates the expression and returns the result
	 * \return the result of the expression
	 */
	virtual double evaluate() const;

	/**
	 * \brief Prints the expression to a string
	 * \return string containing the expression
	 */
	virtual std::string print() const;

};

#endif /* RESULT_H_ */
