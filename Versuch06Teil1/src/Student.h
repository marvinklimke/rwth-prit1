/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.1: Templates und �berladen von Operatoren
 *
 * Datei:  Student.h
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 *
 * Autor:  Marvin Klimke
 * Matr.:  000000
 * Datum:  27.04.2016
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

/**
 * \brief Student-class holds a student's data. Students can be compared using >= <= == operators
 */
class Student
{
  public:
	Student();
	Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string dateofbirth);
	bool operator == (const Student& stud) const;
	bool operator <= (const Student& stud) const;
	bool operator >= (const Student& stud) const;
	std::ostream& ausgabe(std::ostream& out) const;
	
  private:
	int matNr;
	std::string name;
	std::string firstname;
	std::string dateofbirth;
};

std::ostream& operator << (std::ostream& out, Student& student);

#endif // STUDENT_H

