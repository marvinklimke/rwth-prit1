/**
 * @file Student.h
 *
 * \brief content: data structure with attributes of a student
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string> /* data type string */

/**
 * @brief This data type holds the attributes of a student
 *
 */
struct Student
{
	std::string name;
	unsigned int matNr;
	std::string date_of_birth;
	std::string adresse;
};

#endif /*STUDENT_H_*/
