/**
  * @file city.h
  * @brief This file contains the declaration of the City class.
  */

#ifndef CITY_H
#define CITY_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

/**
 * @brief This class represents a city on the map.
 * The city has a name and a position as x- and y-coordinates.
 */
class City
{

protected:

    /**
     * @brief The name of the city.
     */
    QString name;

    /**
     * @brief The x-coordinate of the position of the city.
     */
    int x;

    /**
     * @brief The y-coordinate of the position of the city.
     */
    int y;

    /**
     * @brief The QColor of the dot being drawn in the application window.
     */
    const QColor COLOR = QColor(255, 0, 0);

public:

    /**
     * @brief Constructor for City class.
     * @param name The name of the new City.
     * @param x The x-coordinate of the new City.
     * @param y The y-coordinate of the new City.
     */
    City(QString name, int x, int y);

    /**
      * @brief Default Destructor
      */
    virtual ~City();

    /**
     * @brief This functions draws the City on the application window.
     * It draws the dot and the name of the City.
     * @param scene The QGraphicsScene to draw on.
     */
    virtual void draw(QGraphicsScene &scene) const = 0;

    /**
     * @brief Getter for the Name of the City.
     * @return Name of the City.
     */
    QString getName() const;

    /**
     * @brief Getter for the x-coordinate of the City.
     * @return x-coordinate of the City.
     */
    int getX() const;

    /**
     * @brief Getter for the y-coordinate of the City.
     * @return y-coordinate of the City.
     */
    int getY() const;

};

#endif // CITY_H
