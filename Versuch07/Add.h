/*
 * Add.h
 *
 *  Created on: 02.05.2016
 *      Author: mklimke
 */

/**
 * \file Add.h
 * \brief This file contains the class declaration of Add-class.
 */

#ifndef ADD_H_
#define ADD_H_

#include "expression.h"

/**
 * \brief Add-class
 * This class adds two expressions
 */
class Add : public Expression
{

private:

	/**
	 * \brief first expression (summand)
	 */
	Expression* left;

	/**
	 * \brief second expression (summand)
	 */
	Expression* right;

public:

	/**
	 * \brief Constructor
	 * \param summand1 pointer to first summand
	 * \param summand2 pointer to second summand
	 */
	Add(Expression* summand1, Expression* summand2);

	/**
	 * \brief Destructor
	 * Deletes the two expressions
	 */
	virtual ~Add();

	/**
	 * \brief evaluates the summation
	 * \return the result of the summation
	 */
	virtual double evaluate() const;

	/**
	 * \brief prints the readable representation of the summation
	 * \return string containing the readable representation
	 */
	virtual std::string print() const;

};

#endif /* ADD_H_ */
