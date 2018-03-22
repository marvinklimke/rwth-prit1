/**
 * @file smalltown.h
 * @brief This file contains the class declaration of the SmallTown class.
 */

#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include "city.h"

/**
 * @brief This class represents a small city on the map.
 * It is being drawn as a smaller dot.
 */
class SmallTown : public City
{

public:

    /**
     * @brief Constructor for SmallTown class.
     * @param name Name of the new SmallTown.
     * @param x x-coordinate of the new SmallTown.
     * @param y y-coordinate of the new SmallTown.
     */
    SmallTown(QString name, int x, int y);

    /**
     * @brief Default destructor.
     */
    virtual ~SmallTown();

    /**
     * @brief This function draws the SmallTown on the given QGraphicsScene.
     * It draws a smaller dot.
     * @param scene QGraphicsScene to draw on.
     */
    virtual void draw(QGraphicsScene& scene) const;

private:

    /**
     * @brief The radius of the dot being drawn in the application window.
     */
    const int DOT_RADIUS = 3;

};

#endif // SMALLTOWN_H
