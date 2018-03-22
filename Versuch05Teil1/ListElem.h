/**
 * \file ListElem.h
 *
 * \brief content: declaration of the ListElem class, providing chained-list functionality
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

/**
 * \brief This class provides a chained list
 */
class ListElem
{
	private: // member

		/**
		 * \brief This struct holds the actual data of the element
		 */
		Student data;

		/**
		 * \brief This pointer points to the next element
		 */
		ListElem *next;


	public:

		/**
		 * \brief Standardkonstruktor
		 * the default constructor for ListElem class
		 * \param student initial value for data-field
		 * \param next_elem next pointer initial value
		 */
		ListElem(const Student &student, ListElem *const next_elem);

		/**
		 * \brief Setter for member data
		 * \param student the new value for member data
		 */
		void setData(const Student &student);

		/**
		 * \brief Setter for member next_elem
		 * \param next_elem the new value for member next
		 */
		void setNext(ListElem *const next_elem);

		/**
		 * \brief Getter for member data
		 * \return current value of data
		 */
		Student getData() const;

		/**
		 * \brief Getter for member next
		 * \return current value of next pointer
		 */
		ListElem *getNext() const;

};

#endif
