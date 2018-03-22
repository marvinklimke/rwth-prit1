/**
 * @file dijkstra.cpp
 * @brief This file contains the function definitions of the Dijkstra class.
 * Implementation of the dijkstra algorithm.
 */

#include "dijkstra.h"

#include <QDebug>

/// This structure shall be used by the Dijkstra algorithm
struct tuppel {
	City* city;
	double distance;
	Street* shortest_way;
};


// The name of the variables is based on the Info I lecture notes.
AbstractMap::StreetList Dijkstra::search(const AbstractMap &map, QString start, QString target)
{
	// Getting Pointer to start and target
	City* start_pointer = map.find_city(start);
	City* target_pointer = map.find_city(target);
	if (start_pointer == NULL || target_pointer == NULL)
	{
		qDebug() << "Dijkstra: Cities not found";

		// return an emply list
		AbstractMap::StreetList l;
		return l;
	}

	// Defining Sets
	std::vector<tuppel> green;
	std::vector<tuppel> yellow;

	tuppel temp = {start_pointer, 0, NULL};
	yellow.push_back(temp);

	// Starting Algorithm
	while (yellow.empty() == false)
	{
		// Finding Edge with smallest distance
		tuppel edge_to_process_data;
		std::vector<tuppel>::iterator edge_to_process = yellow.begin();
		for (std::vector<tuppel>::iterator it = yellow.begin(); it != yellow.end(); it++)
		{
			if ((*it).distance < (*edge_to_process).distance)
			{
				edge_to_process = it;
			}
		}
		edge_to_process_data = *edge_to_process;
		green.push_back(*edge_to_process);
		yellow.erase(edge_to_process);

		// Getting list of all Succesors
		AbstractMap::StreetList streets = map.get_street_list(edge_to_process_data.city);
		std::vector<tuppel> successor_list;
		for (AbstractMap::StreetList::const_iterator it = streets.begin(); it != streets.end(); it++)
		{
			// save all necessary data for the algorithm
			temp.city = map.get_opposite_city(*it, edge_to_process_data.city);
			temp.distance = map.get_length(*it);
			temp.shortest_way = *it;
			successor_list.push_back(temp);
		}
		// for every Succesor
		for (std::vector<tuppel>::const_iterator successor = successor_list.begin(); successor != successor_list.end(); successor++)
		{
			// Test if City was already visited
			bool found = false;
			for (std::vector<tuppel>::iterator it = green.begin(); it != green.end(); it++)
			{
				// City already visited
				if ((*successor).city == (*it).city)
				{
					found = true;
					// Check if new way is shorter
					if (edge_to_process_data.distance + (*successor).distance < (*it).distance)
					{
						// Save the new shortest way
						(*it).distance = edge_to_process_data.distance + (*successor).distance;
						(*it).shortest_way = (*successor).shortest_way;
					}
				}
			}
			for (std::vector<tuppel>::iterator it = yellow.begin(); it != yellow.end(); it++)
			{
				// City already visited
				if ((*successor).city == (*it).city)
				{
					found = true;
					// Check if new way is shorter
					if (edge_to_process_data.distance + (*successor).distance < (*it).distance)
					{
						// Save the new shortest way
						(*it).distance = edge_to_process_data.distance + (*successor).distance;
						(*it).shortest_way = (*successor).shortest_way;
					}
				}
			}

			// if new town
			if (found == false)
			{
				temp.city = (*successor).city;
				temp.distance = edge_to_process_data.distance + (*successor).distance;
				temp.shortest_way = (*successor).shortest_way;
				yellow.push_back(temp);
			}
		}
	}

	// Building List with shortest Path
	AbstractMap::StreetList shortest_path;
	City* current_edge = NULL;
	for (std::vector<tuppel>::const_iterator it = green.begin(); it != green.end(); it++)
	{
		if ((*it).city == target_pointer)
		{
			shortest_path.insert(shortest_path.begin(), (*it).shortest_way);
			current_edge = map.get_opposite_city((*it).shortest_way,(*it).city);
		}
	}
	// No connection to the target
	if (current_edge == NULL)
	{
		qDebug() << "Dijkstra: No Connection beetween the targets";
		AbstractMap::StreetList l;
		return l;
	}
	while (current_edge != start_pointer)
	{
		for (std::vector<tuppel>::const_iterator it = green.begin(); it != green.end(); it++)
		{
			if ((*it).city == current_edge)
			{
				shortest_path.insert(shortest_path.begin(), (*it).shortest_way);
				current_edge = map.get_opposite_city((*it).shortest_way, (*it).city);
			}
		}
	}
	return shortest_path;
}

