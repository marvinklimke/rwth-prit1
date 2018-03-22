/**
 * @file abstractmap.h
 * @brief This file contains the declaration of the AbstractMap class.
 */

#ifndef ABSTRACTMAP
#define ABSTRACTMAP

#include "city.h"
#include "street.h"

/**
 * @brief This class provides the prototypes for the Map class.
 */
class AbstractMap
{
public:

    /// STL vector of city pointers
	typedef std::vector<City *> CityList;

    /// STL vector of street pointers
    typedef std::vector<Street *> StreetList;

    /**
     * @brief Adds the provided city to this map.
     * @param city pointer to the city that should be added to the map
     */
    virtual void addCity(City* city) = 0;

    /**
     * @brief Adds the provided street to this map.
     * If the cities linked by the street have not been added to this map before, the street is not added.
     * @param street pointer to the street that should be added to the map
     * @return true if the street has beed added.
	 */
    virtual bool addStreet(Street* street) = 0;

	/**
	 * @brief Search for a city in this map by given name.
     * @param city_name The name of the city to look for
	 * @return the city pointer, if city not found NULL
	 */
    virtual City* find_city(const QString city_name) const = 0;

	/**
	 * @brief Search for streets in this map.
	 * @param city where you want the street_list from
	 * @return a list of all streets in this map connected to provided city.
	 */
    virtual StreetList get_street_list(const City* city) const = 0;

	/**
	 * @brief Look for opposite city.
	 * @param street
	 * @param city
	 * @return opposite city of the street. If city has no connection to street returns NULL.
	 */
    virtual City* get_opposite_city(const Street* street, const City* city) const = 0;

	/**
	 * @brief Calculate the street length.
	 * @param street
	 * @return length of the street
	 */
    virtual double get_length(const Street* street) const = 0;

};

#endif // ABSTRACTMAP

