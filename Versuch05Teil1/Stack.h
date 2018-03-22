/**
 * \file Stack.h
 *
 * \brief content: class declaration of the stack class, providing stack-functionality
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

#include "ListElem.h"

/**
 * \brief This class provides a stack-like data-structure
 */
class Stack
{
	private: // member

		/**
		 * \brief pointer to the top element on the stack as ListElem
		 */
		ListElem *head;

		/**
		 * \brief pointer to the bottom element of the stack as ListElem
		 */
		ListElem *tail;

	public:

		/**
		 * \brief Standardkonstruktor
		 * the default constructor for stack class
		 */
		Stack();

		/**
		 * \brief Pushes one element on the stack
		 * This function takes a student object and pushes it onto the stack
		 * \param student the student object to push on the stack
		 */
		void push(Student &student);

		/**
		 * \brief Pops one element off the stack
		 * This function pops off one element of the stack and passes the content to referenced student
		 * \param student the student to write the read data in
		 */
		bool pop(Student &student);

		/**
		 * \brief Ausgabefunktion
		 * This function prints out the whole content of the stack to the console
		 */
		void ausgabe() const;

};

#endif
