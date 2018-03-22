 //////////////////////////////////////////////////////////////////////////////
 // Praktikum Informatik 1 SS2013
 // Testprogramm_Eclipse_Doxygen:
 // Versuch00: Vorbereitung auf Praktikum
 //
 // Datei:  Complex.h
 // Inhalt: Headerdatei
 //////////////////////////////////////////////////////////////////////////////

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

/**
 * @brief Basisklasse fuer komplexe Zahlen.
 *
 * Klasse fuer komplexe Zahlen mit Real- und
 * Imaginaerteil als double-Werte.
 */
class Complex {
public:
	/** 
	 *  @brief Konstruktor 1
	 *  Realteil mit 0.0 initialisiert
	 *  Imaginaerteil mit 0.0 initialisiert
	 */
	Complex()
    { real = 0.0;
      imag = 0.0;
    }

    /** 
     *  @brief Konstruktor 2
     *  @param r - initialisiert Membervariablen real
     *  @param i - initialisiert Membervariablen imag
     */
    Complex (double r, double i)
    { 	real = r;
        imag = i;
    }

    /** 
     *  @brief Addition von zwei komplexen Zahlen
     *  Ueberladen von Operator "+"
     *  @param c2 rechter Operand
     */
   Complex operator +(Complex c2)
   {
	   return Complex(real + c2.real, imag + c2.imag);
   }

    /** 
     *  @brief Ausgabe von einer komplexen Zahl
     *  Ueberladen des Streamoperators " << "
     *  @param output - Ausgabestream
     *  @param c - Auszugebende komplexe Zahl
     */
   friend ostream& operator << (ostream& output, Complex& c)
      {
   	   output<<"("<<c.real<<"+"<<c.imag<<"i)"<<endl;
   	   return output;

      }

private:
    double real;	//! Realteil
    double imag;	//! Imaginaerteil
};

#endif /* COMPLEX_H_ */
