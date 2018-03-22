/*
 * main.cpp
 *
 *  Created on: 17.04.2016
 *      Author: mklimke
 */

#include <iostream>

int fakultaet(int n)
{
	if(n <= 1)
	{
		return 1;
	}
	else
	{
		return (n * fakultaet(n-1));
	}
}

int main(int argc, char **argv)
{
	int fak[10];
	std::cout << "Fakultaeten:" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		fak[i] = fakultaet(i);
		std::cout << "Die Fakultaet von " << i << " ist " << fak[i] << std::endl;
	}

	return 0;
}
