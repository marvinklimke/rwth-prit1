/*
 * Sub.h
 *
 *  Created on: 03.05.2016
 *      Author: mklimke
 */

/**
 * \file Sub.h
 * \brief This file contains the class declaration of Sub-class.
 */

#ifndef SUB_H_
#define SUB_H_

#include "expression.h"

/**
 * \brief Subtraction-class
 * This class subtracts two expressions
 */
class Sub : public Expression
{

private:

	/**
	 * \brief first expression (minuend)
	 */
	Expression *left;

	/**
	 * \brief second expression (subtrahend)
	 */
	Expression *right;

public:

	/**
	 * \brief Constructor
	 * \param minuend pointer to  the minuend of the subtraction
	 * \param subtrahend pointer to the subtrahend of the subtraction
	 */
	Sub(Expression *minuend, Expression *subtrahend);

	/**
	 * \brief Destructor
	 * Deletes the two expressions
	 */
	virtual ~Sub();

	/**
	 * \brief evaluates the subtraction
	 * \return the result of the subtraction
	 */
	virtual double evaluate() const;

	/**
	 * \brief prints the readable representation of the subtraction
	 * \return string containing the readable representation
	 */
	virtual std::string print() const;

};

#endif /* SUB_H_ */
