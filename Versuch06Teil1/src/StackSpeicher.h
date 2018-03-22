/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.1: Templates und �berladen von Operatoren
 *
 * Datei:  StackSpeicher.h
 * Inhalt: generischer Stackspeicher
 *
 * Autor:  Marvin Klimke
 * Matr.:  000000
 * Datum:  27.04.2016
 */

#ifndef STACKSPEICHER_H_
#define STACKSPEICHER_H_

/**
 * \brief Template for a stack-class to store values of a type T
 */
template<int size, class T>
class StackSpeicher
{
  public:
	StackSpeicher();
	void push (const T& e);
	void pop (T& e);
	void print();
	void sort(int l, int r);
	int partition(int l, int r);
	void exchange(int index1, int index2);

  private:
	T space[size];
	int index;
};

/**
 * @brief Constructor
 */
template <int size, class T>
StackSpeicher <size, T> :: StackSpeicher():index(-1)
{
}

/**
 * @brief Function to push an Element
 * @param e Element to save
 */
template <int size, class T>
void StackSpeicher <size, T>::push(const T& e)
{
	if (index < (size-1))
	{
		index += 1;
		space[index] = e;
	}
}

/**
 * @brief Function to retriev an Element from the Stack
 * @param e Position to save the Element
 */
template<int size, class T>
void StackSpeicher<size, T>::pop(T& e)
{
	if (index >= 0)
	{
		e = space[index];
		index -= 1;
	}
}

/**
 * \brief Prints out the content of the StackSpeicher
 * This function prints the content of the StackSpeicher to the console
 */
template<int size, class T>
void StackSpeicher<size, T>::print()
{
	std::cout << "StackSpeicher contents:" << std::endl;
	for(int i = 0; i < size; i++)
	{
		std::cout << space[i];
	}
}

/**
 * \brief Function to sort a stack of types T
 * This function sorts the stack (big elements up) by using quick sort algorithm
 * \param l left border
 * \param r right border
 */
template<int size, class T>
void StackSpeicher<size, T>::sort(int l, int r)
{
	// invalid parameter ?
	if(l > size || l >= r || r <= 1)
		return;

	int k = partition(l, r);
	sort(l, k-1);
	sort(k+1, r);

}

/**
 * \brief Partition function for quick sort algorithm
 * This function partitions the array for sorting by quick sort. (From GGI1)
 * \param l left border
 * \param r right border
 * \return the index of the partition element
 */
template<int size, class T>
int StackSpeicher<size, T>::partition(int l, int r)
{
	int i = l;
	int j = r - 1;
	int k = r;
	T v = space[k];

	while(1)
	{
		while(space[i] <= v && i < r)
			i++;
		while(space[j] >= v && j >= l)
			j--;

		if(i >= j)
			break;
		else
			exchange(i, j);
	}
	exchange(i, k);
	return i;
}

/**
 * \brief Function to exchange two elements on the stack
 * This function swaps two elements of type T on the stack using triangular exchange
 * \param index1 index of first element to swap
 * \param index2 index of second element to swap
 */
template<int size, class T>
void StackSpeicher<size, T>::exchange(int index1, int index2)
{
	T temp = space[index1];
	space[index1] = space[index2];
	space[index2] = temp;
}

#endif /*STACKSPEICHER_H_*/
