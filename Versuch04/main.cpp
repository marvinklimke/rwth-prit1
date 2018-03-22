//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 04: Einf�hrung in die Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//
// Autor:  Marvin Klimke
// Matr.:  000000
// Datum:  21.04.2016
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Vektor.h"
#include <cmath>

#define EARTH_RADIUS_KM 6371
#define PLATFORM_HEIGHT_M 500
#define HUMAN_SIZE_M 1.8

#define ANGLE_INC 0.0000001
#define PI 3.14159265

int main()
{
	// Erdradius
	Vektor* earth = new Vektor(0, EARTH_RADIUS_KM, 0);

	// Sichth�he Mensch
	Vektor* human = earth->add(new Vektor(0, (PLATFORM_HEIGHT_M + HUMAN_SIZE_M)/1000, 0));

	// Sichtvektor soll Erde tangieren
	Vektor* sight = earth->subtract(human);

	double rad = 0;
	do
	{
		// Erh�he Winkel langsam
		rad += ANGLE_INC;
		earth->rotate(ANGLE_INC);
		sight = earth->subtract(human);

	} while(!sight->isOrthogonal(earth)); // Pr�fe Orthogonalit�t

	// Berechnen der Distanz als Zahlenwert
	double sight_dist = sight->getLength();
	double deg = rad * 180 / PI;

	std::cout << "H�he der Plattform: " << PLATFORM_HEIGHT_M  << "m" << std::endl;
	std::cout << "Sichtweite: " << sight_dist << "km" << std::endl;
	std::cout << "Winkel: " << deg << "�" << std::endl;

	return 0;
}

// E.O.F.
