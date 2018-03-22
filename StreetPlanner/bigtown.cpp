/**
 * @file bigtown.cpp
 * @brief This file contains the function definitions of the BigTown class.
 */

#include "bigtown.h"

BigTown::BigTown(QString name, int x, int y) : City(name, x, y)
{
}

BigTown::~BigTown()
{
}

void BigTown::draw(QGraphicsScene &scene) const
{
    // Draw the dot
    scene.addEllipse(x - DOT_RADIUS, y - DOT_RADIUS, 2 * DOT_RADIUS, 2 * DOT_RADIUS, QPen(COLOR), QBrush(COLOR));

    // Draw the name
    QGraphicsTextItem * txtitem = new QGraphicsTextItem();
    txtitem->setPlainText(name);
    txtitem->setPos(x + DOT_RADIUS / 2, y + DOT_RADIUS / 2);
    scene.addItem(txtitem);
}
