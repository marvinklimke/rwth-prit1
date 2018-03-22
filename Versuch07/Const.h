/*
 * Const.h
 *
 *  Created on: 02.05.2016
 *      Author: mklimke
 */

/**
 * \file Const.h
 * \brief This file contains the class declaration of Const-class.
 */

#ifndef CONST_H_
#define CONST_H_

#include "expression.h"

/**
 * \brief Const-class
 * This class stores a const value to be used with other expression-derived classes (Add, Sub, Mul, Div).
 */
class Const : public Expression
{

private:

	/**
	 * \brief stored value
	 */
	double value;

public:

	/**
	 * \brief Constructor for Const
	 * \param val value to be stored
	 */
	Const(double val);

	/**
	 * \brief Destructor
	 */
	virtual ~Const();

	/**
	 * \brief Getter for stored const value
	 * \return member value
	 */
	virtual double evaluate() const;

	/**
	 * \brief Print the stored const value to a string
	 * \return string containing the member value
	 */
	virtual std::string print() const;

};

#endif /* CONST_H_ */
