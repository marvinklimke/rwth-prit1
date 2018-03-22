/*
 * Mul.h
 *
 *  Created on: 03.05.2016
 *      Author: mklimke
 */

/**
 * \file Mul.h
 * \brief This file contains the class declaration of Mul-class.
 */

#ifndef MUL_H_
#define MUL_H_

#include "expression.h"

/**
 * \brief Mul-class
 * This class multiplies two expressions
 */
class Mul : public Expression
{

private:

	/**
	 * \brief first expression (factor)
	 */
	Expression *left;

	/**
	 * \brief second expression (factor)
	 */
	Expression *right;

public:

	/**
	 * \brief Constructor
	 * \param factor1 pointer to the first factor
	 * \param factor2 pointer to the second factor
	 */
	Mul(Expression *factor1, Expression *factor2);

	/**
	 * \brief Destructor
	 * Deletes the two expressions
	 */
	virtual ~Mul();

	/**
	 * \brief evaluates the product
	 * \return the result of the product
	 */
	virtual double evaluate() const;

	/**
	 * \brief prints the readable representation of the product
	 * \return string containing the readable representation
	 */
	virtual std::string print() const;

};

#endif /* MUL_H_ */
