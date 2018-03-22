/**
 * @file bigtown.h
 * @brief This file contains the class declaration of the BigTown class.
 */

#ifndef BIGTOWN_H
#define BIGTOWN_H

#include "city.h"

/**
 * @brief This class represents a big city on the map.
 * It is being drawn as a bigger dot.
 */
class BigTown : public City
{

public:

    /**
     * @brief Constructor for BigTown class.
     * @param name Name of the new BigTown.
     * @param x x-coordinate of the new BigTown.
     * @param y y-coordinate of the new BigTown.
     */
    BigTown(QString name, int x, int y);

    /**
     * @brief Default destructor.
     */
    virtual ~BigTown();

    /**
     * @brief This function draws the BigTown on the given QGraphicsScene.
     * It draws a bigger dot.
     * @param scene QGraphicsScene to draw on.
     */
    virtual void draw(QGraphicsScene& scene) const;

private:

    /**
     * @brief The radius of the dot being drawn in the application window.
     */
    const int DOT_RADIUS = 6;

};

#endif // BIGTOWN_H
