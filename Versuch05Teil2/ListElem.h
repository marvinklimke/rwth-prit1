/**
 * @file ListElem.h
 *
 * \brief content: List element to be used in a data structure
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

/**
 * @brief An element which can be stored in a data structure
 *
 * The type of data stored here is @ref Student.
 *
 */
class ListElem
{
private:
    Student data;                                           ///< the actual data
    ListElem *next;                                         ///< pointer to the next element in list
    ListElem *prev;											///< pointer to the previous element in list

public:
    ListElem(const Student &pData, ListElem *const pNext, ListElem *const pPrev);   ///< @brief constructor with variable initialization

    /* setter */
    void setData(const Student &pData);
    void setNext(ListElem *const pNext);
    void setPrev(ListElem *const pPrev);

    /* getter */
    Student getData() const;
    ListElem *getNext() const;
    ListElem *getPrev() const;
};

#endif
