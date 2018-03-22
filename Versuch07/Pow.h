/*
 * Pow.h
 *
 *  Created on: 04.05.2016
 *      Author: mklimke
 */

/**
 * \file Pow.h
 * \brief This file contains the class declaration of Pow-class.
 */

#ifndef POW_H_
#define POW_H_

#include "expression.h"

/**
 * \brief Pow-class
 * This class "powers" two expressions
 */
class Pow : public Expression
{

private:
	/**
	 * \brief first expression (base)
	 */
	Expression* b;

	/**
	 * \brief second expression (exponent)
	 */
	Expression* e;

public:

	/**
	 * \brief Constructor
	 * \param base pointer to the base
	 * \param exponent pointer to the exponent
	 */
	Pow(Expression* base, Expression* exponent);

	/**
	 * \brief Destructor
	 * Deletes the two expressions
	 */
	virtual ~Pow();

	/**
	 * \brief evaluates the power
	 * \return the result of the power
	 */
	virtual double evaluate() const;

	/**
	 * \brief prints the readable representation of the power
	 * \return string containing the readable representation
	 */
	virtual std::string print() const;

};

#endif /* POW_H_ */
