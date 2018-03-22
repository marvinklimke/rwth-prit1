/**
 * @file List.cpp
 * \brief content: linked list data structure
 */

#include "List.h"

List::List(): head(NULL), tail(NULL)
{

}

/**
 * @brief Enqueue an element at the beginning of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_head(const Student& pData)
{
    ListElem* new_element = new ListElem(pData, NULL, NULL);

    // list empty ?
    if (tail == NULL)
    {
        tail = new_element;
    }
    else
    {
        new_element->setNext(head);
        head->setPrev(new_element);
    }

    head = new_element;
}

/**
 * @brief Enqueue an element at the tail of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_tail(const Student& pData)
{
    ListElem* new_element = new ListElem(pData, NULL, NULL);

    // list empty ?
    if (tail == NULL)
    {
        head = new_element;
    }
    else
    {
        new_element->setPrev(tail);
        tail->setNext(new_element);
    }

    tail = new_element;
}

/**
 * @brief Dequeue an element from the end of the list.
 *
 * This is the double linked version.
 *
 * @param pData The data will be stored here.
 * @return true if dequeuing was successful, false otherwise
 */
bool List::dequeue(Student& pData)
{
    if (head == NULL)                                       // list empty?
    {
        return false;
    }
    else if (head == tail)                                  // only one element
    {
        pData = head->getData();
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
    	// relocate tail pointer
    	pData = tail->getData();
    	tail = tail->getPrev();
    	delete tail->getNext();
    	tail->setNext(NULL);
    }

    return true;
}

/**
 * @brief Print content from first to last element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_forwards()
{
    ListElem* cursor = head;

    while (cursor != NULL)
    {
        std::cout << (cursor->getData()).name
        		  << ", MatNr. " << (cursor->getData()).matNr
                  << " geb. am " << (cursor->getData()).date_of_birth
                  << " wohnhaft in " << (cursor->getData()).adresse << std::endl;
        cursor = cursor->getNext();
    }
}

/**
 * @brief Print content from last to first element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_backwards()
{
    ListElem* cursor = tail;

    while (cursor != NULL)
    {
        std::cout << (cursor->getData()).name << ", MatNr. "
        		  << (cursor->getData()).matNr
                  << " geb. am " << (cursor->getData()).date_of_birth
                  << " wohnhaft in " << (cursor->getData()).adresse << std::endl;
        cursor = cursor->getPrev();
    }
}

/**
 * \brief Delete Element function
 * This function takes a students matr nr and trys to find it in the list to delete the specific element
 * \param matr matrikel nr to look for
 * \return true if deletion was successful, false otherwise
 */
bool List::delete_byMatrikel(unsigned int matr)
{
	ListElem* cursor = head;

	// cursor to the desired element
	while(cursor->getData().matNr != matr)
	{
		if(cursor == NULL)
			return false;
		cursor = cursor->getNext();
	}

	// only one element
	if(head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else if(cursor == head) // element is head
	{
		head = cursor->getNext();
		cursor->getNext()->setPrev(cursor->getPrev());
	}
	else if(cursor == tail) // element is tail
	{
		cursor->getPrev()->setNext(cursor->getNext());
		tail = cursor->getPrev();
	}
	else // element is in list
	{
		cursor->getPrev()->setNext(cursor->getNext());
		cursor->getNext()->setPrev(cursor->getPrev());
	}

	delete cursor;
	return true;
}
