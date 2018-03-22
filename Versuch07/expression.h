/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  expression.h
 * Inhalt: Headerdatei Abstrakte Klasse Expression
 */

/**
 * \file expression.h
 * \brief This file contains the class declaration of expression-class.
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <sstream>	// To convert double to string

/**
 * \brief Abstract Math-Expression class
 * This class provides the necessary framework for the mathematical operations
 */
class Expression
{

public:

	/**
	 * \brief Default constructor
	 */
	Expression();

	/**
	 * \brief Default destructor
	 */
	virtual ~Expression();

	/**
	 * \brief Calculates the value of expression
	 * \return the value of expression
	 */
	virtual double evaluate() const = 0;

	/**
	 * \brief print mathematical expression as string
	 * \return the mathematical expression as string
	 */
	virtual std::string print() const = 0;

};

#endif
