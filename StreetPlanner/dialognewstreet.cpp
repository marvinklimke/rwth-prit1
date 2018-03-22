/**
 * @file dialognewstreet.cpp
 * @brief This file contains the function definitions of the DialogNewStreet class.
 */

#include "dialognewstreet.h"
#include "ui_dialognewstreet.h"

/**
 * @brief Constructor for DialogNewStreet class.
 * @param parent
 */
DialogNewStreet::DialogNewStreet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewStreet)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor for DialogNewStreet class.
 * Deletes the ui instance.
 */
DialogNewStreet::~DialogNewStreet()
{
    delete ui;
}

/**
 * @brief This function sets the list of cities availible to the user to create the street.
 * @param clist List of cities on the map.
 */
void DialogNewStreet::setCities(AbstractMap::CityList clist)
{
    cities = clist;

    AbstractMap::CityList::const_iterator ic;
    for(ic = clist.begin(); ic != clist.end(); ic++)
    {
        ui->cbCity1->addItem((*ic)->getName());
        ui->cbCity2->addItem((*ic)->getName());
    }
}

/**
 * @brief This function provides access to the new Street
 * It parses the data entered by the user and creates a new Street object.
 * @return pointer on the new Street object.
 */
Street* DialogNewStreet::getNewStreet() const
{
    City* city1 = cities[ui->cbCity1->currentIndex()];
    City* city2 = cities[ui->cbCity2->currentIndex()];

    if(ui->rbStateRoad->isChecked())
        return new StateRoad(city1, city2);
    else if(ui->rbMotorway->isChecked())
        return new Motorway(city1, city2);
    else
        return NULL;
}
