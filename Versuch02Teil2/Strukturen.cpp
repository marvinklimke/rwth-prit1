/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 2.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//
// Autor:  Marvin Klimke
// Matr.:  000000
// Datum:  16.04.2016
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

/**
 * Speichert die Informationen �ber eine Person, im Einzelnen:
 * Vor- und Zuname
 * Geburtsjahr und Alter
 */
struct Person {
	std::string sNachname;
	std::string sVorname;
	int iGeburtsjahr;
	int iAlter;
};

int main()
{
	struct Person nBenutzer;

	std::cout << "Bitte geben Sie Ihren Nachnamen ein: ";
	std::cin  >> nBenutzer.sNachname;
	std::cout << "Bitte geben Sie Ihren Vornamen ein: ";
	std::cin  >> nBenutzer.sVorname;
	std::cout << "Bitte geben Sie Ihr Geburtsjahr ein: ";
	std::cin  >> nBenutzer.iGeburtsjahr;
	std::cout << "Bitte geben Sie Ihr Alter ein: ";
	std::cin  >> nBenutzer.iAlter;

	std::cout << std::endl << "Folgende Daten wurden erfasst:"			<< std::endl;
	std::cout << "nBenutzer.sNachname    = " << nBenutzer.sNachname		<< std::endl;
	std::cout << "nBenutzer.sVorname     = " << nBenutzer.sVorname		<< std::endl;
	std::cout << "nBenutzer.iGeburtsjahr = " << nBenutzer.iGeburtsjahr	<< std::endl;
	std::cout << "nBenutzer.iAlter       = " << nBenutzer.iAlter		<< std::endl;

	struct Person nKopieEinzeln;
	struct Person nKopieGesamt;

	// Kopiere jede Komponente einzeln
	nKopieEinzeln.sNachname		= nBenutzer.sNachname;
	nKopieEinzeln.sVorname		= nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr	= nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter		= nBenutzer.iAlter;

	// Kopiere das Struct komplett
	nKopieGesamt = nBenutzer;

	std::cout << std::endl << "nKopieEinzeln:" << std::endl;
	std::cout << "nKopieEinzeln.sNachname    = " << nKopieEinzeln.sNachname		<< std::endl;
	std::cout << "nKopieEinzeln.sVorname     = " << nKopieEinzeln.sVorname		<< std::endl;
	std::cout << "nKopieEinzeln.iGeburtsjahr = " << nKopieEinzeln.iGeburtsjahr	<< std::endl;
	std::cout << "nKopieEinzeln.iAlter       = " << nKopieEinzeln.iAlter		<< std::endl;

	std::cout << std::endl << "nKopieGesamt:" << std::endl;
	std::cout << "nKopieGesamt.sNachname    = " << nKopieGesamt.sNachname	 << std::endl;
	std::cout << "nKopieGesamt.sVorname     = " << nKopieGesamt.sVorname	 << std::endl;
	std::cout << "nKopieGesamt.iGeburtsjahr = " << nKopieGesamt.iGeburtsjahr << std::endl;
	std::cout << "nKopieGesamt.iAlter       = " << nKopieGesamt.iAlter		 << std::endl;

	return 0;
}

// E.O.F.
