/**
 * @file street.cpp
 * @brief This file contains the function definitions of the Street class.
 */

#include "street.h"

Street::Street(City* from, City* to)
    : city1(from), city2(to)
{
}

Street::~Street()
{
}

/*
void Street::draw(QGraphicsScene &scene) const
{
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY());
}

void Street::drawBlue(QGraphicsScene &scene) const
{
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), QPen(QBrush(QColor(255,0,0)),5));
}
*/

City* Street::getCity1() const
{
    return city1;
}

City* Street::getCity2() const
{
    return city2;
}
