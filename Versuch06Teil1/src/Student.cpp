/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.1: Templates und �berladen von Operatoren
 *
 * Datei:  Student.cpp
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 *
 * Autor:  Marvin Klimke
 * Matr.:  000000
 * Datum:  27.04.2016
 */

#include "Student.h"

/**
 * @brief Standard constructor of Student
 */
Student::Student()
{
	matNr = 0;
}

/**
 * @brief Constructor
 * @param matriculationnumber The matriculation number of the student.
 * @param name The name of the Student.
 * @param firstname The first name of the Student.
 * @param dateofbirth The date of birth of the Student.
 */
Student::Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string dateofbirth):
	matNr(matriculationnumber), name(name), firstname(firstname), dateofbirth(dateofbirth)
{
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return If two Students are the same true. Else false.
 */
bool Student::operator == (const Student& stud) const
{
	if (matNr == stud.matNr)
		return true;
	else 
		return false;
}

/**
 * \brief Operator for comparing (<=) two Students
 * \param stud Student to compare with
 * \return true if the object students matrikel is smaller or equal to the one of stud parameter
 */
bool Student::operator <= (const Student& stud) const
{
	if(matNr <= stud.matNr)
		return true;
	else
		return false;
}

/**
 * \brief Operator for comparing (>=) two Students
 * \param stud Student to compare with
 * \return true if the object students matrikel is greater or equal to the one of stud parameter
 */
bool Student::operator >= (const Student& stud) const
{
	if(matNr >= stud.matNr)
		return true;
	else
		return false;
}

/**
 * \brief Printout function for student class
 * This function prints out the information about the student to a given ostream (e.g. cout)
 * \param os ostream to print to
 * \return ostream with output of student class
 */
std::ostream& Student::ausgabe(std::ostream& os) const
{
	os << "MatrNr: " << matNr << ",\tName: " << name << ",\tVorname: " << firstname << "\tgeb. am " << dateofbirth << std::endl;
	return os;
}

/**
 * \brief Operator overload for <<
 * This is the operator overload for stream-operator << for output of student class
 * \param out ostream to print to
 * \param student Student object to be printed
 * \return ostream with the output of the student class
 */
std::ostream& operator << (std::ostream& out, Student& student)
{
	return student.ausgabe(out);
}
