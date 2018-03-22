/**
 * @file motorway.cpp
 * @brief This file contains the function definitions of the Motorway class.
 */

#include "motorway.h"

Motorway::Motorway(City* from, City* to) : Street(from, to)
{
}

Motorway::~Motorway()
{
}

void Motorway::draw(QGraphicsScene &scene) const
{
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), QPen(QBrush(QColor(0,0,0)), LINE_THICKNESS));
}

void Motorway::drawBlue(QGraphicsScene &scene) const
{
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), QPen(QBrush(QColor(0,0,255)), LINE_THICKNESS));
}

int Motorway::getAvgSpeed() const
{
    return AVG_SPEED;
}
