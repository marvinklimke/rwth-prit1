/**
 * @file dijkstra.h
 * @brief This file contains the function declaration of the dijkstra algorithm.
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "abstractmap.h"

/**
 * @brief This class holds the implementation of the dijkstra algorithm.
 */
class Dijkstra
{
public:

	/**
	 * @brief Dijkstra Algorithm to find the shortest path between two towns.
     * @param map Map to plan the route on.
	 * @param start Name of the start town.
	 * @param target Name of the target town.
	 * @return Pointer to a list of streets between the towns. Empty list if no connection found.
	 */
	static AbstractMap::StreetList search(const AbstractMap &map, QString start, QString target);

private:
	Dijkstra();

};

#endif // DIJKSTRA_H
