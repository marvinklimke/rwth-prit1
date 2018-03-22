/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.2: STL
 *
 * Datei:  Student.cpp
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 */

#include "Student.h"

/**
 * @brief Constructor of student
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
 * @param date The date of birth of the Student.
 */
Student::Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string date):
	matNr(matriculationnumber), name(name), firstname(firstname), dateofbirth(date)
{
}

// Insert your implementation here

/**
 * \brief Getter for member matNr
 * Required for comparing two students
 * \return the matriculation-number of the student
 */
int Student::getMatNr()
{
	return matNr;
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
 * \brief Operator for comparing (<) two Students
 * \param stud Student to compare with
 * \return true if the object students matriculation-number is smaller to the one of stud parameter
 */
bool Student::operator < (const Student& stud) const
{
	if(matNr < stud.matNr)
		return true;
	else
		return false;
}

/**
 * \brief Operator for comparing (>) two Students
 * \param stud Student to compare with
 * \return true if the object students matriculation-number is greater to the one of stud parameter
 */
bool Student::operator > (const Student& stud) const
{
	if(matNr > stud.matNr)
		return true;
	else
		return false;
}

/**
 * \brief Printout function for student class
 * This function prints out the information about the student to a given ostream (e.g. cout)
 * \param out ostream to print to
 * \return ostream with output of student class
 */
std::ostream& Student::ausgabe(std::ostream& out) const
{
	out << "MatrNr: " << matNr << ",\tName: " << name << ",\tVorname: " << firstname << "\tgeb. am " << dateofbirth << std::endl;
	return out;
}

/**
 * \brief Operator overload for <<
 * This is the operator overload for stream-operator << for output of student class
 * \param out ostream to print to
 * \param stud Student object to be printed
 * \return ostream with the output of the student class
 */
std::ostream& operator << (std::ostream& out, const Student& stud)
{
	return stud.ausgabe(out);
}
