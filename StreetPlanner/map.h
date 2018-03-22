/**
 * @file map.h
 * @brief This file contains the class declaration of the Map class.
 */

#ifndef MAP_H
#define MAP_H

#include <algorithm>
#include <vector>
#include <QDebug>
#include <QGraphicsScene>

#include "abstractmap.h"
#include "city.h"
#include "street.h"

/**
 * @brief This class represents the map of cities and streets.
 * It holds a list of all cities and streets.
 */
class Map : public AbstractMap
{

private:

    /**
     * @brief The list of all cities on the map.
     */
    CityList cities;

    /**
     * @brief The list of all streets on the map.
     */
    StreetList streets;

    /**
     * @brief Routing preference.
     * true  = By Travelling time.
     * false = By Distance.
     */
    bool routeByTime = false;

public:

    /**
     * @brief Constructor for Map class.
     */
    Map();

    /**
     * @brief Default destructor.
     */
    ~Map();

    /**
     * @brief This function adds a City to the map.
     * @param city the city to be added.
     */
    virtual void addCity(City* city);

    /**
     * @brief This function adds a Street to the map.
     * The connected cities must be added to map first.
     * @param street The street to be added.
     * @return true if the street was added successful, false otherwise.
     */
    virtual bool addStreet(Street* street);

    /**
     * @brief Search for a city in this map by given name.
     * @param city_name The name of the city to look for
     * @return the city pointer, if city not found NULL
     */
    virtual City* find_city(const QString city_name) const;

    /**
     * @brief Search for streets in this map.
     * @param city where you want the street_list from
     * @return a list of all streets in this map connected to provided city.
     */
    virtual StreetList get_street_list(const City *city) const;

    /**
     * @brief Look for opposite city.
     * @param street
     * @param city
     * @return opposite city of the street. If city has no connection to street returns NULL.
     */
    virtual City* get_opposite_city(const Street *street, const City *city) const;

    /**
     * @brief Calculate the street length.
     * @param street
     * @return length of the street
     */
    virtual double get_length(const Street *street) const;

    /**
     * @brief This function draws the map (cities & streets) on the provided GraphicsScene.
     * @param scene The QGraphicsScene to draw on.
     */
    void draw(QGraphicsScene &scene) const;

    /**
     * @brief Getter for list of all cities on the map.
     * @return List of cities.
     */
    CityList getCities() const;

    /**
     * @brief Getter for list of all streets on the map.
     * @return List of streets.
     */
    StreetList getStreets() const;

    /**
     * @brief Setter for Routing preference.
     * @param prefTime true for time based routing, false for distance based routing.
     */
    void setRoutingPreference(bool prefTime);

    /**
     * @brief Getter for Routing Preference.
     * @return true for time based routing, false for distance based routing.
     */
    bool getRoutingPreference() const;

};

#endif // MAP_H
