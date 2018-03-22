/**
 * @file stateroad.cpp
 * @brief This file contains the function definitions of the StateRoad class.
 */

#include "stateroad.h"

StateRoad::StateRoad(City* from, City* to) : Street(from, to)
{
}

StateRoad::~StateRoad()
{
}

void StateRoad::draw(QGraphicsScene &scene) const
{
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), QPen(QBrush(QColor(0,0,0)), LINE_THICKNESS));
}

void StateRoad::drawBlue(QGraphicsScene &scene) const
{
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), QPen(QBrush(QColor(0,0,255)), LINE_THICKNESS));
}

int StateRoad::getAvgSpeed() const
{
    return AVG_SPEED;
}
