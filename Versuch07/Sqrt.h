/*
 * Sqrt.h
 *
 *  Created on: 04.05.2016
 *      Author: mklimke
 */

/**
 * \file Sqrt.h
 * \brief This file contains the class declaration of Sqrt-class.
 */

#ifndef SQRT_H_
#define SQRT_H_

#include "expression.h"

/**
 * \brief Sqrt-class
 * This class calculates the root of an expression
 */
class Sqrt : public Expression
{

private:

	/**
	 * \brief expression under the root (discriminant)
	 */
	Expression* diskr;

public:

	/**
	 * \brief Constructor
	 * \param discriminant pointer to the discriminant of the root
	 */
	Sqrt(Expression* discriminant);

	/**
	 * \brief Destructor
	 * Deletes the expression under the root
	 */
	virtual ~Sqrt();

	/**
	 * \brief evaluates the root
	 * \return the result of the root
	 */
	virtual double evaluate() const;

	/**
	 * \brief prints the readable representation of the root
	 * \return string containing the readable representation
	 */
	virtual std::string print() const;

};

#endif /* SQRT_H_ */
