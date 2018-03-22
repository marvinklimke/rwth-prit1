/**
  * @file city.cpp
  * @brief This file contains the function definitions of the City class.
  */

#include "city.h"

City::City(QString name, int x, int y)
    : name(name), x(x), y(y)
{
}

City::~City()
{
}

/*
void City::draw(QGraphicsScene &scene) const
{
    // Draw the dot
    scene.addEllipse(x - DOT_RADIUS, y - DOT_RADIUS, 2 * DOT_RADIUS, 2 * DOT_RADIUS, QPen(COLOR), QBrush(COLOR));

    // Draw the name
    QGraphicsTextItem * txtitem = new QGraphicsTextItem();
    txtitem->setPlainText(name);
    txtitem->setPos(x + DOT_RADIUS / 2, y + DOT_RADIUS / 2);
    scene.addItem(txtitem);

    qDebug() << QString("City %1 being drawn at X %2 | Y %3").arg(name).arg(x).arg(y);
}
*/

QString City::getName() const
{
    return name;
}

int City::getX() const
{
    return x;
}

int City::getY() const
{
    return y;
}
