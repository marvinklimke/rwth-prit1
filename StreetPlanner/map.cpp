/**
 * @file map.cpp
 * @brief This file contains the function definitions of the Map class.
 */

#include "map.h"

Map::Map()
{
}

Map::~Map()
{
    // Delte all cities
    CityList::const_iterator ic;
    for(ic = cities.begin(); ic != cities.end(); ic++)
    {
        delete (*ic);
    }

    // Delete all streets
    StreetList::const_iterator is;
    for(is = streets.begin(); is != streets.end(); is++)
    {
        delete (*is);
    }
}

void Map::addCity(City* city)
{
    cities.push_back(city);
}

bool Map::addStreet(Street *street)
{
    // First check whether both cities are in the map
    if(     std::find(cities.begin(), cities.end(), street->getCity1()) != cities.end()
         && std::find(cities.begin(), cities.end(), street->getCity2()) != cities.end())
    {
        streets.push_back(street);
        return true;
    }
    return false;
}

City* Map::find_city(const QString city_name) const
{
    // Go through the list of cities
    CityList::const_iterator ic;
    for(ic = cities.begin(); ic != cities.end(); ic++)
    {
        // Found it ?
        if( (*ic)->getName() == city_name )
        {
            return (*ic);
        }
    }
    return NULL; // not found
}

AbstractMap::StreetList Map::get_street_list(const City *city) const
{
    StreetList mystreets; // streets at provided city

    // Go through the list of streets
    StreetList::const_iterator is;
    for(is = streets.begin(); is != streets.end(); is++)
    {
        // One City of a street hits the provided city ?
        if( (*is)->getCity1() == city || (*is)->getCity2() == city )
        {
            mystreets.push_back(*is);
        }
    }

    return mystreets;
}

City* Map::get_opposite_city(const Street *street, const City *city) const
{
    City* opposite = NULL;

    if(street->getCity1() == city) // Found it on one side ?
    {
        opposite = street->getCity2();
    }
    else if(street->getCity2() == city) // Found it on the other side ?
    {
        opposite = street->getCity1();
    }

    return opposite;
}

double Map::get_length(const Street *street) const
{
    City* c1 = street->getCity1();
    City* c2 = street->getCity2();

    // calculate length by Pythagorean theorem
    double len = sqrt( pow(c1->getX() - c2->getX(), 2) + pow(c1->getY() - c2->getY(), 2) );

    if(routeByTime) // asked for travelling time ?
        return (len / street->getAvgSpeed() );
    else
        return len;
}

void Map::draw(QGraphicsScene &scene) const
{
    scene.clear();

    // Draw all streets
    StreetList::const_iterator is;
    for(is = streets.begin(); is != streets.end(); is++)
    {
        (*is)->draw(scene);
    }

    // Draw all cities
    CityList::const_iterator ic;
    for(ic = cities.begin(); ic != cities.end(); ic++)
    {
        (*ic)->draw(scene);
    }
}

AbstractMap::CityList Map::getCities() const
{
    return cities;
}

AbstractMap::StreetList Map::getStreets() const
{
    return streets;
}

void Map::setRoutingPreference(bool prefTime)
{
    routeByTime = prefTime;
}

bool Map::getRoutingPreference() const
{
    return routeByTime;
}
