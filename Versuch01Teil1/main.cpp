/*
 * main.cpp
 *
 *  Created on: 16.04.2016
 *      Author: Marvin Klimke
 *      Matr. : 000000
 */

#include <iostream>

/**
 * Berechne Fibonacci-Zahlen bis zur MAX_N-ten Fibonacci-Zahl
 */
#define MAX_N 25

/**
 * Rekursive Implementierung einer Fibonacci-Funktion.
 * Gibt die n-te Fibonacci-Zahl zur�ck (-1 bei falschem Parameter)
 */
unsigned int fib(unsigned int n)
{
	int fib_n = -1;

	if(n == 0 || n == 1)
	{
		fib_n = n;
	}
	else
	{
		fib_n = fib(n-1) + fib(n-2);
	}

	return fib_n;
}

/**
 * Hauptprogramm zum Testen der rekursiven Fibonacci-Funktion.
 * Gibt die ersten 26 (0..25) Fibonacci-Zahlen auf dem Standardstream aus.
 */
int main(void)
{
	std::cout << "n\tfib(n)" << std::endl;

	for(unsigned int n = 0; n <= MAX_N; n++)
	{
		std::cout << n << "\t" << fib(n) << std::endl;
	}

	return 0;
}

// E.O.F.
