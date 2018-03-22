/*
 * Div.h
 *
 *  Created on: 03.05.2016
 *      Author: mklimke
 */

/**
 * \file Div.h
 * \brief This file contains the class declaration of Div-class.
 */

#ifndef DIV_H_
#define DIV_H_

#include "expression.h"

/**
 * \brief Div-class
 * This class divides two expressions
 */
class Div : public Expression
{

private:

	/**
	 * \brief first expression (dividend)
	 */
	Expression *left;

	/**
	 * \brief second expression (divisor)
	 */
	Expression *right;

public:

	/**
	 * \brief Constructor
	 * \param dividend pointer to the dividend of the division
	 * \param divisor pointer to the divisor of the division
	 */
	Div(Expression *dividend, Expression *divisor);

	/**
	 * \brief Destructor
	 * Deletes the two expressions
	 */
	virtual ~Div();

	/**
	 * \brief evaluates the division
	 * \return the result of the division
	 */
	virtual double evaluate() const;

	/**
	 * \brief prints the readable representation of the division
	 * \return string containing the readable representation
	 */
	virtual std::string print() const;
};

#endif /* DIV_H_ */
