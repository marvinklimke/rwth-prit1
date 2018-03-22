/**
 * @file motorway.h
 * @brief This file contains the declaration of the Motorway class.
 */

#ifndef MOTORWAY_H
#define MOTORWAY_H

#include "street.h"

/**
 * @brief This class represents a bigger Motorway on the map.
 * It is being drawn as a thicker line.
 */
class Motorway : public Street
{

public:

    /**
     * @brief Constructor for Motorway class.
     * Note a street is always bidirectional.
     * @param from First City to connect by the new Motorway.
     * @param to Second City to connect by the new Motorway.
     */
    Motorway(City* from, City* to);

    /**
     * @brief Default destructor.
     */
    virtual ~Motorway();

    /**
     * @brief This function draws the street on the application window.
     * @param scene The QGraphicsScene to draw on.
     */
    virtual void draw(QGraphicsScene& scene) const;

    /**
     * @brief This function draws the street in blue on the application window.
     * @param scene The QGraphicsScene to draw on.
     */
    virtual void drawBlue(QGraphicsScene& scene) const;

    /**
     * @brief Getter for the average Speed on this street.
     * @return AVG_SPEED.
     */
    virtual int getAvgSpeed() const;

private:

    /**
     * @brief The thickness of the line being drawn on the application window.
     */
    const int LINE_THICKNESS = 4;

    /**
     * @brief The average speed to drive on this street. In km/h.
     */
    const int AVG_SPEED = 130;

};

#endif // MOTORWAY_H
