//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 2.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//
// Autor:  Marvin Klimke
// Matr.:  000000
// Datum:  16.04.2016
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	// (1)
	int iErste;
	int iZweite;

	std::cout << "Bitte geben Sie die  erste Zahl ein: ";
	std::cin  >> iErste;
	std::cout << "Bitte geben Sie die zweite Zahl ein: ";
	std::cin  >> iZweite;

	int iSumme = iErste + iZweite;
	int iQuotient = iErste / iZweite;
	std::cout << "iSumme = "	<< iSumme	 << std::endl;
	std::cout << "iQuotient = " << iQuotient << std::endl;

	// (2)
	double dSumme = iErste + iZweite;
	double dQuotient = iErste / iZweite;
	std::cout << "dSumme = "	<< dSumme	 << std::endl;
	std::cout << "dQuotient = " << dQuotient << std::endl;

	// (3)
	double dSummeCast = (double)iErste + (double)iZweite;
	double dQuotientCast = (double)iErste / (double)iZweite;
	std::cout << "dSummeCast = "	<< dSummeCast	 << std::endl;
	std::cout << "dQuotientCast = " << dQuotientCast << std::endl;

	// (4)
	std::string sVorname;
	std::string sNachname;

	std::cout << "Bitte geben Sie Ihren Vornamen ein: ";
	std::cin  >> sVorname;
	std::cout << "Bitte geben Sie Ihren Nachnamen ein: ";
	std::cin  >> sNachname;

	std::string sVornameNachname = sVorname + " " + sNachname;
	std::string sNachnameVorname = sNachname + ", " + sVorname;

	std::cout << "sVornameNachname = " << sVornameNachname << std::endl;
	std::cout << "sNachnameVorname = " << sNachnameVorname << std::endl;

	// (5) in a block
	{
		// (a)
		int iFeld[] = { 1, 2 };
		// Indices: [0..1]

		// (b)
		int spielfeld[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
		// Indices: [0..2][0..2] oder [0..8]

		// (c)
		std::cout << "iFeld[0] = " << iFeld[0] << std::endl;
		std::cout << "iFeld[1] = " << iFeld[1] << std::endl;

		std::cout << "spielfeld[][] = " << std::endl;
		std::cout << spielfeld[0][0] << " " << spielfeld[0][1] << " " << spielfeld[0][2] << std::endl;
		std::cout << spielfeld[1][0] << " " << spielfeld[1][1] << " " << spielfeld[1][2] << std::endl;
		std::cout << spielfeld[2][0] << " " << spielfeld[2][1] << " " << spielfeld[2][2] << std::endl;

		// (d)
		const int iZweite = 1;
		std::cout << "iZweite (im Block) = " << iZweite << std::endl;
	}
	std::cout << "iZweite (draussen) = " << iZweite << std::endl;

	// (6)
	int iName1 = (int)sVorname[0];
	int iName2 = (int)sVorname[1];

	std::cout << "iName1 = " << iName1 << std::endl;
	std::cout << "iName2 = " << iName2 << std::endl;

	// (7)
	int iName1_alt = (int)toupper(sVorname[0]) - (int)('A') + 1;
	int iName2_alt = (int)toupper(sVorname[1]) - (int)('A') + 1;

	std::cout << "iName1_alt (Pos. im ABC) = " << iName1_alt << std::endl;
	std::cout << "iName2_alt (Pos. im ABC) = " << iName2_alt << std::endl;

	return 0;
}

// E.O.F.
