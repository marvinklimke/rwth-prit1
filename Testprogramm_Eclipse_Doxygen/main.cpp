//////////////////////////////////////////////////////////////////////////////
 // Praktikum Informatik 1 SS2013
 // Testprogramm_Eclipse_Doxygen:
 // Versuch00: Vorbereitung auf Praktikum
 //
 // Datei: main.cpp
 // Inhalt: Hauptprogramm
 //////////////////////////////////////////////////////////////////////////////
/// @file main.cpp

#include <iostream>
#include "Complex.h"
using namespace std;

/** 
 *  @brief Hier ist die main-Funktion
 *  zwei komplexe Zahlen werden addiert.
 *  Das Ergebnis wird in der dritten
 *  komplexen Zahl speichert bzw. ausgegeben.
 */
int main(int argc, char* argv[])
{   //Erstelle zwei komplexe Zahlen ueber Konstruktor 2
	Complex c1(2.0, 4.0);
    Complex c2(6.0, 8.0);

    //Erstelle dritte komplexe Zahl ueber Konstruktor 1
    Complex c3;

    //Addition zwei komplexer Zahlen
    c3=c1+c2;

    //dritte komplexe Zahl ausgeben.
    cout<<"c3="<<c3;

	return 0;
}
