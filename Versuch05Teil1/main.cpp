/** @mainpage
 *
 * Praktikum Informatik 1 MMXVI@n
 * Versuch 5.1: Dynamische Datenstrukturen
 *
 * *Die erklaerenden Texte wurden zum Teil von* wikipedia.org *uebernommen*@n
 * *Siehe hierzu die entsprechende* [Webseite][wikipedia].
 *
 * [wikipedia]: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */

/**
 * @file main.cpp
 *
 * \brief content: main routine
 */

#include <iostream>
#include <string>
#include "Stack.h"
#include "Student.h"

int main()
{
    Stack testStack;
    Student stud1;

    char abfrage;
    std::cout << "Wollen sie den Stack selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;

    if (abfrage != 'j')
    {
        stud1.matNr = 12345;
        stud1.adresse = "Ahornst.55";
        stud1.date_of_birth = "23.04.1983";
        stud1.name = "Siggi Baumeister";
        testStack.push(stud1);
        stud1.matNr = 23456;
        stud1.adresse = "Wüllnerstr.8";
        stud1.date_of_birth = "15.10.1963";
        stud1.name = "Walter Rodenstock";
        testStack.push(stud1);
        stud1.matNr = 34567;
        stud1.adresse = "Am Markt 1";
        stud1.date_of_birth = "19.06.1971";
        stud1.name = "Harro Simoneit";
        testStack.push(stud1);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinzufügen" << std::endl
                  << "(2): Datenelement abhängen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(7): Beenden" << std::endl;
        std::cin >> abfrage;

        switch (abfrage)
        {
            case '1':
                std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
                getline(std::cin, stud1.name);    // get entire line, including whitespace
                std::cout << "Geburtsdatum: ";
                getline(std::cin, stud1.date_of_birth);
                std::cout << "Adresse: ";
                getline(std::cin, stud1.adresse);
                std::cout << "Matrikelnummer: ";
                std::cin >> stud1.matNr;
                testStack.push(stud1);
                break;

            case '2':
                std::cout << "Das oberste Datenelemt wird entfernt\n";
                testStack.pop(stud1);
                std::cout << "Studi " << stud1.name << " popped" << std::endl;
                break;

            case '3':
                std::cout << "Inhalt des Stacks:\n";
                testStack.ausgabe();
                break;

            case '7':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '7');

//  system("PAUSE");
    return 0;
}
