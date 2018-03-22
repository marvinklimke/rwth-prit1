/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.2: STL
 *
 * Datei:  main.cpp
 * Inhalt: Hauptprogramm
 */

/**
 * \mainpage
 *
 * This project contains the student database implemented using STL-containers and algorithms.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"

/**
 * \brief typedef for an iterator on vector-list of students
 */
typedef std::vector<Student>::iterator iterTyp;

int main()
{
	// Create some students
	Student stud1(22222, "Born"      ,"Jessica", "16.03.1986");
	Student stud2(24528, "Rodenstock","Maxim"  , "09.02.1985");
	Student stud3(95420, "Schneider" ,"Petra"  , "29.12.1989");
	Student stud4(44523, "Baumeister","Siggi"  , "13.01.1979");
	Student stud5(12635, "Baumeister","Dinah"  , "07.06.1982");
	Student stud6(81237, "Simoneit"  ,"Harro"  , "30.10.1973");
	Student stud7(54879, "Soers"     ,"Irmchen", "01.06.1983");

	// Create a std::vector linked list
	std::vector<Student> speicher;

	// put students in list
	speicher.push_back(stud1);
	speicher.push_back(stud2);
	speicher.push_back(stud3);
	speicher.push_back(stud4);
	speicher.push_back(stud5);
	speicher.push_back(stud6);
	speicher.push_back(stud7);

	std::cout << "Speicher unsortiert:" << std::endl;
	for(iterTyp it = speicher.begin(); it != speicher.end(); it++)
	{
		std::cout << *it;
	}

	// Use STL sort-algorithms to sort with own student < > operators
	std::sort(speicher.begin(), speicher.end(), std::greater<Student>());

	std::cout << std::endl << "Speicher sortiert:" << std::endl;
	for(iterTyp it = speicher.begin(); it != speicher.end(); it++)
	{
		std::cout << *it;
	}

	// look for an specific matriculation number
	int matr = 44523;

	// look for a specific matriculation number
	for(iterTyp it = speicher.begin(); it <= speicher.end(); it++)
	{
		if(it->getMatNr() == matr)
		{
			std::cout << *it << " wird gelöscht..." << std::endl;
			speicher.erase(it);
			break;
		}
	}

	std::cout << std::endl << "Speicher:" << std::endl;
	for(iterTyp it = speicher.begin(); it != speicher.end(); it++)
	{
		std::cout << *it;
	}

	return 0;
}
