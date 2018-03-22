#include <iostream>

int fib(int n)
{
	int prevFib = 0; // Erste Fibonacci-Zahl ist Null, nicht Eins
	int currFib = 1;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	for (int i = 2; i <= n; i++) // Berechnung startet bei zwei (0, 1 wurden oben behandelt)
	// Genauer Wert von i ist nicht relevant => Reine Zählschleife (n-1)-mal ausgeführt
	{
		int newFib = prevFib + currFib ;
		prevFib = currFib ; // Hier ging der "alte" Wert von currFib verloren.
		currFib = newFib ;  // Der muss zunächst in prevFib übertragen werden.
	}
	return currFib ;
}

int main ()
{
	std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
	for (int i = 1; i <= 12 ; i ++)
	{
		std :: cout << "f(" << i << ") = " << fib (i) << std :: endl ;
	}
	return 0;
}

/*
 * Um größere Fibonacci-Zahlen zu berechnen, kann der Datentyp von prevFib, currFib, newFib
 * sowie der Rückgabetyp der Funktion fib auf "unsigned long long" geändert werden.
 * Dann tritt der erste Fehler bei n = 94 (?) auf. Wertebereich 0 .. 2^64 - 1
 */
