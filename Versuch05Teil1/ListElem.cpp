/**
 * \file ListElem.cpp
 *
 * \brief content: source of the ListElem class functions
 */

#include "ListElem.h"
#include "Student.h"


ListElem::ListElem(const Student &student, ListElem *const next_elem)
	: data(student), next(next_elem)
{

}


void ListElem::setData(const Student &student)
{
	data = student;
}

void ListElem::setNext(ListElem *const next_elem)
{
	next = next_elem;
}

Student ListElem::getData() const
{
	return data;
}

ListElem *ListElem::getNext() const
{
	return next;
}
