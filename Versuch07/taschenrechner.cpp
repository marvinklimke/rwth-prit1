/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  taschenrechner.cpp
 * Inhalt: Hauptprogramm
 *
 * Autor:  Marvin Klimke
 * Matr.:  000000
 * Datum:  02.05.2016
 */

/**
 * \file taschenrechner.cpp
 * \brief This file contains the main method to test the different classes of the calculator.
 */

/**
 * \mainpage
 *
 * This Project contains a modular calculator. Mathematical operations are derived from the class expression.
 *
 * Currently the following operations are implemented:
 *  - Add (Summation)
 *  - Sub (Subtraction)
 *  - Mul (Multiplication)
 *  - Div (Division)
 *  - Pow (Power x^n)
 *  - Sqrt (square root)
 *
 * Additional necessary classes are:
 *  - Const (Constant value)
 *  - Result (of an expression)
 */

#include "expression.h"
#include "Const.h"
#include "Result.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
#include "Pow.h"
#include "Sqrt.h"

#include <iostream>

/**
 * \brief Test Const-class
 * This function tests the Const-class.
 */
void testConst()
{
	Const c(4);
	std::cout << c.print() << " = " << c.evaluate() << std::endl;
}

/**
 * \brief Test Result-class
 * This function tests the Result-class (and Const-class).
 */
void testResult()
{
	Result res ( new Const(4) );
	std::cout << res.print() << " = " << res.evaluate() << std::endl;
}

/**
 * \brief Test Add-class
 * This function tests the Add-class (and Result-, Const-class).
 */
void testAddConst()
{
	Result res (	new Add (
					new Const(7),
					new Const(8)
				)
			);
	std::cout << res.print() << " = " << res.evaluate() << std::endl;
}

/**
 * \brief Test Mul-class
 * This function tests the Mul-class (and Result-, Const-class).
 */
void testMultConst()
{
	Result res (	new Mul (
					new Const(6),
					new Const(8)
				)
			);
	std::cout << res.print() << " = " << res.evaluate() << std::endl;
}

/**
 * \brief Test everything
 * This function tests the classes Mul, Add, Const and Result.
 */
void finalTest()
{

	Result res1 (	new Mul (
					new Sqrt (
						new Add(
							new Const(87),
							new Const(13)
						)
					),
					new Div(
						new Const(21),
						new Const(5)
					)
				)
			);
	std::cout << res1.print() << " = " << res1.evaluate() << std::endl;
	
	Result res2 (	new Add (
					new Sqrt(
						new Const(16)
					),
					new Mul (
						new Const(9),
						new Pow (
							new Const(4),
							new Const(3)
						)
					)
				)
			);
	std::cout << res2.print() << " = " << res2.evaluate() << std::endl;
}

/**
 * \brief Main-method
 */
int main(void)
{
	std::cout << " # testConst # " << std::endl;
	testConst();

	std::cout << " # testResult # " << std::endl;
	testResult();
	
	std::cout << " # testMultConst # " << std::endl;
	testMultConst();

	std::cout << " # testAddConst # " << std::endl;
	testAddConst();

	std::cout << " # finalTest # " << std::endl;
	finalTest();

	return 0;
}

