//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 04: Einf�hrung in die Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//
// Autor:  Marvin Klimke
// Matr.:  000000
// Datum:  21.04.2016
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath>
#include <iostream>


Vektor::Vektor(double inX, double inY, double inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

Vektor::~Vektor()
{

}


void Vektor::ausgabe() const
{
	std::cout << "Vektor{x= " << x << ", y= " << y << ", z= " << z << " }" << std::endl;
}

double Vektor::getX() const
{
	return x;
}

double Vektor::getY() const
{
	return y;
}

double Vektor::getZ() const
{
	return z;
}

double Vektor::getLength() const
{
	return sqrt(x*x + y*y + z*z);
}

Vektor Vektor::subtract(const Vektor& v) const
{
	// subtract v from this (object) and return result
	return Vektor(x - v.x, y - v.y, z - v.z);
}

Vektor Vektor::add(const Vektor& v) const
{
	// add v1 and v2, return result
	return Vektor(x + v.x, y + v.y, z + v.z);
}

double Vektor::scalar(const Vektor v) const
{
	return (x*v.x + y*v.y + z*v.z);
}

bool Vektor::isOrthogonal(const Vektor v) const
{
	double sc = scalar(v);
	return (sc < 0.1) && (sc > -0.1);
}

void Vektor::rotate(double rad)
{
	// calculate matrix product with rotation-matrix
	// save old x value to calculate rotation correctly
	double new_x = x*cos(rad) - y*sin(rad);
	double new_y = x*sin(rad) + y*cos(rad);
	x = new_x;
	y = new_y;
}
