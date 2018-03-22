/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.1: Templates und �berladen von Operatoren
 *
 * Datei:  main.cpp
 * Inhalt: Hauptprogramm
 *
 * Autor:  Marvin Klimke
 * Matr.:  000000
 * Datum:  27.04.2016
 */

/**
 * \mainpage
 *
 * This project contains a linked list to store students.
 * The list is being sorted using quick-sort algorithm.
 */

#include <iostream>
#include <string>
#include "Student.h"
#include "StackSpeicher.h"

int main()
{
	// Create a linked list
	StackSpeicher<7, Student> speicher;

	// Put some students on the list
	speicher.push(Student(123456, "Mustermann", "Max", "01.12.1994"));
	speicher.push(Student(222222, "Lustig", "Peter", "13.11.1954"));
	speicher.push(Student(435123, "Meier", "Hans", "24.07.1985"));
	speicher.push(Student(853422, "Schmidt", "Karl", "28.05.1948"));
	speicher.push(Student(453430, "Bayer", "Heinz", "17.09.2011"));
	speicher.push(Student(785634, "Schneider", "Jost", "05.12.1921"));
	speicher.push(Student(111111, "Gauss", "Carl-Friedrich", "30.04.1777"));

	// Sort the list using quick-sort implementation from GGI1
	speicher.sort(0, 6);

	// remove students from list and print them out
	Student studi;
	for(int i = 0; i < 7; i++)
	{
		speicher.pop(studi);
		std::cout << studi;
	}
	
	// Compare two students
	Student stud1(222222, "Lustig", "Peter", "12.03.1945");
	Student stud2(222222, "Lustig", "Peter", "30.04.1939");
	if (stud1 == stud2)
	{
		std::cout << "Stud1 und Stud2 sind gleich" << std::endl;
	}
	else
	{
		std::cout << "Stud1 und Stud2 sind nicht gleich" << std::endl;
	}
	
	return 0;
}
