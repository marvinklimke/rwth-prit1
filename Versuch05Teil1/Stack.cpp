/**
 * \file Stack.cpp
 *
 * \brief content: source of the stack class functions
 */

#include "Stack.h"

Stack::Stack() : head(NULL)
{
	tail = NULL;
}

void Stack::push(Student& student)
{
	// create new ListElem
	ListElem *neu = new ListElem(student, NULL);

	// stack empty => tail becomes the new element as well
	if(head == NULL)
		tail = neu;
	else
		neu->setNext(head);

	head = neu;
}

void Stack::ausgabe() const
{
	// stack empty?
	if (head == NULL)
		std::cout << "Der Stack ist leer." << std::endl;
	else
	{
		// Start at the 'top'
		ListElem* cursor = head;

		// till the end of the stack..
		while (cursor != NULL)
		{
			std::cout << (cursor->getData()).name
					  << ",\tMatNr. " << (cursor->getData()).matNr
					  << "\tgeb. am " << (cursor->getData()).date_of_birth
					  << "\twohnhaft in " << (cursor->getData()).adresse << std::endl;

			// go one element deeper
			cursor = cursor->getNext();
		}
	}
}

bool Stack::pop(Student& student)
{
	// stack empty ?
	if(head == NULL)
		return false;
	else if(head == tail)
	{
		// stack of only one element => stack vanishes
		student = head->getData();

		delete head;
		tail = NULL;
		head = NULL;
	}
	else
	{
		// 'normal' pop (i.e. remove head element)
		student = head->getData();
		head = head->getNext();
	}
	return true;
}
