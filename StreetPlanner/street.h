/**
 * @file street.h
 * @brief This file contains the class declaration of the Street class.
 */

#ifndef STREET_H
#define STREET_H

#include <QGraphicsScene>

#include "city.h"

/**
 * @brief This class represents a street between two cities.
 * It holds two cities to be connected by the street.
 */
class Street
{

protected:

    /**
     * @brief The first city to connect.
     */
    City* city1;

    /**
     * @brief The second city to connect.
     */
    City* city2;

public:

    /**
     * @brief Constructor for Street class.
     * Note a street is always bidirectional.
     * @param from first city to connect by the new street.
     * @param to second city to connect by the new street.
     */
    Street(City* from, City* to);

    /**
     * @brief Default Destructor.
     */
    virtual ~Street();

    /**
     * @brief This function draws the street on the application window.
     * @param scene The QGraphicsScene to draw on.
     */
    virtual void draw(QGraphicsScene &scene) const = 0;

    /**
     * @brief This function draws the street in blue on the application window.
     * @param scene The QGraphicsScene to draw on.
     */
    virtual void drawBlue(QGraphicsScene &scene) const = 0;

    /**
     * @brief Getter for member city1
     * @return The first city connected by the street.
     */
    City* getCity1() const;

    /**
     * @brief Getter for member city2
     * @return The second city connected by the street.
     */
    City* getCity2() const;

    /**
     * @brief Getter for the average Speed on this street.
     * @return AVG_SPEED.
     */
    virtual int getAvgSpeed() const = 0;

};

#endif // STREET_H
